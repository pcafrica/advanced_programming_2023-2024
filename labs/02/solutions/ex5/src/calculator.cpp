#include "calculator.hpp"

#include <iostream>

namespace Calculator {
double add(const double &a, const double &b) { return a + b; }

double subtract(const double &a, const double &b) { return a - b; }

double multiply(const double &a, const double &b) { return a * b; }

double divide(const double &a, const double &b) {
  if (b == 0) {
    std::cerr << "Division by zero is not allowed." << std::endl;

    std::exit(1);
  }
  return a / b;
}
} // namespace Calculator
