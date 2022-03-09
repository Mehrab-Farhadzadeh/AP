#include "../hdr/update.hpp"
#include "../hdr/ShuffledTable.hpp"

#include <iostream>
using namespace std;

void update(Window &window, ShuffledTable &ShuffledTable)
{
    while (window.has_pending_event())
    {
        Event event = window.poll_for_event();
        switch (event.get_type())
        {
        case Event::KEY_PRESS:
            if (event.get_pressed_key() == 'r')
            {
                ShuffledTable.update();
            }
            break;
        case Event::QUIT:
            exit(0);
        default:
            break;
        }
    }
}