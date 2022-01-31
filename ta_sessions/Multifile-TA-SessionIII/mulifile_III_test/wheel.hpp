#ifndef CIRCULAR_DEPENDENCY_WHEEL_HPP /*<PROJECT>_<PATH>_<FILE>_H */
#define CIRCULAR_DEPENDENCY_WHEEL_HPP

// #include "car.hpp"

class Car;
class Wheel
{
public:
    void hello();
    Car *car;
};

#endif