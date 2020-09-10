#include <filesystem>
#include <fstream>
#include "ResponseProcessor.h"

#define MAX_FILE_BUFFER_SIZE 1024

std::string ResponseProcessor::startProcessing(const std::string& method, std::string url, char version)
{
    std::string response = "HTTP/1.";
    std::string headers;
    response.push_back(version);
    response.push_back(' ');

    headers.append("Server: nginx\r\n");
    headers.append("Date: ");
    headers.append(processDate());
    headers.append("\r\n");
    headers.append("Connection: Closed\r\n");
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

    response.append(std::move(headers));
    processHeaders(method, responseCode, url, response);

    return std::move(response);
}

int ResponseProcessor::processMethod(const std::string& method, std::string& url, std::string& headers)
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

        headers.append("Content-Type: ");
        headers.append(content_type);
        headers.append("\r\n");
        headers.append("Content-Length: ");
        headers.append(std::to_string(std::filesystem::file_size(url)));
        headers.append("\r\n");

        return 200;
    } else if (notOutOfRoot && indexFile)
    {
        return 403;
    }

    return 404;
}

void ResponseProcessor::processHeaders(const std::string& method, const int code, const std::string& path,
                                     std::string& responseBuffer)
{
    if (method == "HEAD") {
        responseBuffer.append("\r\n");
    } else if (method == "GET" && code == 200) {
        responseBuffer.append("\r\n");

        // TODO mutex was here
        std::ifstream file(path.c_str(), std::ios::in | std::ios::binary);
        char fileBuffer[MAX_FILE_BUFFER_SIZE];

        while (file.read(fileBuffer, sizeof(fileBuffer)).gcount() > 0) {
            responseBuffer.append(fileBuffer, file.gcount());
        }
    }
}

std::string ResponseProcessor::processDate()
{
    std::time_t timer = std::time(nullptr);
    char bufferTime[256];
    auto timeNow = std::strftime(bufferTime, sizeof(bufferTime), "%a, %d %b %Y %H:%M:%S GMT",
                                 std::localtime(&timer));

    return std::string(bufferTime, timeNow);
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