#pragma once

#include "boost/asio.hpp"
#include <Config.h>
#include <Client.h>
#include <memory>
#include <set>
#include "Types.h"

class Server
{
public:
    explicit Server(std::shared_ptr<Config> conf);// noexcept;
    void start();

private:
    void connectAcceptor();
    void acceptConnection(const boost::system::error_code &error);

    std::atomic_int64_t m_threadsActive;
    io_service m_ioService;
    tcp::acceptor m_acceptor;
    std::shared_ptr<Config> m_conf;
    std::shared_ptr<Client> m_newClient;
    std::shared_ptr<Client> m_oldClient;
};

