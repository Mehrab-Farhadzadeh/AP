#ifndef MULTIPROCESSOR_HPP
#define MULTIPROCESSOR_HPP

#include <vector>
#include "Core.hpp"

class MultiProcessor
{
public:
    MultiProcessor(int _id_of_last_core = 0);
    void add_a_core();
    void add_a_process();
    void run();

private:
    int id_of_last_core;
    std::vector<Core> cores;
};

#endif