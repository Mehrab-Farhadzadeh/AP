#include <iostream>

#include "../hdr/rsdl.hpp"
#include "../hdr/update.hpp"
#include "../hdr/draw.hpp"
#include "../hdr/ball.hpp"

using namespace std;

int main()
{
    Window window(480, 360, "Warm-up");
    Ball ball(Point(0, 0), Velociy(0, 0));
    while (true)
    {
        update(window, ball);
        draw(window, ball);
        delay(1000);
    }
}