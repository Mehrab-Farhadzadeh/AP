#include <iostream>
using namespace std;

int sum_of_digits(int number);
int sum_of_digits_recursive(int number);

int main()
{
    int number;
    cout << "Please enter a number: ";
    cin >> number;

    int sum = sum_of_digits(number);
    cout << "Sum of its digits = " << sum << endl;

    sum = sum_of_digits_recursive(number);
    cout << "Sum of its digits(recursive) = " << sum << endl;

    return 0;
}

int sum_of_digits(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += (number % 10);
        number /= 10;
    }
    return sum;
}

int sum_of_digits_recursive(int number){
    
    if (number < 10)
        return number;
    return (number % 10) + sum_of_digits_recursive(number / 10);
}