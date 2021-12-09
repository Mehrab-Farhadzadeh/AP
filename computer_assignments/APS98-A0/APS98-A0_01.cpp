#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ibm_minus_one(string str);

int main()
{
  string str;
  vector<string> corresponding_acronyms;
  int num_of_strs;
  cin >> num_of_strs;
  for (int str_counter = 0; str_counter < num_of_strs; str_counter++)
  {
    cin >> str;
    string corresponding_acronym = ibm_minus_one(str);
    corresponding_acronyms.push_back(corresponding_acronym);
  }
  
  for (int counter = 0; counter < num_of_strs; counter++)
  {
    cout << "string #" << counter + 1 << endl;
    cout << corresponding_acronyms[counter] << endl
         << endl;
  }

  return 0;
}

string ibm_minus_one(string str)
{
  for (int i = 0; i < str.size(); i++)
  {
    str[i] != 'Z' ? str[i] = str[i] + 1 : str[i] = 'A';
  }
  return str;
}