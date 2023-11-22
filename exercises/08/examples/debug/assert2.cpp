#include <cassert>
#include <iostream>

int non_negative_add(const int &x, const int &y) {
  assert(x >= 0);
  assert(y >= 0);

  return x + y;
}

int main(int argc, char **argv) {
  std::cout << non_negative_add(2, 2) << std::endl;
  std::cout << non_negative_add(2, -5) << std::endl;

  return 0;
}
