#ifndef MULTICOREPROCESSOR_HPP
#define MULTICOREPROCESSOR_HPP

#include <vector>
#include "Core.hpp"
#include "Process.hpp"

int id_of_proper_core(std::vector<Core> cores);

class MultiCoreProcessor
{
public:
    MultiCoreProcessor(int _id_of_last_core = 0);
    void add_a_core();
    void add_a_process(Process process);
    void run(std::vector<Process> &processes);
    void show_cores_stat();

private:
    int id_of_last_core;
    std::vector<Core> cores;
};

#endif