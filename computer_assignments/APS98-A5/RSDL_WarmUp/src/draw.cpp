#include "../hdr/draw.hpp"
#include "../hdr/main.hpp"
#include "../hdr/ShuffledTable.hpp"

void draw(Window &window, ShuffledTable &ShuffledTable)
{
    window.clear();
    ShuffledTable.draw(window);
    window.update_screen();
}