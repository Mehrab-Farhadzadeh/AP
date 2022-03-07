#include <iostream>
#include <cmath>

#include "../hdr/ball.hpp"
#include "../hdr/rsdl.hpp"

using namespace std;

Velociy::Velociy(float _vx, float _vy) : vx(_vx), vy(_vy) {}

Ball::Ball(Point _position, Velociy _v, int _speed, int _radius, RGB _color)
    : position(_position), v(_v), speed(_speed), radius(_radius), color(_color) {}

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

void Ball::update(const int milisecond_interval, Point end)
{
    v = calculate_velocity(position, end, speed);
    update(milisecond_interval);
    if ((v.vx >= 0 && position.x >= end.x) || (v.vx <= 0 && position.x <= end.x) ||
        (v.vy >= 0 && position.y >= end.y) || (v.vy <= 0 && position.y <= end.y))
    {
        position.x = end.x;
        position.y = end.y;
    }
}

void Ball::draw(Window &window)
{
    window.fill_circle(position, radius, color);
}

void Ball::set_speed(const int _speed)
{
    speed = _speed;
}

double calculate_distance(const Point &p1, const Point &p2)
{
    int delta_x = p2.x - p1.x;
    int delta_y = p2.y - p1.y;
    double distance = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
    return distance;
}

Velociy calculate_velocity(const Point &p1, const Point &p2, const int &speed)
{
    double distance = calculate_distance(p1, p2);
    if (distance == 0)
        return Velociy(0, 0);
    double time = distance / speed;
    int delta_x = p2.x - p1.x;
    int delta_y = p2.y - p1.y;
    Velociy v;
    v.vx = delta_x / time;
    v.vy = delta_y / time;
    return v;
}
