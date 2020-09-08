#include <iostream>
#include <boost/asio.hpp>
#include "boost/regex.hpp"
#include "Client.h"
#include "Request.h"
#include "Response.h"


Client::Client(io_service& ioService, std::string confPath) noexcept
    : m_socket(ioService),
    m_rootPath(confPath),
    m_buffer()
{

}

void Client::run() {
//    waitForSocketAsync();
    std::string message_ = "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n"
                           "<html><head><title>test</title>"
                           "</head><body><h1>Test</h1><p>This is a test!</p></body></html>";

    try {
        boost::asio::read_until(m_socket, buf, boost::regex("\r\n\r\n"));
        // write answer to socket
        std::string method, uri;
        char version;
        std::vector<Header> headers;

        if (Request::parseRequest(boost::asio::buffer_cast<const char*>(buf.data()), method, uri, version, headers)) {
            m_response = Response::startProcessing(method, m_rootPath, uri, version);
            boost::asio::write(m_socket,boost::asio::buffer(m_response),boost::asio::transfer_all());

            m_socket.close();
        }

        // close socket
        m_socket.close();
    } catch(std::exception& x) {
//		std::cerr << "Exception: " << x.what() << std::endl;
    }
}

void Client::waitForSocketAsync()
{
    m_socket.async_read_some(
            boost::asio::buffer(m_buffer),
            std::bind(&Client::readSocket, this,
                    std::placeholders::_1,
                    std::placeholders::_2));
}

// TODO переписать!!!

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
            std::cout << this << std::endl << std::flush;
            m_response = "awd";
            m_response = Response::startProcessing(method, m_rootPath, uri, version);
            writeSocket();
            m_socket.close();
        } else {
            return;
        }
    }

}

void Client::writeSocket()
{
    boost::asio::async_write(
            m_socket,
            boost::asio::buffer(m_response),
            [this](const boost::system::error_code &error, size_t bytes_transferred) {
                if (error) {
                    std::cout << error.message() << " || " << error.value() << " || " << std::endl;
                }
            }
    );
}