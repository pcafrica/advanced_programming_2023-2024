#include "newton.hpp"
#include <complex>
#include <functional>
#include <iostream>

int main() {
  // Function with real root: f(x) = x^2 - 1 = 0.
  {
    // Define function and its derivative.
    auto f = [](const double &x) { return x * x - 1.0; };
    auto df = [](const double &x) { return 2.0 * x; };

    // Create a NewtonSolver instance and find the root.
    const double x0 = 0.5;
    NewtonSolver<double> solver(f, df, x0);

    const double root = solver.solve();

    if (root != std::numeric_limits<double>::quiet_NaN()) {
      std::cout << "Approximate root: " << root << std::endl;
    } else {
      std::cout << "Failed to converge to a root." << std::endl;
    }
  }

  // Function with complex root: f(x) = x^2 + 1 = 0.
  {
    // Define function and its derivative.
    auto f = [](const std::complex<double> &x) { return x * x + 1.0; };
    auto df = [](const std::complex<double> &x) { return 2.0 * x; };

    // Create a NewtonSolver instance and find the root.
    const std::complex<double> x0{0.5, 0.5};
    NewtonSolver<std::complex<double>> solver(f, df, x0);

    const std::complex<double> root = solver.solve();

    if (root != std::numeric_limits<std::complex<double>>::quiet_NaN()) {
      std::cout << "Approximate root: " << root << std::endl;
    } else {
      std::cout << "Failed to converge to a root." << std::endl;
    }
  }

  return 0;
}
