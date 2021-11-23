#include <iostream>
#include <vector>

using namespace std;

void f(int &n);

int main()
{
    int n;

    for (int i = 0; i < 1000000000; i++)
    {
        n = 5;
        f(n);
    }

    return 0;
}

void f(int &n)
{
    n = 7;
}