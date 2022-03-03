#include <iostream>
#include "../hdr/rsdl.hpp"
#include "../hdr/rect.hpp"

using namespace std;

int main()
{

    Window win;
    Point p(0, 0);
    Rectangle rect(p, 200, 200);
    win.draw_rect(rect);
    win.update_screen();

    int frame = 0;
    bool is_finished = false;
    Point mm(0, 0);
    while (!is_finished)
    {
        cout << frame++ << " ";
        while (win.has_pending_event())
        {
            Event event = win.poll_for_event();
            switch (event.get_type())
            {
            case Event::KEY_PRESS:
                cout << "Pressed Key: " << event.get_pressed_key() << endl;
                break;
            case Event::QUIT:
                cout << "Quit..." << endl;
                is_finished = true;
                break;
            case Event::NA:
                cout << "NA..." << endl;
                break;
            case Event::MMOTION:
                mm = event.get_mouse_position();
                cout << "MM" << endl;
                break;
            default:
                cout << "Other..." << endl;
                break;
            }
            win.fill_circle(mm, 10, RED);
        }
        win.fill_circle(mm, 10, RED);
        win.draw_rect(get_dynamic_rect(win, frame));
        win.update_screen();
        win.clear();
        delay(15);
        cout << endl;
    }

    cout << "hello" << endl;
}