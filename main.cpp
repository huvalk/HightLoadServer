#include "ConfigParser.h"
#include <iostream>
#include "Server.h"

int main(int argc, char** argv)
{
    auto path = std::string("/etc/httpd.conf");
    if (argc > 1)
    {
        path = std::string(argv[1]);
    }

    auto result = ConfigParser::parse(path);
    if (!result.first)
    {
        std::cout << "Invalid config";
        return 1;
    }


    if (argc > 2)
    {
        result.second->setPort(atoi(argv[2]));
    }

    try
    {
        Server server(result.second);
        server.start();
    } catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}