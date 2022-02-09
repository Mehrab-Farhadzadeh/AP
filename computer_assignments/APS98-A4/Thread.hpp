#ifndef THREAD_HPP
#define THREAD_HPP

#include <vector>

class Thread
{
public:
    Thread(int _id, int _demanded_time_slices);
    void run();
    bool is_done();

private:
    int id;
    int demanded_time_slices;
};

#endif