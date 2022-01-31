#include "functions.hpp"
#include <iostream>
using namespace std;

void error(string message) {
	cerr << message << endl;
	abort();
}