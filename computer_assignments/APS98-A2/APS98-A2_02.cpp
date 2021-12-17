#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> words_locations;
vector<string> get_spaceless_strs(void);
void print_all_sentences(string spaceless_str);
bool sentences(string spaceless_strs, int after_this_location);

int main()
{
  vector<string> spaceless_strs = get_spaceless_strs();

  int num_of_spaceless_strs = (int)spaceless_strs.size();
  for (int spaceless_str = 0; spaceless_str < num_of_spaceless_strs; spaceless_str++)
  {
    print_all_sentences(spaceless_strs[spaceless_str]);
    cout << "***" << endl;
  }

  return 0;
}

vector<string> get_spaceless_strs(void)
{
  vector<string> spaceless_strs;
  string spaceless_str;
  while(cin >> spaceless_str)
    spaceless_strs.push_back(spaceless_str);

  return spaceless_strs;
}

void print_all_sentences(string spaceless_str)
{
  
}

