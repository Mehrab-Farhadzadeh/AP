#include "Process.hpp"

Process::Process(int _id)
{
    id = _id;
}
void Process::run(int tid)
{
    threads[tid].run();
    if (threads[tid].is_done())
    {
        threads.erase(threads.begin() + tid - 1);
    }
}

void Process::add_a_thread(Thread thread)
{
}
