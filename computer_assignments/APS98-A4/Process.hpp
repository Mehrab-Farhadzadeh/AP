#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <vector>
#include "Thread.hpp"

class Process
{
public:
    Process(int _id, std::vector<Thread> _threads);
    void run_cores();

private:
    int id;
    std::vector<Thread> threads;
};

#endif