#include "RoundRobinScheduler.hpp"

RoundRobinScheduler::RoundRobinScheduler(int _id_of_last_process)
{

}
void RoundRobinScheduler::add_a_process(Process process)
{
}
void RoundRobinScheduler::finsih_tasks()
{
    while(!processes.empty())
    {
        multi_core_processor.run(processes);
    }
}