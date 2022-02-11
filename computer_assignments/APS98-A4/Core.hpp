#ifndef CORE_HPP
#define CORE_HPP

#include <vector>
#include "Thread.hpp"
#include "Process.hpp"

void show_stat_in_run(Thread thread, int core_id);

class Core
{
public:
    Core(int _id);
    void add_a_thread(Thread thread);
    void run(std::vector<Process> &processes);
    void show_stat();
    int get_id();
    int get_size_of_queue();

private:
    int id;
    std::vector<Thread> queue;
};

#endif