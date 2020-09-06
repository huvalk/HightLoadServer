#include <boost/asio/signal_set.hpp>
#include <iostream>
#include "Server.h"
#include "ThreadRoutine.h"

Server::Server(std::shared_ptr<Config> conf) //noexcept
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
    m_oldClient = m_newClient;
    m_newClient.reset(new Client(m_ioService, m_conf));
    m_acceptor.async_accept(
            m_newClient->m_socket,
            std::bind(&Server::acceptConnection, this, std::placeholders::_1)
    );
}

void Server::acceptConnection(const boost::system::error_code &error)
{
    if (!error) {
        std::thread (ThreadRoutine, m_newClient, std::ref(m_threadsActive)).detach();

        std::cout << "no error " << std::endl << std::flush;
    } else {
        std::cerr << "Accept error: " << error.message() << std::endl;
    }

    connectAcceptor();
}