#include "../headers/Ball.hpp"

Ball::Ball(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Ball::set_v(float _vx, float _vy)
{
    vx = _vx;
    vy = _vy;
}