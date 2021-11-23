#include <iostream>
#include <vector>
using namespace std;

int add_odds_subtract_evens(vector<int> list, int i);

int main()
{
    vector<int> a;
    int x;
    cout << "Please enter the list's elements:\n";
    while (cin >> x)
        a.push_back(x);

    cout << "result = " << add_odds_subtract_evens(a, 0) << endl;
}

int add_odds_subtract_evens(vector<int> list, int i)
{
    if (i == list.size())
        return 0;
    return i % 2 ? -list[i] + add_odds_subtract_evens(list, i + 1):
                    list[i] + add_odds_subtract_evens(list, i + 1);
}