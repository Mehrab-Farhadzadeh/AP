#include "../hdr/draw.hpp"
#include "../hdr/ball.hpp"

void draw(Window &window, Ball &ball)
{
    window.clear();
    ball.draw(window);
    window.update_screen();
}