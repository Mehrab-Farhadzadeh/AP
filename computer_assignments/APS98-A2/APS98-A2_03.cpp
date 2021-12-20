#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define HERO 'o'
#define EMPTY '#'
#define ROCK '-'
#define U 0
#define R 1
#define D 2
#define L 3
#define DIR_MAX 4
#define ROW_MAX (int)map.size()
#define ROW_MIN 0
#define COL_MAX (int)map[0].size()
#define COL_MIN 0
#define END_POINT 1

struct Movement
{
  int row;
  int col;
  int dir;
};

vector<Movement> moves;
int map_print_counter = 0;

typedef vector<string> map_t;

map_t get_map();
bool play(map_t map);
void print_moves();
void print_error();
void print_map(map_t map);
bool can_hero_move(map_t map, Movement try_to_move);
void apply_movement(map_t &map, Movement movement);
void discard_movement(map_t &map, Movement movement);

int main()
{
  int row, col;
  cin >> row >> col;
  map_t map = get_map();

  if (play(map))
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
  int num_of_moves = moves.size();
  for (int move = 0; move < num_of_moves; move++)
  {
    cout << moves[move].row + 1 << " " << moves[move].col + 1 << " ";

    switch (moves[move].dir)
    {
    case U:
      cout << "U" << endl;
      break;

    case R:
      cout << "R" << endl;
      break;

    case D:
      cout << "D" << endl;
      break;

    case L:
      cout << "L" << endl;
      break;

    default:
      cerr << "ERROR printing moves!" << endl;
      cerr << "Unexpted direction." << endl;
      exit(-1);
      break;
    }
  }
}
void print_error()
{
  cout << "Bad map configuration!" << endl;
}

void print_map(map_t map)
{
  cout << endl
       << ++map_print_counter << endl;
  for (int line = 0; line < ROW_MAX; line++)
  {
    cout << map[line] << endl;
  }
  cout << endl;
  cin.get();
}

bool play(map_t map)
{
  int lefted_heros = 0;

  for (int row = 0; row < ROW_MAX; row++)
    for (int col = 0; col < COL_MAX; col++)
    {
      if (map[row][col] != HERO)
        continue;
      lefted_heros++;
      for (int dir = 0; dir < DIR_MAX; dir++)
      {
        Movement movement = {row, col, dir};
        if (can_hero_move(map, movement))
        {
          apply_movement(map, movement);
          // cout << endl
          //      << ++map_print_counter << endl;
          // print_moves();
          bool solved = play(map);
          discard_movement(map, movement);
          if (solved)
            return true;
          moves.pop_back();
        }
      }
    }

  return lefted_heros == END_POINT;
}

bool can_hero_move(map_t map, Movement try_to_move)
{
  switch (try_to_move.dir)
  {
  case U:
    if (try_to_move.row - 2 < ROW_MIN)
      break;
    if ((map[try_to_move.row - 2][try_to_move.col] == EMPTY) && (map[try_to_move.row - 1][try_to_move.col] == HERO))
      return true;
    break;

  case R:
    if (try_to_move.col + 2 >= COL_MAX)
      break;
    if ((map[try_to_move.row][try_to_move.col + 2] == EMPTY) && (map[try_to_move.row][try_to_move.col + 1] == HERO))
      return true;
    break;

  case D:
    if (try_to_move.row + 2 >= ROW_MAX)
      break;
    if ((map[try_to_move.row + 2][try_to_move.col] == EMPTY) && (map[try_to_move.row + 1][try_to_move.col] == HERO))
      return true;
    break;

  case L:
    if (try_to_move.col - 2 < COL_MIN)
      break;
    if ((map[try_to_move.row][try_to_move.col - 2] == EMPTY) && (map[try_to_move.row][try_to_move.col - 1] == HERO))
      return true;
    break;

  default:
    cerr << "ERROR finding hero movement!" << endl;
    cerr << "Unexpted direction." << endl;
    exit(-1);
    break;
  }
  return false;
}

void apply_movement(map_t &map, Movement movement)
{
  moves.push_back(movement);

  switch (movement.dir)
  {
  case U:
    map[movement.row][movement.col] = EMPTY;
    map[movement.row - 1][movement.col] = EMPTY;
    map[movement.row - 2][movement.col] = HERO;
    break;

  case R:
    map[movement.row][movement.col] = EMPTY;
    map[movement.row][movement.col + 1] = EMPTY;
    map[movement.row][movement.col + 2] = HERO;
    break;

  case D:
    map[movement.row][movement.col] = EMPTY;
    map[movement.row + 1][movement.col] = EMPTY;
    map[movement.row + 2][movement.col] = HERO;
    break;

  case L:
    map[movement.row][movement.col] = EMPTY;
    map[movement.row][movement.col - 1] = EMPTY;
    map[movement.row][movement.col - 2] = HERO;
    break;

  default:
    cerr << "ERROR aplying hero movement!" << endl;
    cerr << "Unexpted direction." << endl;
    exit(-1);
    break;
  }
}

void discard_movement(map_t &map, Movement movement)
{
  // moves.pop_back();

  switch (movement.dir)
  {
  case U:
    map[movement.row][movement.col] = HERO;
    map[movement.row - 1][movement.col] = HERO;
    map[movement.row - 2][movement.col] = EMPTY;
    break;

  case R:
    map[movement.row][movement.col] = HERO;
    map[movement.row][movement.col + 1] = HERO;
    map[movement.row][movement.col + 2] = EMPTY;
    break;

  case D:
    map[movement.row][movement.col] = HERO;
    map[movement.row + 1][movement.col] = HERO;
    map[movement.row + 2][movement.col] = EMPTY;
    break;

  case L:
    map[movement.row][movement.col] = HERO;
    map[movement.row][movement.col - 1] = HERO;
    map[movement.row][movement.col - 2] = EMPTY;
    break;

  default:
    cerr << "ERROR discarding hero movement!" << endl;
    cerr << "Unexpted direction." << endl;
    exit(-1);
    break;
  }
}