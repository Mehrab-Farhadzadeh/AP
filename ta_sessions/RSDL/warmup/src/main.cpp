#include <iostream>

#include "../hdr/rsdl.hpp"
#include "../hdr/update.hpp"
#include "../hdr/draw.hpp"
#include "../hdr/ball.hpp"

using namespace std;

const int DELAY = 30;
const int WIDTH = 900;
const int HEIGHT = 600;

int main()
{
    Window window(WIDTH, HEIGHT, "Warm-up");
    balls_t balls;
    balls.push_back(Ball(Point(200, 300), Velociy(0, 0), 200, 15, RGB(220, 220, 0)));
    balls.push_back(Ball(Point(100, 200), Velociy(34, 0), 0, 30, RGB(0, 220, 220))); // To do: Matching speed and velocity

    while (true)
    {
        update(window, balls, DELAY);
        draw(window, balls, DELAY);
        delay(DELAY);
    }
}