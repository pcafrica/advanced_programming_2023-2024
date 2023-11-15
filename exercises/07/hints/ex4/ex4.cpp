#include <dlfcn.h>
#include <iostream>
#include <string>

int main() {
  // Load libfunctions.so.
  // ...

  // Prompt the user for the function to evaluate.
  std::string answer;
  std::cout << "cube, square or square_root: ";
  std::cin >> answer;

  // Load the proper symbol from libfunctions.so
  // auto fun = ...

  // Prompt the user for the value to evaluate the function at.
  double value;
  std::cout << "x = ";
  std::cin >> value;

  // Evaluate function and print result.
  const double result = fun(value);
  std::cout << answer << "(" << value << ") = " << result << std::endl;

  // Close libfunctions.so.
  // ...

  return 0;
}
