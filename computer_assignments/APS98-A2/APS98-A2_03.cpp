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

bool find_movement(string line, Movement movement);
void apply_movement(map_t map, Movement movement);
void discard_movement(map_t map, Movement movement);
bool is_there_move(map_t map);
int lefted_heros(map_t map);

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
  for (int line = 0; line < (int)map.size(); line++)
  {
    while(find_movement(map[line], movement))
    {
      apply_movement(map, movement);
      if(play(map, movement))
        return true;
      discard_movement(map, movement);
    }
  }

  if (is_there_move(map))
    play(map, movement);

  if (lefted_heros(map) == 1)
    return true;

  return false;
}