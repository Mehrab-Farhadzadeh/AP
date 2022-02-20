#ifndef TABLE_HPP
#define TABLE_HPP

#include <vector>
#include "../headers/Ball.hpp"

class Table
{
public:
    Table(int _length, int _width);
    void add_a_ball(Ball ball);
    void show();

private:
    int lenght;
    int width;
    std::vector<Ball> balls;
};

#endif