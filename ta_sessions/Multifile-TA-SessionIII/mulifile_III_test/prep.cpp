# 1 "main.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "main.cpp"
# 1 "car.hpp" 1



# 1 "wheel.hpp" 1



class Car;
class Wheel
{
    Car *car;
};
# 5 "car.hpp" 2
class Car
{
    Wheel wheel_1, wheel_2;
};
# 2 "main.cpp" 2

int main()
{
    Car car;
}
