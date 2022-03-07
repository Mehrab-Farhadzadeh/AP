#include <iostream>

#include "../hdr/update.hpp"
#include "../hdr/ball.hpp"

using namespace std;

void update(Window &window, balls_t &balls, const int DELAY)
{
    static int counter = 0;
    static Point mouse_position;
    cout << mouse_position.x << "," << mouse_position.y << "  " << counter++ << endl;

    while (window.has_pending_event())
    {
        Event event = window.poll_for_event();
        switch (event.get_type())
        {
        case Event::MMOTION:
            mouse_position = event.get_mouse_position();
            break;
        case Event::QUIT:
            exit(0);
        default:
            break;
        }
    }
    balls[0].update(DELAY, mouse_position);
    balls[1].update(DELAY);
}