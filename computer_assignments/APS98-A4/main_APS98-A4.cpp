#include "Core.hpp"
#include "Thread.hpp"

int main()
{
    Core core(1);
    core.add_a_thread(Thread(1, 5));
    core.add_a_thread(Thread(2, 3));
}