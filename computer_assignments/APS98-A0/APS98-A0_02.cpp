#include <iostream>
#include <vector>
using namespace std;

bool read_and_split_number(vector<vector<int>> &splited_num(7, vector<int>(2, 0)));
int ch_to_digit(char ch);
bool is_charkheshi(vector<vector<int>> &splited_num(7, vector<int>(2, 0)));
void print_result(bool result);

int main()
{
  int counter = 0;
  while (true)
  {
    vector<vector<int>> splited_num(7, vector<int>(2, 0));
    if (!read_and_split_number(splited_num))
      break;
    counter++;
    cout << "Case " << counter << ": ";
    print_result(is_charkheshi(splited_num));
  }

  return 0;
}

bool read_and_split_number(vector<vector<int>> &splited_num(7, vector<int>(2, 0)))
{
  char ch;
  cin.get(ch);
  if ((ch == '0') || (ch == '\n'))
    return false;
  int i = 0;
  while (true)
  {
    cin.get(ch);
    if (ch == '\n')
      break;
    int digit = ch_to_digit(ch);
    splited_num[i][0] = digit;
    i++;
  }
  return true;
}

int ch_to_digit(char ch)
{
  return (int)ch - 48;
}

bool is_charkheshi(vector<vector<int>> &splited_num(7, vector<int>(2, 0)))
{
}

void print_result(bool result)
{
  if (result)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}