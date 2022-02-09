#ifndef ROUNDROBINSCHEDULER_HPP
#define ROUNDROBINSCHEDULER_HPP

#include <vector>
#include "MulticoreProcessor.hpp"
#include "Process.hpp"

class RoundRobinScheduler
{
public:
    RoundRobinScheduler(int _id_of_last_process = 0);
    void add_a_process(Process process);
    void finsih_tasks();

private:
    MultiProcessor multi_processor;
    std::vector<Process> processes;
    static int id_of_last_process;
};

#endif