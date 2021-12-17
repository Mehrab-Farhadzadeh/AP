#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<int> words_locations_on_str;

vector<string> get_spaceless_strs(void);
void print_all_sentences(string spaceless_str);
bool sentences(string spaceless_str, int after_this_location);
bool is_meaningful(string spaceless_strs, int after_this_location, int end_of_word);
void print_sentence(string spaceless_str, vector<int> words_locations_on_str);

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
  words_locations_on_str.clear();
  sentences(spaceless_str, 0);
  //print_sentence(spaceless_str, words_locations_on_str);
}

bool sentences(string spaceless_str, int after_this_location)
{
  if (after_this_location >= (int)spaceless_str.size())
  {
    print_sentence(spaceless_str, words_locations_on_str);
    return true;
  }

  for (int end_of_word = after_this_location + 1; end_of_word <= (int)spaceless_str.size(); end_of_word++)
  {
    if (is_meaningful(spaceless_str, after_this_location, end_of_word))
    {
      words_locations_on_str.push_back(end_of_word);
      sentences(spaceless_str, end_of_word);
      words_locations_on_str.pop_back();
    }
  }
  return false;
}

bool is_meaningful(string spaceless_strs, int after_this_location, int end_of_word)
{
  int len = end_of_word - after_this_location;
  string word = spaceless_strs.substr(after_this_location, len);

  ifstream meaningful_words_file("words.txt");

  string readed_word;
  while (meaningful_words_file >> readed_word)
    if (readed_word == word)
      return true;

  meaningful_words_file.close();

  return false;
}

void print_sentence(string spaceless_str, vector<int> words_locations_on_str)
{
  for (int char_location = 0, space_location = 0; char_location < (int)spaceless_str.size(); char_location++)
  {
    cout << spaceless_str[char_location];
    if ((char_location + 1) == words_locations_on_str[space_location])
    {
      cout << " ";
      space_location++;
    }
  }
  cout << endl;
}
