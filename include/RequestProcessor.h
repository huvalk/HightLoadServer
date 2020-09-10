#pragma once

#include "Header.h"
#include <vector>

class RequestProcessor
{
public:
    static bool parseRequest(char* const request, std::string &method, std::string &uri, char &version,
                             std::vector<Header> &headers);

private:
    static inline char* skipSpaces(char* ch);
    static inline bool isUrlSymbol(char ch);
};