#include <iostream>
#include <vector>

using namespace std;

vector<int> reverse_sequence(vector<int>);

int main()
{
    vector<int> numbers(1000000);
    
    for (int i = 0; i < 1000; i++)
    {
        reverse_sequence(numbers);
    }

    return 0;
}

vector<int> reverse_sequence(vector<int> numbers)
{
    for (int i = 0; i < (numbers.size() / 2); i++)
    {
        swap(numbers[i], numbers[numbers.size() - i - 1]);
    }

    return numbers;
}