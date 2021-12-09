#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// if don't exists returns 0
int first_odd_frequent_number(vector<int> numbers);

int main()
{
  vector<int> numbers;
  int number;
  for (int i = 0; cin >> number; i++)
    numbers.push_back(number);

  cout << endl << first_odd_frequent_number(numbers) << endl;
  
  return 0;
}

int first_odd_frequent_number(vector<int> numbers)
{
  sort(numbers.begin(), numbers.end());

  int frequency;
  for (int i = 0; i < numbers.size(); i += frequency)
  {
    frequency = 1;
    for (int j = i + 1; (j < numbers.size()) && (numbers[i] == numbers[j]); frequency++, j++)
      ;
    if ((frequency % 2) == 1)
    {
      return numbers[i];
    }
  }
  return 0;
}
