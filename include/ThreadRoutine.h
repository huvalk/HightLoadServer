#pragma once

#include "Client.h"

//class ThreadRoutine {
//    static void operator() (std::shared_ptr<Client>);
//};

void ThreadRoutine(std::shared_ptr<Client> client, std::atomic_int64_t& thread_count);