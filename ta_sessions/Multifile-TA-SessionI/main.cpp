#include <iostream>
#include "str.hpp"
using namespace std;

int main()
{
    int a = 3, b = 4;
    cout << add(a, b) << endl;
    cout << mult(a, b) << endl;
    cout << int_to_string(a) + " is str" << endl;
}