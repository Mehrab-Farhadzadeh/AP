#ifndef CORE_HPP
#define CORE_HPP

#include <vector>
#include "Thread.hpp"

class Core
{
public:
    Core(int _id);
    void add_a_thread(Thread thread);
    void run();
    void show_stat();

private:
    int id;
    std::vector<Thread> queue;
};

#endif