#include <iostream>
#include "../hdr/rsdl.hpp"

using namespace std;

int main()
{

    Window win;
    Point p(0, 0);
    Rectangle rect(p, 200, 200);
    win.draw_rect(rect);
    win.update_screen();
    delay(2000);
    
    cout << "hello" << endl;
}