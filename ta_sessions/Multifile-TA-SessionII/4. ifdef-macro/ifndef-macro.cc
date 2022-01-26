// #define M

#include <iostream>

int main()
{
#ifndef M
  std::cout << "M had not been defined yet!" << std::endl;
#else
  std::cout << "M had been defined!" << std::endl;
#endif
}