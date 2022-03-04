#include <iostream>
using namespace std;

#include "../hdr/update.hpp"
#include "../hdr/ball.hpp"

void update(Window &window, balls_t &balls, const int DELAY)
{
    while (window.has_pending_event())
    {
        Event event = window.poll_for_event();
        switch (event.get_type())
        {
        case Event::MMOTION:
            balls[0].update(event.get_mouse_position());
            break;
        case Event::QUIT:
            exit(0);
        default:
            break;
        }
    }
    balls[1].update(DELAY);
}