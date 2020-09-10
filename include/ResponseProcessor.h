#pragma once

#include "Header.h"
#include <vector>

class ResponseProcessor {
public:
    // TODO небыло ссылки
    static std::string startProcessing(const std::string& method, std::string url, char version);

private:
    static int processMethod(const std::string& method, std::string& url, std::vector<Header>& headers);
    static void processHeaders(const std::string& method, const int code, const std::string& path,
                             std::string& responseBuffer,
                             const std::vector<Header>& headers);
    static std::string processDate();
    static std::string processContentType(const std::string& extension);
};