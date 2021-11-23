#include <iostream>
#include <vector>
using namespace std;

int num_of_positives(vector<int> list, int i);

int main()
{
    vector<int> a;
    int x;
    cout << "Please enter the list's elements:\n";
    while (cin >> x)
        a.push_back(x);

    cout << "Number of positives = " << num_of_positives(a, 0) << endl;
}

int num_of_positives(vector<int> list, int i)
{
    if (i == list.size())
        return 0;
    else
        return list[i] > 0 ? 1 + num_of_positives(list, i + 1) : num_of_positives(list, i + 1);
}