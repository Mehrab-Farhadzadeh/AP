#ifndef CIRCULAR_DEPENDENCY_CAR_HPP /*<PROJECT>_<PATH>_<FILE>_H */
#define CIRCULAR_DEPENDENCY_CAR_HPP

#include "wheel.hpp"

class Car
{
public:
    Wheel wheel_1, wheel_2;
};

#endif

/*
Header file best practices
    Here are a few more recommendations for creating and using header files.

        1. Always include header guards (we’ll cover these next lesson).
        2. Do not define variables and functions in header files (global constants are an exception -- we’ll cover these later)
        3. Give a header file the same name as the source file it’s associated with (e.g. grades.h is paired with grades.cpp).
        4. Each header file should have a specific job, and be as independent as possible. For example, you might put all your declarations related to functionality A in A.h and all your declarations related to functionality B in B.h. That way if you only care about A later, you can just include A.h and not get any of the stuff related to B.
        5. Be mindful of which headers you need to explicitly include for the functionality that you are using in your code files
        6. Every header you write should compile on its own (it should #include every dependency it needs)
        7. Only #include what you need (don’t include everything just because you can).
        9. Do not #include .cpp files.
*/