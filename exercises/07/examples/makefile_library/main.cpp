#include "math.hpp"
#include <iostream>

int main() {
  const int result_add = add(5, 3);
  const int result_multiply = multiply(4, 6);

  std::cout << "Addition result: " << result_add << std::endl;
  std::cout << "Multiplication result: " << result_multiply << std::endl;

  return 0;
}
