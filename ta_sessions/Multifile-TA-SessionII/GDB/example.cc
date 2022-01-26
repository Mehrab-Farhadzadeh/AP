#include <cstdlib>
#include <iostream>
#include <vector>

void g(std::vector<std::size_t> a) {
  int dummy_var = 10;
  dummy_var = 11;

  for (std::size_t i = 0; i < a.size(); ++i)
    std::cout << a[i] << std::endl;

  a[10000] = 10;
}

void f(std::vector<std::size_t> a) { g(a); }

int main() {
  std::vector<std::size_t> a(10);

  f(a);

  return 0;
}