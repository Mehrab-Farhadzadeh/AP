#include <iostream>
#include <vector>
using namespace std;

int ch_to_digit(char ch);
bool is_charkheshi(string num_str);
void print_result(bool result);

int main()
{

  return 0;
}

int ch_to_digit(char ch)
{
  return (int)ch - 48;
}

bool is_charkheshi(string num_str)
{
}

void print_result(bool result)
{
  if (result)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}