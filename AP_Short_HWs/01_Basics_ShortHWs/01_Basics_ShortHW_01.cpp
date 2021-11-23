#include <iostream>
using namespace std;

int main()
{
	double inch, cm;
	cout << "Please enter the number(inch): " << endl;
	cin >> inch;
	cm = inch * 2.54;
	cout << endl << inch << " inch = " << cm << " cm" << endl;
}