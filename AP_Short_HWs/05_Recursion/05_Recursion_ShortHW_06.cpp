#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

bool palindrome(string str);
// check palindromness form i to end
bool palindrome(string str, int start, int end);

int main()
{
    string str = "this is cooool looooc si siht";

    if (palindrome(str))
        cout << '"' << str << '"' << " is palindrome." << endl;
    else
        cout << '"' << str << '"' << " ISN'T palindrome." << endl;

    return 0;
}

bool palindrome(string str)
{
    return palindrome(str, 0, str.size() - 1);
}

bool palindrome(string str, int start, int end)
{
    char left = tolower(str[start]), right = tolower(str[end]);

    if (start >= end)
        return (left == right);

    if (!isalpha(left))
        return palindrome(str, start + 1, end);
    if (!isalpha(right))
        return palindrome(str, start, end - 1);

    if (left == right)
        return palindrome(str, start + 1, end - 1);

    return false;
}
