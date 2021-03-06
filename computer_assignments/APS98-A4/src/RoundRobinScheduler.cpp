#include <iostream>
#include <vector>
#include "RoundRobinScheduler.hpp"
#include "MulticoreProcessor.hpp"
#include "Process.hpp"
#include "Thread.hpp"

void get_process_info_from_stdin(Process &process)
{
    int num_of_threads;
    std::cin >> num_of_threads;
    for (int i = 0; i < num_of_threads; i++)
    {
        int num_of_time_slices;
        std::cin >> num_of_time_slices;
        process.add_a_thread(Thread(process.get_id(), i + 1, num_of_time_slices));
    }
}

RoundRobinScheduler::RoundRobinScheduler(int _id_of_last_process) { id_of_last_process = _id_of_last_process; }

void RoundRobinScheduler::add_a_process()
{
    processes.push_back(Process(++id_of_last_process));
    get_process_info_from_stdin(processes.back());
    multicore_processor.add_a_process(processes.back());
    std::cout << "Process with pid = " << id_of_last_process << " added!" << std::endl;
}

void RoundRobinScheduler::add_a_core()
{
    multicore_processor.add_a_core();
}

void RoundRobinScheduler::show_cores_stat()
{
    multicore_processor.show_cores_stat();
}

void RoundRobinScheduler::run_cores()
{
    multicore_processor.run(processes);
}

void RoundRobinScheduler::finsih_tasks()
{
    int time_slices_counter = 0;
    while (!processes.empty())
    {
        std::cout << "Time Slice : " << ++time_slices_counter << std::endl;
        run_cores();
    }
}