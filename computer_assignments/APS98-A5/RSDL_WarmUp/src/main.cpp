#include "../hdr/main.hpp"
#include "../hdr/update.hpp"
#include "../hdr/draw.hpp"
#include "../hdr/ShuffledTable.hpp"
#include "../hdr/rsdl.hpp"

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "Warm-up");
    ShuffledTable ShuffledTable(TableDimensions(IMG_WIDTH, IMG_HEIGHT, NUM_OF_ROWS_IN_IMG, NUM_OF_COLS_IN_IMG));
    while (true)
    {
        update(window, ShuffledTable);
        draw(window, ShuffledTable);
        delay(DELAY);
    }
}