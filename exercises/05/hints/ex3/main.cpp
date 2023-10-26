#include "newton.hpp"
#include <functional>
#include <iostream>
#include <limits>

int main() {
  // Function with real root: f(x) = x^2 - 1 = 0.
  {
    // Define function and its derivative.
    // ...

    // Create a NewtonSolver instance and find the root.
    const double x0 = 0.5;
    NewtonSolver solver(f, df, x0);

    const double root = solver.solve();

    if (root != std::numeric_limits<double>::quiet_NaN()) {
      std::cout << "Approximate root: " << root << std::endl;
    } else {
      std::cout << "Failed to converge to a root." << std::endl;
    }
  }

  return 0;
}
