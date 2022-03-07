#ifndef __BALL_HPP__
#define __BALL_HPP__

#include "../hdr/rsdl.hpp"
#include <vector>

struct Velociy
{
    Velociy(float _vx, float _vy);
    Velociy() = default;
    float vx;
    float vy;
};

class Ball
{
public:
    Ball(Point _position, Velociy _v = Velociy(0, 0), int _speed = 0, int _radius = 15, RGB _color = WHITE);
    void update(Point new_position);
    void update(const int milisecond_interval);
    void update(const int milisecond_interval, Point end);
    void draw(Window &window);
    void set_speed(const int _speed);

private:
    Point position;
    Velociy v;
    int speed;
    int radius;
    RGB color;
};

typedef std::vector<Ball> balls_t;

double calculate_distance(const Point &p0, const Point &p2);
Velociy calculate_velocity(const Point &p1, const Point &p2, const int &speed);
#endif