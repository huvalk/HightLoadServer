#pragma once

#include <string>

class Config
{
public:
    explicit Config(const std::string& root, const uint16_t cpuLimit,
                    const uint16_t port, const uint64_t threadLimit) noexcept;

    std::string getRoot() const;
    uint64_t getThreadLimit() const;
    uint16_t getPort() const;
    uint16_t getCpuLimit() const;

private:
    const std::string m_root;
    const uint64_t m_threadLimit;
    const uint16_t m_cpuLimit;
    const uint16_t m_port;
};
