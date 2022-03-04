#include "../hdr/draw.hpp"
#include "../hdr/ball.hpp"

void draw(Window &window, balls_t &balls, const int DELAY)
{
    window.clear();
    balls[0].draw(window);
    balls[1].draw(window);
    window.update_screen();
}