#pragma once

#include "boost/asio.hpp"
#include <Client.h>
#include <Config.h>
#include <list>
#include <memory>
#include <mutex>
#include <set>
#include <shared_mutex>
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
    tcp::endpoint m_endPoint;
    tcp::acceptor m_acceptor;
    Cache m_cache;
    std::shared_ptr<Config> m_conf;
    std::shared_ptr<Client> m_newClient;
    std::mutex m_threadMutex;
    std::shared_mutex m_cacheMutex;
    int64_t m_threadsActive;
};

