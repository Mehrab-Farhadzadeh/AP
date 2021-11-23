#include <iostream>
#include <vector>

using namespace std;

void reverse_sequence(vector<int>&);

int main()
{
    vector<int> numbers;
    for (int i = 0; i < 10; i++)
    {
        numbers.push_back(i + 5);
    }
    
    reverse_sequence(numbers);

    return 0;
}

void reverse_sequence(vector<int> &numbers)
{
    for (int i = 0; i < (numbers.size() / 2); i++)
    {
        swap(numbers[i], numbers[numbers.size() - i - 1]);
        
    }

}