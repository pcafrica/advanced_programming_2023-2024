#include "calculator.hpp"
#include <iostream>

int main() {
  char operation;
  double num1, num2, result;

  std::cout << "Enter two numbers: ";
  std::cin >> num1 >> num2;

  std::cout << "Choose an operation (+, -, *, /): ";
  std::cin >> operation;

  switch (operation) {
  case '+':
    result = Calculator::add(num1, num2);
    break;
  case '-':
    result = Calculator::subtract(num1, num2);
    break;
  case '*':
    result = Calculator::multiply(num1, num2);
    break;
  case '/':
    result = Calculator::divide(num1, num2);
    break;
  default:
    std::cerr << "Error: Invalid operation." << std::endl;
    return 1;
  }

  std::cout << "Result: " << result << std::endl;

  return 0;
}
