// #include "A.hh"

// ** Question: Is Forward Declaration helpful? Answer:
class B;

class A
{
  B b;
};

/*******************************************************************************/

// #include "B.hh"
class B
{
  A a;
};

int main() { return 0; }