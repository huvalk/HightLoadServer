#pragma once

#include <boost/asio/io_service.hpp>
#include <boost/array.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>
#include "Config.h"
#include "Header.h"
#include <list>
#include <mutex>
#include <shared_mutex>
#include "Types.h"

class Client: public std::enable_shared_from_this<Client>
{
public:
    explicit Client(io_service& ioService, std::string confPath, int64_t& threadsActive) noexcept;
    void run(int64_t& m_threadsActive, std::mutex& threadMutex,
             Cache& cache, std::shared_mutex& cacheMutex);

    io_service m_ioService;
    tcp::socket m_socket;
private:
    void addCache(Cache& cache, std::shared_mutex& cacheMutex,
            const boost::array<char, 1024>& key, const std::string& response);
    std::string getCache(Cache& cache, std::shared_mutex& cacheMutex,
                         const boost::array<char, 1024>& key) const;

    std::vector<Header> m_headers;
    boost::array<char, 1024> m_buffer;
    std::string m_method;
    std::string m_uri;
    std::string m_response;
    std::string m_rootPath;
    int64_t& m_threadsActive;
    char m_version;
};