#include "../headers/Ball.hpp"

Ball::Ball(int _x, int _y)
{
    x = _x;
    y = _y;
    vx = 0;
    vy = 0;
}

void Ball::set_v(float _vx, float _vy)
{
    vx = _vx;
    vy = _vy;
}

void Ball::move_one_ms()
{
    constexpr float TIME_INTERVAL = 0.1;
    x = vx * TIME_INTERVAL;
    y = vy * TIME_INTERVAL;
}