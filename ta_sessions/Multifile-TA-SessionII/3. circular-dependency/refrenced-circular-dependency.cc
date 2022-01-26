#include <iostream>

// #include "A.hh"

// ** Question: Is Forward Declaration helpful? Answer:
class B;

class A
{
  B &b;
};

/*******************************************************************************/

// #include "B.hh"
class B
{
  int x;
  A a;
};

int main()
{
  std::cout << sizeof(A) << std::endl;
  return 0;
}