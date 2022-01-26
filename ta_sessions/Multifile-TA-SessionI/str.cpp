#include <string>
#include <sstream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int mult(int a, int b)
{
    return a * b;
}

string int_to_string(int a)
{
    stringstream converter;
    converter << a;
    return converter.str();
}