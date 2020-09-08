#pragma once

#include <boost/asio/io_service.hpp>
#include <boost/array.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>
#include "Config.h"
#include "Types.h"

class Client: public std::enable_shared_from_this<Client>
{
public:
    explicit Client(io_service& ioService, std::string confPath, int64_t& threadsActive) noexcept;
    void run(int64_t& m_threadsActive);
    void waitForSocketAsync();

    tcp::socket m_socket;
private:
    void readSocket(const error_code& error, size_t bytes_transferred);
    void writeSocket(const boost::system::error_code &error, size_t bytes_transferred);

    io_service& m_ioService;
    boost::array<char, 1024> m_buffer;
    std::string m_response;
    std::string m_rootPath;
    int64_t& m_threadsActive;
};