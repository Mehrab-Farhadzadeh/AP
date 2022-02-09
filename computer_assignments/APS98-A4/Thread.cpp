#include "Thread.hpp"

Thread::Thread(int _pid, int _tid, int _demanded_time_slices)
{
    pid = _pid;
    tid = _tid;
    demanded_time_slices = _demanded_time_slices;
}

void Thread::run()
{
    demanded_time_slices--;
}
bool Thread::is_done()
{
    return demanded_time_slices == 0;
}

int Thread::get_tid() { return tid; }

int Thread::get_pid() { return pid; }

int Thread::remaining_time_slots() { return demanded_time_slices; }