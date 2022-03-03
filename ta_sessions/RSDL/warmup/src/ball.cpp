#include "../hdr/ball.hpp"
#include "../hdr/rsdl.hpp"

Velociy::Velociy(float _vx, float _vy) : vx(_vx), vy(_vy) {}

Ball::Ball(Point _position, Velociy _v) : position(_position), v(_v) {}

void Ball::update(Point new_position)
{
    position.x = new_position.x;
    position.y = new_position.y;
}
void Ball::draw(Window &window)
{
    window.fill_circle(position, BALL_RADIUS, BALL_COLOR);
}