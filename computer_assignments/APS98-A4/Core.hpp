#ifndef CORE_HPP
#define CORE_HPP

#include <vector>
#include "Thread.hpp"
#include "Process.hpp"

class Core
{
public:
    Core(int _id);
    void add_a_thread(Thread thread);
    void run(std::vector<Process> &processes);
    void show_stat();
    void show_stat_in_run();
    int get_id();
    int get_size_of_queue();

private:
    int id;
    std::vector<Thread> queue;
};

#endif