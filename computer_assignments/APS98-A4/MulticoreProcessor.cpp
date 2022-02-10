#include <vector>
#include "MulticoreProcessor.hpp"

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

MultiCoreProcessor::MultiCoreProcessor(int _id_of_last_core)
{
}

void MultiCoreProcessor::add_a_core()
{
    cores.push_back(Core(++id_of_last_core));
}

void MultiCoreProcessor::add_a_process(Process process)
{
    std::vector<Thread> threads = process.get_queue_of_threads();
    for (int i = 0; i < (int)threads.size(); i++)
    {
        cores[id_of_proper_core(cores)].add_a_thread(threads[i]);
    }
}

void MultiCoreProcessor::run(std::vector<Process> &processes)
{
    for (int i = 0; i < (int)cores.size(); i++)
    {
        cores[i].run(processes);
    }
}

void MultiCoreProcessor::show_cores_stat()
{
    for (int i = 0; i < (int)cores.size(); i++)
    {
        cores[i].show_stat();
    }
}