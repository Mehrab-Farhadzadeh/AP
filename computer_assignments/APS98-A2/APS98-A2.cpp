#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> get_queues(void);
void validate_and_print_queue(string queue, int curr_pos);
void validate_and_print_queue(string queue);

int main()
{
  vector<string> queues = get_queues();

  int queues_size = (int)queues.size();
  for (int queue = 0; queue < queues_size; queue++)
  {
    validate_and_print_queue(queues[queue]);
  }

    return 0;
}

vector<string> get_queues(void)
{
  vector<string> queues;
  string queue;
  while (cin >> queue)
    queues.push_back(queue);

  return queues;
}

void validate_and_print_queue(string queue, int curr_pos)
{
  if (curr_pos >= (int)queue.size() - 2)
  {
    if (queue[curr_pos] == queue[curr_pos + 1])
      cout << queue[curr_pos];
      else
      {
        cout << queue[curr_pos];
        cout << queue[curr_pos + 1];
      }
    cout << endl;
    return;
  }
  if (queue[curr_pos] == queue[curr_pos + 1])
  {
    validate_and_print_queue(queue, curr_pos + 1);
    return;
  }

  cout << queue[curr_pos];
  validate_and_print_queue(queue, curr_pos + 1);
}

void validate_and_print_queue(string queue)
{
  validate_and_print_queue(queue, 0);
}