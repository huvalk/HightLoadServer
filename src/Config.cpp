#include "Config.h"

Config::Config(const std::string& root, const uint16_t cpuLimit,
        const uint16_t port, const uint64_t threadLimit) noexcept
    : m_root(root),
    m_threadLimit(threadLimit),
    m_cpuLimit(cpuLimit),
    m_port(port)
{
}

std::string Config::getRoot() const
{
    return m_root;
}

uint64_t Config::getThreadLimit() const
{
    return m_threadLimit;
}

uint16_t Config::getPort() const
{
    return m_port;
}

uint16_t Config::getCpuLimit() const
{
    return m_cpuLimit;
}

void Config::setPort(const uint16_t port) {
    m_port = port;
}
