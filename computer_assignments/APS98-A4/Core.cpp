#include "Core.hpp"
#include "Thread.hpp"

Core::Core(int _id)
{
    id = _id;
}

void Core::add_a_thread(Thread thread)
{
    queue.insert(queue.begin(), thread);
}

void Core::run()
{
    if (!queue.empty())
    {
        Thread thread = queue.back();
        queue.pop_back();
        thread.run();
        if (!thread.is_done())
        {
            queue.insert(queue.begin(), thread);
        }
    }
}