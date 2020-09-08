#include <boost/asio.hpp>
#include "Client.h"
#include <iostream>
#include "Response.h"
#include "Request.h"


Client::Client(std::string confPath) noexcept
    : m_socket(m_ioService),
    m_rootPath(std::move(confPath)),
    m_buffer()
{
    m_ioService.run();
}

void Client::run(int64_t& m_threadsActive)
{
//    threadMutex.lock();
//    m_threadsActive += 1;
//    threadMutex.unlock();
    std::cout << "+" << m_threadsActive << std::endl << std::flush;

    sleep(5);

    size_t readSize = 0;
    try {
        readSize = m_socket.read_some(boost::asio::buffer(m_buffer));

        std::string method, uri;
        char version;
        std::vector<Header> headers;

        if (Request::parseRequest(m_buffer.elems, method, uri, version, headers)) {
            m_response = Response::startProcessing(method, m_rootPath, uri, version);
            boost::asio::write(m_socket, boost::asio::buffer(m_response), boost::asio::transfer_all());
        }

        m_socket.close();
    } catch(std::exception& x) {
        if (readSize == 0)
        {
            std::cout << "Client exception: " << x.what() << std::endl << std::flush;
        } else
        {
            std::cerr << "Client exception: " << x.what() << std::endl << std::flush;
        }
    }

    std::cout << "-" << m_threadsActive << std::endl << std::flush;

//    threadMutex.lock();
//    m_threadsActive -= 1;
//    threadMutex.unlock();
}