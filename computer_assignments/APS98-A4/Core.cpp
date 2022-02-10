#include <iostream>
#include <vector>
#include "Core.hpp"
#include "Thread.hpp"
#include "Process.hpp"

using namespace std;

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
        processes[thread.get_pid() - 1].run(thread.get_tid());
        queue.pop_back();
        thread.run();
        if (!thread.is_done())
        {
            queue.insert(queue.begin(), thread);
        }
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

void Core::show_stat_in_run()
{
    if (!queue.empty())
    {
        cout << "Core number : " << id << endl;
        for (int i = 0; i < (int)queue.size(); i++)
        {
            cout << "Process ID : " << queue[i].get_pid() << " - Thread ID : " << queue[i].get_tid() << endl;
        }
    }
}

int Core::get_id() { return id; }
int Core::get_size_of_queue() { return (int)queue.size(); }
