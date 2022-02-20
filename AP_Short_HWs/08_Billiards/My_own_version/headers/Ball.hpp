#ifndef BALL_HPP
#define BALL_HPP

class Ball
{
public:
    Ball(int _x, int _y);
    void set_v(float _vx, float _vy);
    void move_one_ms();

private:
    int x, y;
    float vx, vy;
};

#endif