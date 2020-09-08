#include <boost/asio.hpp>
#include "Client.h"
#include <iostream>
#include <mutex>
#include "Response.h"
#include "Request.h"


Client::Client(io_service& ioService, std::string confPath, int64_t& threadsActive) noexcept
    : m_ioService(),
    m_threadsActive(threadsActive),
    m_socket(m_ioService),
    m_rootPath(std::move(confPath)),
    m_buffer()
{

}

void Client::waitForSocketAsync()
{
    std::cout << "+" << m_threadsActive << std::endl << std::flush;
    m_ioService.run();
    m_socket.async_read_some(
            boost::asio::buffer(m_buffer),
            std::bind(&Client::readSocket, shared_from_this(),
                      std::placeholders::_1,
                      std::placeholders::_2));
}

void Client::readSocket(const error_code& error, size_t bytes_transferred)
{
    if (error) {
        if (bytes_transferred == 0) {
            return;
        }
        std::cout << error.message() << " || " << error.value() << " || " << std::endl;
    } else {
        std::string method, uri;
        char version;
        std::vector<Header> headers;

        if (Request::parseRequest(m_buffer.elems, method, uri, version, headers)) {
            auto m_response = Response::startProcessing(method, m_rootPath, uri, version);

            m_socket.async_write_some(boost::asio::buffer(m_response),
                                      std::bind(&Client::writeSocket, shared_from_this(),
                                                std::placeholders::_1,
                                                std::placeholders::_2));

//            boost::asio::async_write(
//                    m_socket,
//                    boost::asio::buffer(m_response),
//                    std::bind(&Client::writeSocket, shared_from_this(),
//                              std::placeholders::_1,
//                              std::placeholders::_2));
        } else {
            return;
        }
    }
}

void Client::writeSocket(const boost::system::error_code &error, size_t bytes_transferred)
{
    if (error) {
        std::cout << error.message() << " || " << error.value() << " || " << std::endl;
    }

    std::cout << "-" << m_threadsActive << std::endl << std::flush;
}


void Client::run(int64_t& m_threadsActive, std::mutex& threadMutex)
{
    threadMutex.lock();
    m_threadsActive += 1;
    threadMutex.unlock();


    size_t readSize = 0;
    try {
        readSize = m_socket.read_some(boost::asio::buffer(m_buffer));

        std::string method, uri;
        char version;
        std::vector<Header> headers;

        if (Request::parseRequest(m_buffer.elems, method, uri, version, headers)) {
            auto response = Response::startProcessing(method, m_rootPath, uri, version);
            boost::asio::write(m_socket, boost::asio::buffer(response), boost::asio::transfer_all());
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

    threadMutex.lock();
    m_threadsActive -= 1;
    threadMutex.unlock();
}