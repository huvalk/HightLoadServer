#include <filesystem>
#include <fstream>
#include "ResponseProcessor.h"

#define MAX_FILE_BUFFER_SIZE 1024

std::string ResponseProcessor::startProcessing(const std::string& method, std::string url, char version)
{
    std::string response = "HTTP/1.";
    response.push_back(version);
    response.push_back(' ');

    std::vector<Header> headers;
    headers.push_back(Header{"Server", "nginx"});
    headers.push_back(Header{"Date", processDate()});
    headers.push_back(Header{"Connection", "Closed"});

    int responseCode = 500;

    if (method == "GET" || method == "HEAD") {
        responseCode = processMethod(method, url, headers);
    } else {
        responseCode = 405;
    }

    switch (responseCode)
    {
        case 200:
        {
            response.append("200 OK\r\n");
            break;
        }

        case 403:
        {
            response.append("403 Forbidden\r\n");
            break;
        }

        case 404:
        {
            response.append("404 Not Found\r\n");
            break;
        }

        case 405:
        {
            response.append("405 Method Not Allowed\r\n");
            break;
        }

        default:
        {
            ;
        }
    }

    processHeaders(method, responseCode, url, response, headers);

    return std::move(response);
}

int ResponseProcessor::processMethod(const std::string& method, std::string& url,
                                             std::vector<Header>& headers)
{
    bool indexFile = false;
    if (url[url.size() - 1] == '/')
    {
        indexFile = true;
        url += "index.html";
    }

    url = url.substr(0, url.find('?'));
    bool notOutOfRoot = url.find("../") == std::string::npos;

    if (std::filesystem::exists(url) && notOutOfRoot)
    {
        size_t delim = url.find_last_of('.');
        std::string content_type = processContentType(url.substr(delim + 1, url.length() - delim));

        headers.push_back(Header{"Content-Type", content_type});
        headers.push_back(Header{"Content-Length", std::to_string(std::filesystem::file_size(url))});

        return 200;
    } else if (notOutOfRoot && indexFile)
    {
        return 403;
    }

    return 404;
}

void ResponseProcessor::processHeaders(const std::string& method, const int code, const std::string& path,
                                     std::string& response_buffer, const std::vector<Header>& headers)
{
    for (const auto& header : headers)
    {
        response_buffer.append(std::move(header.key));
        response_buffer.append(": ");
        response_buffer.append(header.value);
        response_buffer.append("\r\n");
    }

    if (method == "HEAD") {
        response_buffer.append("\r\n");
    } else if (method == "GET" && code == 200) {
        response_buffer.append("\r\n");

        // TODO mutex was here
        std::ifstream file(path.c_str(), std::ios::in | std::ios::binary);
        char file_buffer[MAX_FILE_BUFFER_SIZE];

        while (file.read(file_buffer, sizeof(file_buffer)).gcount() > 0) {
            response_buffer.append(file_buffer, file.gcount());
        }
    }
}

std::string ResponseProcessor::processDate()
{
    std::time_t timer = std::time(nullptr);
    char buffer_time[256];
    auto time_now = std::strftime(buffer_time, sizeof(buffer_time), "%a, %d %b %Y %H:%M:%S GMT",
                                  std::localtime(&timer));

    return std::string(buffer_time, time_now);
}

std::string ResponseProcessor::processContentType(const std::string& extension)
{
    if (extension == "html")
    {
        return "text/html";
    } else if (extension == "css")
    {
        return "text/css";
    } else if (extension == "js")
    {
        return "application/javascript";
    } else if (extension == "jpg")
    {
        return "image/jpeg";
    } else if (extension == "jpeg")
    {
        return "image/jpeg";
    } else if (extension == "png")
    {
        return "image/png";
    } else if (extension == "gif")
    {
        return "image/gif";
    } else if (extension == "swf")
    {
        return "application/x-shockwave-flash";
    } else if (extension == "txt")
    {
        return "text/plain";
    }

    return "";
}