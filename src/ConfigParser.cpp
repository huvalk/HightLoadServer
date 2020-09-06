#include "ConfigParser.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

std::pair<bool, std::shared_ptr<Config>> ConfigParser::parse(const std::string& path = "./httpd.conf")
{
    if (!std::filesystem::exists(path))
        return std::make_pair(false, nullptr);

    std::ifstream conf;
    conf.open(path, std::ios::in);
    if (!conf.is_open())
        return std::make_pair(false, nullptr);

    uint64_t threadLimit = 0;
    uint16_t cpuLimit = 0;
    std::string root = "";
    for (std::string curLine; std::getline(conf, curLine);)
    {
        std::stringstream curLineStream;
        curLineStream << curLine;
        std::string buf;
        curLineStream >> buf;

        if (buf == "cpu_limit")
        {
            curLineStream >> buf;
            cpuLimit = std::stoi(buf);
        } else if (buf == "thread_limit")
        {
            curLineStream >> buf;
            threadLimit = std::stoi(buf);
        } else if (buf == "document_root")
        {
            curLineStream >> buf;
            root = std::move(buf);
        } else {
            return std::make_pair(false, nullptr);
        }
    }

    conf.close();
    return std::make_pair(true, std::make_shared<Config>(root, cpuLimit, 80, threadLimit));
}