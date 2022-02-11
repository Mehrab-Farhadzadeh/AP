#include <iostream>
#include <vector>
#include "MulticoreProcessor.hpp"
#include "Process.hpp"
#include "Core.hpp"

int id_of_proper_core(std::vector<Core> cores)
{
    if (!cores.empty())
    {
        int proper_id = cores[0].get_id(), min = cores[0].get_size_of_queue();
        for (int i = 1; i < (int)cores.size(); i++)
        {
            int size = cores[i].get_size_of_queue();
            if (size < min)
            {
                min = size;
                proper_id = cores[i].get_id();
            }
        }
        return proper_id;
    }
    return -1;
}

MulticoreProcessor::MulticoreProcessor(int _id_of_last_core)
{
    id_of_last_core = _id_of_last_core;
    cores.push_back(Core(++id_of_last_core));
    cores.push_back(Core(++id_of_last_core));
}

void MulticoreProcessor::add_a_core()
{
    cores.push_back(Core(++id_of_last_core));
    std::cout << "Core with core ID = " << id_of_last_core << " successfully added!" << std::endl;
}

void MulticoreProcessor::add_a_process(Process process)
{
    std::vector<Thread> threads = process.get_threads();
    for (int i = 0; i < (int)threads.size(); i++)
    {
        cores[id_of_proper_core(cores) - 1].add_a_thread(threads[i]);
    }
}

void MulticoreProcessor::run(std::vector<Process> &processes)
{
    for (int i = 0; i < (int)cores.size(); i++)
    {
        cores[i].run(processes);
    }
}

void MulticoreProcessor::show_cores_stat()
{
    for (int i = 0; i < (int)cores.size(); i++)
    {
        cores[i].show_stat();
    }
}