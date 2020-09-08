#pragma once

typedef std::list<std::pair<boost::array<char, 1024>, std::string>> Cache;
using boost::asio::io_service;
using boost::asio::ip::tcp;
using boost::system::error_code;