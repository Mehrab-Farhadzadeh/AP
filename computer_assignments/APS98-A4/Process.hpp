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
    bool is_done();
    std::vector<Thread> get_threads();
    int get_id();

private:
    int id;
    std::vector<Thread> threads;
};

#endif