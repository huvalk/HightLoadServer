#pragma once

#include <boost/asio/io_service.hpp>
#include <boost/array.hpp>
#include <boost/asio/ip/tcp.hpp>
#include "Config.h"
#include "Types.h"

class Client {
public:
    explicit Client(io_service& ioService, std::shared_ptr<Config> conf) noexcept;
    void waitForSocketAsync();

    tcp::socket m_socket;
private:
    void readSocket(const error_code& error, size_t bytes_transferred);
    void writeSocket();

    boost::array<char, 1024> m_buffer;
    std::string m_response;
    std::shared_ptr<Config> m_config;
};