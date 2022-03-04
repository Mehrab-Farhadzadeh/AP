#ifndef __BALL_HPP__
#define __BALL_HPP__

#include "../hdr/rsdl.hpp"
#include <vector>

struct Velociy
{
    Velociy(float _vx, float _vy);
    float vx;
    float vy;
};

class Ball
{
public:
    Ball(Point _position, Velociy _v, int _radius = 15, RGB _color = WHITE);
    void update(Point new_position);
    void update(const int milisecond_interval);
    void draw(Window &window);

private:
    Point position;
    Velociy v;
    int radius;
    RGB color;
};

typedef std::vector<Ball> balls_t;

void move_ball(Ball &ball, Window &window, Point end);

#endif