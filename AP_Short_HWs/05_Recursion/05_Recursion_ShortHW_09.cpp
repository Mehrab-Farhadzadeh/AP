#include <iostream>
#include <vector>
using namespace std;

// a[0]*a[1] + a[2]/a[3] + …
int sum_list_09_recursive(vector<int> list, int i, bool divide);
int sum_list_09(vector<int> list, int i);

int main()
{
    vector<int> a;
    int x;
    cout << "Please enter the list's elements:\n";
    while (cin >> x)
        a.push_back(x);

    cout << "result = " << sum_list_09(a, 0) << endl;
}

int sum_list_09_recursive(vector<int> list, int i, bool divide)
{
    if (i == list.size())
        return 0;

    if ((i + 1) == list.size())
        return list[i];

    if (divide)
        return (list[i] / list[i + 1]) + sum_list_09_recursive(list, i + 2, false);

    return (list[i] * list[i + 1]) + sum_list_09_recursive(list, i + 2, true);
}

int sum_list_09(vector<int> list, int i)
{
    return sum_list_09_recursive(list, i, false);
}