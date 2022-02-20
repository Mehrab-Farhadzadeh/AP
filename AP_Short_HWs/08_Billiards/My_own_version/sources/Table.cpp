#include "../headers/Table.hpp"

#include <vector>
#include <iostream>
#include <cstdio>

#include "../headers/Ball.hpp"

using namespace std;

Table::Table(int _length, int _width)
{
    lenght = _length;
    width = _width;
}

void Table::add_a_ball(Ball ball)
{
    balls.push_back(ball);
}

void Table::show()
{
    
}