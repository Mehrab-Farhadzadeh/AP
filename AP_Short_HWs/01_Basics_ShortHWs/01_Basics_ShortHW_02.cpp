#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;

	cout << "Please enter your words: ";
	if (cin >> word)
	{
		cout << "[" << word;
	}

	while (cin >> word)
	{
		cout << ", ";
		cout << word;
	}

	cout << "]" << endl;
}