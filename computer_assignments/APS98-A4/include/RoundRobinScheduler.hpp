#ifndef ROUNDROBINSCHEDULER_HPP
#define ROUNDROBINSCHEDULER_HPP

#include <vector>
#include "MulticoreProcessor.hpp"
#include "Process.hpp"

class RoundRobinScheduler
{
public:
    RoundRobinScheduler(int _id_of_last_process = 0);
    void add_a_process();
    void add_a_core();
    void show_cores_stat();
    void run_cores();
    void finsih_tasks();

private:
    MulticoreProcessor multicore_processor;
    std::vector<Process> processes;
    int id_of_last_process;
};

#endif