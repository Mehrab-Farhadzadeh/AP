#include <iostream>
#include <vector>

using namespace std;

#define ASCII_CODE_OF_ZERO 48

int ch_to_digit(char ch);
bool is_charkheshi(string num_str);
bool is_all_seen_once(vector<bool> is_seen);
void print_result(bool result, int counter);

int main()
{
    for (int counter = 1;; counter++)
    {
        string num_str;
        cin >> num_str;
        if (num_str == "0")
            break;

        print_result(is_charkheshi(num_str), counter);
    }
    return 0;
}

int ch_to_digit(char ch)
{
    return (int)ch - ASCII_CODE_OF_ZERO;
}

bool is_charkheshi(string num_str)
{
    int size = num_str.size();
    vector<bool> is_seen(size, false);
    int next_digit_pos = 0;
    while (true)
    {
        int digit = ch_to_digit(num_str[next_digit_pos]);
        next_digit_pos = (next_digit_pos + digit) % size;
        if (is_seen[next_digit_pos])
            break;
        else
            is_seen[next_digit_pos] = true;
    }

    return is_all_seen_once(is_seen);
}

bool is_all_seen_once(vector<bool> is_seen)
{
    int size = is_seen.size();
    for (int state = 0; state < size; state++)
    {
        if (!is_seen[state])
            return false;
    }
    return true;
}

void print_result(bool result, int counter)
{
    cout << "Case " << counter << ": ";
    if (result)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}