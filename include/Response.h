#pragma once

#include "Header.h"
#include <vector>

// TODO переписать !!!
class Response {
public:
    static std::string
    startProcessing(const std::string &method, const std::string document_root, std::string &uri, char version);

private:
    static std::string processMethod(const std::string &method, const std::string &document_root, std::string &uri,
                                     std::vector<Header> &headers);

    static std::string processUnknownMethod();

    static void initHeaders(std::vector<Header> &headers);

    static void writeHeaders(const std::string &method, const std::string &code, const std::string &path,
                             std::string &response_buffer,
                             const std::vector<Header> &headers);

    static std::string getDate();

    static std::string getContentType(const std::string &extension);
};