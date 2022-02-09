#include "Thread.hpp"

Thread::Thread(int _id, int _demanded_time_slices)
{
    id = _id;
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