#include <iostream>
#include <cmath>
using namespace std;

void reverse_number_just_printble(int number);

int reverse_number(int number);
int tail(int number);
int head(int number);

int main()
{
    int number;
    cout << "Please enter a number: ";
    cin >> number;

    // reverse_number_just_printble(number);
    
    int reversed = reverse_number(number);
    cout << "reversed = " << reversed << endl;

    return 0;
}

int reverse_number(int number)
{
    if (number < 10)
        return number;

  return (reverse_number(tail(number)) * 10) + head(number);
}

int tail(int number)
{
    int numOfDigits = log10(number);
    return (number - (head(number) * pow(10, numOfDigits)));
}

int head(int number)
{
    int numOfDigits = log10(number);
    return (number / (int)pow(10, numOfDigits));
}

void reverse_number_just_printble(int number)
{
    if (number < 10)
    {
        cout << number;
        return;
    }
    cout << number % 10;
    reverse_number_just_printble(number / 10);
    return;
}