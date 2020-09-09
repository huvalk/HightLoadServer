#include <cstring>
#include "RequestProcessor.h"
#include <sstream>

bool RequestProcessor::parseRequest(char* const request, std::string &method, std::string &uri, char &version,
                                    std::vector<Header> &headers)
{
    size_t state = 0;
    char* previousPos = request;
    char* curPos = request;
    std::string tempKeyString;
    std::string tempValueString;

    while(*curPos != '\0')
    {
        switch (state)
        {
            // Метод
            case 0:
            {
                if ( std::isalpha(*curPos) )
                {
                    curPos++;
                } else if (*curPos == ' ')
                {
                    method.append(previousPos, curPos - previousPos);
                    curPos = previousPos = skipSpaces(curPos);
                    state = 1;
                } else
                {
                    return false;
                }
                break;
            }

                // URL
            case 1:
            {
                if ( isUrlSymbol(*curPos) )
                {
                    curPos++;
                } else if (*curPos == '%') {
                    uri.append(previousPos, curPos - previousPos);
                    char temp[3];
                    memcpy(temp, curPos + 1, 2);

                    std::stringstream ss;
                    ss << std::hex << temp;
                    int character = 0;
                    ss >> character;
                    uri.push_back(static_cast<char>(character));

                    previousPos = curPos += 3;
                } else if (*curPos == '+')
                {
                    uri.push_back(' ');
                } else if (*curPos == ' ')
                {
                    uri.append(previousPos, curPos - previousPos);
                    curPos = previousPos = skipSpaces(curPos);
                    state = 2;
                } else
                {
                    return false;
                }
                break;
            }

                // http (проигнорирован)
            case 2:
                // TODO проверить, всегда ли есть точка
            {
                // TODO нет проверки на ноль
                while (*curPos != '.')
                {
                    curPos++;
                }
                curPos++;

                if (std::isdigit(*curPos))
                {
                    version = *curPos;
                    curPos = previousPos = skipSpaces(++curPos);
                    state = 3;
                } else
                {
                    return  false;
                }
                break;
            }
                // \r\n
            case 3:
            {
                // TODO проверить, всегда ли есть точка
                if (*curPos == '\r' && *(curPos + 1) == '\n')
                {
                    previousPos = curPos += 2;
                    state = 4;
                } else
                {
                    return false;
                }
                break;
            }

            //header key
            case 4:
            {
                if (method == "HEAD" && *curPos == '\r' && *(curPos + 1) == '\n')
                {
                    return true;
                }

                if (std::isalnum(*curPos) || *curPos == '-')
                {
                    curPos++;
                } else if (*curPos == ':')
                {
                    tempKeyString.append(previousPos, curPos - previousPos);
                    curPos = previousPos = skipSpaces(++curPos);
                    state = 5;
                } else
                {
                    return false;
                }
                break;
            }

            // header value
            case 5:
            {
                if (*curPos == '\r' && *(curPos + 1) == '\n')
                {
                    tempValueString.append(previousPos, curPos - previousPos);
                    headers.emplace_back(Header{std::move(tempKeyString), std::move(tempValueString)});
                    tempKeyString.clear();
                    tempValueString.clear();
                    previousPos = curPos += 2;
                    state = 6;
                } else
                {
                    curPos++;
                }
                break;
            }

            // terminal
            case 6:
            {
                if (*curPos != '\r')
                {
                    state = 5;
                } else if (*curPos == '\r' && *(curPos + 1) == '\n')
                {
                    // previousPos =
                    curPos += 2;
                    state = 7;
                } else
                {
                    return false;
                }
                break;
            }

            default:
            {
                return false;
            }
        }
    }


    return state == 7;
}

bool RequestProcessor::isUrlSymbol(char ch)
{
    return (std::isalnum(ch) ||
            ch == '.' || ch == '/' || ch == '?' || ch == '&' || ch == '=' || ch == '_' || ch == '-');
}

char* RequestProcessor::skipSpaces(char* ch)
{
    while (*ch == ' ')
    {
        ch++;
    }
    return ch;
}
