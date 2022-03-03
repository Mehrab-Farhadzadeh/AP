#ifndef __BALL_HPP__
#define __BALL_HPP__

#include "../hdr/rsdl.hpp"

const int BALL_RADIUS = 20;
const RGB BALL_COLOR(175, 20, 20);

struct Velociy
{
    Velociy(float _vx, float _vy);
    float vx;
    float vy;
};

class Ball
{
public:
    Ball(Point _position, Velociy _v);
    void update(Point new_position);
    void draw(Window &window);

private:
    Point position;
    Velociy v;
};

#endif