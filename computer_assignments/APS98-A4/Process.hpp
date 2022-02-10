#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <vector>
#include "Thread.hpp"

class Process
{
public:
    Process(int _id);
    void add_a_thread(Thread thread);
    void run(int tid);
    std::vector<Thread> get_queue_of_threads();

private:
    int id;
    std::vector<Thread> threads;
};

#endif