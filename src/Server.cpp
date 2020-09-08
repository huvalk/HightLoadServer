#include <boost/asio/signal_set.hpp>
#include <iostream>
#include "Server.h"
#include <thread>

Server::Server(std::shared_ptr<Config> conf) noexcept
    : m_threadsActive(0),
    m_conf(conf),
    m_acceptor(m_ioService,
            tcp::endpoint(
                tcp::v4(),
                conf->getPort())
    )
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
    std::cout << "?" << m_threadsActive << std::endl << std::flush;
    m_acceptor.async_accept(
            m_newClient->m_socket,
            std::bind(&Server::acceptConnection, this, std::placeholders::_1)
    );
}

void Server::acceptConnection(const boost::system::error_code &error)
{
    if (!error) {
        std::cout << 1 << std::flush;
//        while (m_threadsActive >= m_conf->getThreadLimit())
//        {
//            std::cout << 2 << std::flush;
//            std::cout << m_threadsActive << std::endl << std::flush;
//        }

        m_threadsActive++;
        std::thread (std::bind(&Client::waitForSocketAsync, m_newClient)).detach();

        connectAcceptor();
    } else {
        std::cerr << "Accept error: " << error.message() << std::endl;
    }

}