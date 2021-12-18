#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<Movement> moves;

struct Movement
{
  int row;
  int col;
  char dir;
};

typedef vector<string> map_t;

map_t get_map();

bool play(map_t map, Movement movement);
void print_moves();
void print_error();

int main()
{
  map_t map = get_map();
  Movement movement;

  if (play(map, movement))
    print_moves();
  else
    print_error();

  return 0;
}

map_t get_map()
{
  map_t map;
  string line;
  while (cin >> line)
    map.push_back(line);

  return map;
}

void print_moves()
{
  cout << "Insane!" << endl;
}
void print_error()
{
  cout << "Bad map configuration!" << endl;
}

bool play(map_t map, Movement movement)
{

}