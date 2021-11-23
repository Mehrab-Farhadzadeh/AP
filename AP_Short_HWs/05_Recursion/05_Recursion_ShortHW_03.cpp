#include <iostream>
#include <vector>
using namespace std;

int sum_list_positives(vector<int> list, int i);

int main()
{
    vector<int> a;
    int x;
    cout << "Please enter the list's elements:\n";
    while (cin >> x)
        a.push_back(x);

    cout << "sum of positives = " << sum_list_positives(a, 0) << endl;
}

int sum_list_positives(vector<int> list, int i)
{
    if (i == list.size())
        return 0;
    else
        return list[i] > 0 ? list[i] + sum_list_positives(list, i + 1) : sum_list_positives(list, i + 1);
}