#include <iostream>
#include <vector>
#include "Core.hpp"
#include "Thread.hpp"
#include "Process.hpp"

using namespace std;

int index_of_process(std::vector<Process> processes, int pid)
{
    int size = (int)processes.size();
    for (int i = 0; i < size; i++)
    {
        if (processes[i].get_id() == pid)
            return i;
    }
    return -1;
}

void show_stat_in_run(Thread thread, int core_id)
{
    cout << "Core number : " << core_id << endl;
    cout << "Process ID : " << thread.get_pid() << " - Thread ID : " << thread.get_tid() << endl;
}

Core::Core(int _id)
{
    id = _id;
}

void Core::add_a_thread(Thread thread)
{
    queue.insert(queue.begin(), thread);
}

void Core::run(std::vector<Process> &processes)
{
    if (!queue.empty())
    {
        Thread thread = queue.back();
        thread.run();
        queue.pop_back();
        if (!thread.is_done())
        {
            queue.insert(queue.begin(), thread);
        }

        int p_index = index_of_process(processes, thread.get_pid());
        processes[p_index].run(thread.get_tid());
        if (processes[p_index].is_done())
        {
            processes.erase(processes.begin() + p_index);
        }
        show_stat_in_run(thread, id);
    }
}

void Core::show_stat()
{
    cout << "Core number : " << id << endl;
    for (int i = 0; i < (int)queue.size(); i++)
    {
        cout << "Process ID : " << queue[i].get_pid() << " - Thread ID : " << queue[i].get_tid() << endl;
        cout << "Number of time slots : " << queue[i].remaining_time_slots() << endl;
    }
}

int Core::get_id() { return id; }
int Core::get_size_of_queue() { return (int)queue.size(); }
