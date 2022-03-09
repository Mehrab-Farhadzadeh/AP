#ifndef __ShuffledTable_HPP__
#define __ShuffledTable_HPP__

#include "../hdr/rsdl.hpp"

#include <vector>

const int IMG_WIDTH = 889;
const int IMG_HEIGHT = 889;
const int NUM_OF_ROWS_IN_IMG = 3;
const int NUM_OF_COLS_IN_IMG = 3;
const int BLOCK_WIDTH = IMG_WIDTH / NUM_OF_COLS_IN_IMG;
const int BLOCK_HEIGHT = IMG_HEIGHT / NUM_OF_ROWS_IN_IMG;
const double SCALE = 1 / 2.0;
const int WINDOW_WIDTH = IMG_WIDTH * SCALE;
const int WINDOW_HEIGHT = IMG_HEIGHT * SCALE;

struct TableDimensions
{
    TableDimensions(int _width, int _height, int _rows, int _columns);
    int width;
    int height;
    int rows;
    int columns;
};

class ShuffledTable
{
public:
    ShuffledTable(TableDimensions t_d);
    void update();
    void draw(Window &window);

private:
    int width;
    int height;
    int rows;
    int columns;
    std::vector<Point> rectangles_points;
    std::vector<int> shuffled_index;
};

std::vector<Point> calculate_rectangles_points(const TableDimensions &ShuffledTable_dimensions);
std::vector<int> get_non_repeating_shuffled_vector(size_t size);

#endif
