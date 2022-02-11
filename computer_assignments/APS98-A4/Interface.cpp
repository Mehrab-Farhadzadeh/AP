#include <iostream>
#include <string>
#include "Interface.hpp"
#include "RoundRobinScheduler.hpp"

void interface(RoundRobinScheduler &round_robin_scheduler)
{
    std::cout << BOLDCYAN << ">> " << RESET;
    std::string command;
    std::cin >> command;
    if (command == "add_core")
    {
        round_robin_scheduler.add_a_core();
    }
    else if (command == "add_process")
    {
        round_robin_scheduler.add_a_process();
    }
    else if (command == "show_cores_stat")
    {
        round_robin_scheduler.show_cores_stat();
    }
    else if (command == "run_cores")
    {
        round_robin_scheduler.run_cores();
    }
    else if (command == "finish_tasks")
    {
        round_robin_scheduler.finsih_tasks();
    }
    else
    {
        std::cout << "Command \"" << BOLDRED << command << RESET << "\" not found, available commands:" << std::endl
                  << BOLDWHITE << "\tadd_core" << std::endl
                  << "\tadd_process <number_of_process_threads> <number_of_time_slices_per_first_thread> ..." << std::endl
                  << "\tshow_cores_stat" << std::endl
                  << "\trun_cores" << std::endl
                  << "\tfinish_tasks" << RESET << std::endl;
    }
}