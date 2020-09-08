#include <boost/asio/signal_set.hpp>
#include <iostream>
#include <mutex>
#include "Server.h"
#include <thread>

Server::Server(std::shared_ptr<Config> conf) noexcept
    : m_threadsActive(0),
    m_conf(conf),
    m_endPoint(tcp::v4(), conf->getPort()),
    m_acceptor(m_ioService, m_endPoint)
{
    connectAcceptor();
}

void Server::start()
{
    m_ioService.run();
}

void Server::connectAcceptor()
{
    m_newClient.reset(new Client(m_ioService, m_conf->getRoot(), m_threadsActive));

    m_acceptor.async_accept(
            m_newClient->m_socket,
            std::bind(&Server::acceptConnection, this, std::placeholders::_1)
    );
}

void Server::acceptConnection(const boost::system::error_code &error)
{
    if (!error) {
        while (m_threadsActive >= m_conf->getThreadLimit())
        {
            std::cout << "loop" << m_threadsActive << std::endl << std::flush;
        }

        std::thread (std::bind(&Client::run, m_newClient, std::ref(m_threadsActive), std::ref(m_threadMutex),
                std::ref(m_cache), std::ref(m_cacheMutex))).detach();

        connectAcceptor();
    } else {
        std::cerr << "Accept error: " << error.message() << std::endl;
    }

}