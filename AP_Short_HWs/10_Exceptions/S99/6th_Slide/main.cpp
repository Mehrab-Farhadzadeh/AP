#include <iostream>
using namespace std;

void f(int i)
{
    cout << "f1\n";
    if (i % 2)
        throw runtime_error("error");
    cout << "f2\n";
}
void g()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "g" << i << endl;
        f(i);
    }
}
void h()
{
    try
    {
        cout << "h1\n";
        g();
        cout << "h2\n";
    }
    catch (runtime_error &ex)
    {
        try
        {
            cout << "h1\n";
            g();
            cout << "h2\n";
        }
        catch (runtime_error &ex)
        {
            cout << "nested 1" << endl;
        }
    }
    cout << "h4\n";
}

int main()
{
    h();
}