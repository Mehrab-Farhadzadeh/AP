#include "../hdr/main.hpp"
#include "../hdr/update.hpp"
#include "../hdr/draw.hpp"
#include "../hdr/rsdl.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "Warm-up");
    while (true)
    {
        update(window);
        draw(window);
        delay(DELAY);
    }
}