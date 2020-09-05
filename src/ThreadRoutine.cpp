#include <iostream>
#include "ThreadRoutine.h"

void ThreadRoutine(std::shared_ptr<Client> client, std::atomic_int64_t& thread_count)
{
    thread_count++;
    client->waitForSocketAsync();
    std::cout << "thread";
    thread_count--;
    std::cout << thread_count << std::endl << std::flush;
}