#include "../hdr/rsdl.hpp"

Rectangle get_dynamic_rect(const Window &win, const int &frame)
{
    Point p(0, 0);
    int h = 200 - frame % 100;
    int w = 200 - frame % 100;
    return Rectangle (p, w, h);
}
