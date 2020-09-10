#include <boost/asio.hpp>
#include "Client.h"
#include <iostream>
#include <mutex>
#include "ResponseProcessor.h"
#include "RequestProcessor.h"


Client::Client(io_service& ioService, std::string confPath, int64_t& threadsActive) noexcept
    : m_ioService(ioService),
    m_threadsActive(threadsActive),
    m_socket(m_ioService),
    m_rootPath(std::move(confPath)),
    m_buffer()
{

}

void Client::run(int64_t& m_threadsActive, std::mutex& threadMutex,
                 Cache& cache, std::shared_mutex& cacheMutex)
{
    size_t readSize = 0;
    try
    {
        readSize = m_socket.read_some(boost::asio::buffer(m_buffer));

        auto response = getCache(cache, cacheMutex, m_buffer);
        if (response.size() > 0)
        {
            boost::asio::write(m_socket, boost::asio::buffer(response), boost::asio::transfer_all());
        } else if (RequestProcessor::parseRequest(m_buffer.elems, m_method, m_uri, m_version, m_headers))
        {
            response = ResponseProcessor::startProcessing(m_method, m_rootPath + m_uri, m_version);
            addCache(cache, cacheMutex, m_buffer, response);

            boost::asio::write(m_socket, boost::asio::buffer(response), boost::asio::transfer_all());
        }

        m_socket.close();
    } catch(std::exception& x)
    {
        if (readSize == 0)
        {
//            std::cout << "Client exception: " << x.what() << std::endl << std::flush;
        } else
        {
            std::cerr << "Client exception: " << x.what() << std::endl << std::flush;
        }
    }

    threadMutex.lock();
    m_threadsActive -= 1;
    threadMutex.unlock();
}

void Client::addCache(Cache& cache, std::shared_mutex& cacheMutex,
                      const boost::array<char, 1024>& key, const std::string& response)
{
    cacheMutex.lock();
    cache.emplace_front(std::make_pair(std::move(key), m_response));
    if (cache.size() > 10)
    {
        cache.pop_back();
    }
    cacheMutex.unlock();
}

std::string Client::getCache(Cache& cache, std::shared_mutex& cacheMutex,
                             const boost::array<char, 1024>& key) const
{
    cacheMutex.lock_shared();
    size_t size = 0;
    for(const auto& elem : cache)
    {
        size++;
        if (elem.first == key)
        {
            cacheMutex.unlock_shared();
            return elem.second;
        }
    }
    cacheMutex.unlock_shared();
    return "";
}
