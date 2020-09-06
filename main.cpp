#include "ConfigParser.h"
#include <iostream>
#include "Server.h"

int main()
{
    auto result = ConfigParser::parse("/etc/httpd.conf");
    if (!result.first)
    {
        std::cout << "Invalid config";
        return 1;
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