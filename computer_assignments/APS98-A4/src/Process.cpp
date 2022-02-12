#include <vector>
#include "Process.hpp"
#include "Thread.hpp"

int index_of_thread(std::vector<Thread> threads, int tid)
{
    int size = (int)threads.size();
    for (int i = 0; i < size; i++)
    {
        if (threads[i].get_tid() == tid)
            return i;
    }
    return -1;
}

Process::Process(int _id)
{
    id = _id;
}

void Process::add_a_thread(Thread thread)
{
    threads.push_back(thread);
}

void Process::run(int tid)
{
    int t_index = index_of_thread(threads, tid);
    threads[t_index].run();
    if (threads[t_index].is_done())
    {
        threads.erase(threads.begin() + t_index);
    }
}

bool Process::is_done()
{
    return (int)threads.size() == 0;
}

std::vector<Thread> Process::get_threads() { return threads; }
int Process::get_id() { return id; }
