#include <iostream>

#include "../hdr/ball.hpp"
#include "../hdr/rsdl.hpp"

using namespace std;

Velociy::Velociy(float _vx, float _vy) : vx(_vx), vy(_vy) {}

Ball::Ball(Point _position, Velociy _v, int _radius, RGB _color)
    : position(_position), v(_v), radius(_radius), color(_color) {}

void Ball::update(Point new_position)
{
    position.x = new_position.x;
    position.y = new_position.y;
}

void Ball::update(const int milisecond_interval)
{
    float second_interval = milisecond_interval / 1000.0;
    position.x += v.vx * second_interval;
    position.y += v.vy * second_interval;
}

void Ball::draw(Window &window)
{
    window.fill_circle(position, radius, color);
}

void move_ball(Ball &ball, Window &window, Point end)
{
}