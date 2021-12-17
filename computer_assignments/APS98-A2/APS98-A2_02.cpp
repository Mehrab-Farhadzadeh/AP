#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> get_spaceless_sentences(void);
void print_all_meaningful_sentences(string spaceless_sentence);

int main()
{
  vector<string> spaceless_sentences = get_spaceless_sentences();

  int num_of_spaceless_sentences = (int)spaceless_sentences.size();
  for (int spaceless_sentence = 0; spaceless_sentence < num_of_spaceless_sentences; spaceless_sentence++)
  {
    print_all_meaningful_sentences(spaceless_sentences[spaceless_sentence]);
    cout << "***" << endl;
  }

  return 0;
}

vector<string> get_spaceless_sentences(void)
{
  vector<string> spaceless_sentences;
  string spaceless_sentence;
  while(cin >> spaceless_sentence)
    spaceless_sentences.push_back(spaceless_sentence);

  return spaceless_sentences;
}

void print_all_meaningful_sentences(string spaceless_sentence)
{

}

