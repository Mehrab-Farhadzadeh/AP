#include <iostream>
#include <string>
using namespace std;

bool palindrome(string word);
// check palindromness form i to end
bool palindrome(string word, int i);

int main()
{
    string word;
    cout << "Please enter your words:\n\n";

    while (cin >> word)
    {
        if (palindrome(word))
            cout << word << " is palindrome." << endl;
        else
            cout << word << " ISN'T palindrome." << endl;
        cout << endl;
    }

    return 0;
}

bool palindrome(string word)
{
    return palindrome(word, 0);
}

bool palindrome(string word, int i)
{
    int size = word.size();

    if (i == size / 2)
        return (word[i] == word[size - i - 1]);

    if (word[i] == word[size - i - 1])
        return palindrome(word, i + 1);

    return false;
}