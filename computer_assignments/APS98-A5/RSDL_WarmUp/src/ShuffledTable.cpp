#include "../hdr/ShuffledTable.hpp"

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

TableDimensions::TableDimensions(int _width, int _height, int _rows, int _columns)
    : width(_width), height(_height), rows(_rows), columns(_columns) {}

ShuffledTable::ShuffledTable(TableDimensions t_d)
    : width(t_d.width), height(t_d.height), rows(t_d.rows), columns(t_d.columns)
{
    rectangles_points = calculate_rectangles_points(t_d);
    shuffled_index = get_non_repeating_shuffled_vector(rectangles_points.size());
    srand(unsigned(time(nullptr)));
}

void ShuffledTable::update()
{
    shuffled_index = get_non_repeating_shuffled_vector(rectangles_points.size());
}

void ShuffledTable::draw(Window &window)
{
    for (size_t i = 0; i < rectangles_points.size(); i++)
    {
        Point top_left_corner_src = rectangles_points[i];
        Point top_left_corner_dst = rectangles_points[shuffled_index[i]] / (1 / SCALE);
        window.draw_img("./assets/warmup/warmup.png",
                        Rectangle(top_left_corner_dst, BLOCK_WIDTH * SCALE, BLOCK_HEIGHT * SCALE),
                        Rectangle(top_left_corner_src, BLOCK_WIDTH, BLOCK_HEIGHT));
    }
}

vector<Point> calculate_rectangles_points(const TableDimensions &ShuffledTable_dimensions)
{
    vector<Point> rectangles_points;

    for (int row = 0; row < ShuffledTable_dimensions.rows; row++)
        for (int col = 0; col < ShuffledTable_dimensions.columns; col++)
        {
            Point top_left_corner;
            top_left_corner.x = row * BLOCK_HEIGHT;
            top_left_corner.y = col * BLOCK_WIDTH;
            rectangles_points.push_back(top_left_corner);
        }

    return rectangles_points;
}

vector<int> get_non_repeating_shuffled_vector(size_t size)
{
    vector<int> non_repeating_shuffled_vector;
    for (size_t i = 0; i < size; i++)
        non_repeating_shuffled_vector.push_back(i);

    for (size_t i = 0; i < non_repeating_shuffled_vector.size(); i++)
    {
        int j = rand() % size;
        swap(non_repeating_shuffled_vector[i], non_repeating_shuffled_vector[j]);
    }

    return non_repeating_shuffled_vector;
}