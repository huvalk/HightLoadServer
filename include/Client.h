#pragma once

#include <boost/asio/io_service.hpp>
#include <boost/array.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>
#include "Config.h"
#include "Types.h"

class Client {
public:
    explicit Client(std::string confPath) noexcept;
    void run(int64_t& m_threadsActive);

    io_service m_ioService;
    tcp::socket m_socket;
private:
    boost::array<char, 1024> m_buffer;
    std::string m_response;
    std::string m_rootPath;
};