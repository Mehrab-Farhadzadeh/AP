#ifndef THREAD_HPP
#define THREAD_HPP

#include <vector>

class Thread
{
public:
    Thread(int _pid, int _tid, int _demanded_time_slices);
    void run();
    bool is_done();
    int get_tid();
    int get_pid();
    int remaining_time_slots();

private:
    int pid, tid;
    int demanded_time_slices;
};

#endif