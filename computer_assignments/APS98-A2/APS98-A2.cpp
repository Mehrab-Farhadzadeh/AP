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

  for (int queue = 0; queue < queues.size(); queue++)
  {
    validate_and_print_queue(queues[queue]);
  }

    return 0;
}

vector<string> get_queues(void)
{

}

void validate_and_print_queue(string queue, int curr_pos)
{

}

void validate_and_print_queue(string queue)
{
  validate_and_print_queue(queue, 0);
}