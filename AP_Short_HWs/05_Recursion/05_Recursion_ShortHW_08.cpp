#include <iostream>
#include <vector>
using namespace std;

// a[0]*a[1] + a[2]*a[3] - … + a[n-2]*a[n-1]
int sum_list_08(vector<int> list, int i);

int main()
{
    vector<int> a;
    int x;
    cout << "Please enter the list's elements:\n";
    while (cin >> x)
        a.push_back(x);

    cout << "result = " << sum_list_08(a, 0) << endl;
}

int sum_list_08(vector<int> list, int i)
{
    if (i == list.size())
        return 0;

    if ((i + 1) == list.size())
        return list[i];

    return (list[i] * list[i + 1]) + sum_list_08(list, i + 2);
}