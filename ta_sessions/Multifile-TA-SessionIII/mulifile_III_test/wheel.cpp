#include "car.hpp"
#include "wheel.hpp"

Wheel get_wheel_of_car(Wheel wheel)
{
    return wheel.car->wheel_1;
}