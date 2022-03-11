#include "../hdr/update.hpp"

#include <iostream>
using namespace std;

void update(Window &window)
{
    while (window.has_pending_event())
    {
        Event event = window.poll_for_event();
        switch (event.get_type())
        {
        case Event::QUIT:
            exit(0);
        default:
            break;
        }
    }
}