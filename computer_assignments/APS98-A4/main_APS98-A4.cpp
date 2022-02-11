#include <iostream>
#include <vector>
#include "RoundRobinScheduler.hpp"
#include "MulticoreProcessor.hpp"
#include "Process.hpp"
#include "Core.hpp"
#include "Thread.hpp"
#include "Interface.hpp"

int main()
{

    RoundRobinScheduler round_robin_scheduler;

    while (true)
    {
        interface(round_robin_scheduler);
    }

}