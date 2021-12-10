#include <iostream>
#include <vector>
using namespace std;

int ch_to_digit(char ch);
bool is_charkheshi(string num_str);
void print_result(bool result);

int main()
{
  string num_str;
  cin >> num_str;

  int counter = 1;
  while (num_str != "0")
  {
    cout << "Case " << counter << ": ";
    print_result(is_charkheshi(num_str));
    cin >> num_str;
    counter++;
  }
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