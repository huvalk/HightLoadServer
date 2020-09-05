#pragma once

#include "Config.h"
#include <string>
#include <memory>

class ConfigParser
{
public:
    explicit ConfigParser() noexcept;

    static std::pair<bool, std::shared_ptr<Config>> parse(const std::string& path);
};
