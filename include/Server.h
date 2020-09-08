#pragma once

#include "boost/asio.hpp"
#include <Client.h>
#include <Config.h>
#include <memory>
#include <set>
#include "Types.h"

class Server
{
public:
    explicit Server(std::shared_ptr<Config> conf) noexcept;
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;

    void start();

private:
    void connectAcceptor();
    void acceptConnection(const boost::system::error_code &error);

    io_service m_ioService;
    tcp::acceptor m_acceptor;
    std::shared_ptr<Config> m_conf;
    std::shared_ptr<Client> m_newClient;
//    std::mutex m_threadMutex;
    int64_t m_threadsActive;
};

