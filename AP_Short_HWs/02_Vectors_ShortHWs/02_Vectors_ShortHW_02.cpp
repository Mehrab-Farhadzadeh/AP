#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> alphabets(26);
    for(int i = 0; i <alphabets.size(); i++)
    {
        alphabets[i] = 'A' + i;
    }
    
    return 0;
}