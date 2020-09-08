#pragma once

#include <boost/asio/io_service.hpp>
#include <boost/array.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>
#include "Config.h"
#include "Types.h"

class Client {
public:
    explicit Client(io_service& ioService, std::string confPath) noexcept;
    void run();
    void waitForSocketAsync();

    tcp::socket m_socket;
private:
    void readSocket(const error_code& error, size_t bytes_transferred);
    void writeSocket();

//    io_service& m_ioService;
    boost::array<char, 1024> m_buffer;
    boost::asio::streambuf buf;
    std::string m_response;
    std::string m_rootPath;
};