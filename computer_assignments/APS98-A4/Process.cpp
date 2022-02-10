#include <vector>
#include "Process.hpp"
#include "Thread.hpp"

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
    threads[tid].run();
    if (threads[tid].is_done())
    {
        threads.erase(threads.begin() + tid - 1);
    }
}

std::vector<Thread> Process::get_queue_of_threads() { return threads; }
