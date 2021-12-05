#include <iostream>
#include <vector>
using namespace std;

// if don't exists returns 0
int first_odd_frequent_number(vector<int> numbers);

int main()
{
  vector<int> numbers;

  for (int i = 0; cin >> numbers[i]; i++)
    ;

  cout << first_odd_frequent_number(numbers);
  
  return 0;
}

int first_odd_frequent_number(vector<int> numbers)
{
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