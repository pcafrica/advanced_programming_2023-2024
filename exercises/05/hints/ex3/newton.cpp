#include "newton.hpp"
#include <cmath>

NewtonSolver::NewtonSolver(const /* ??? */ &f, const /* ??? */ &df,
                           const double &x0, const double &tolerance = 1e-12,
                           const unsigned int &max_iterations = 100)
    : f(f), df(df), tolerance(tolerance), max_iterations(max_iterations) {}

double NewtonSolver::solve() {
  double x = x0;

  unsigned int it = 0;

  while (it < max_iterations) {
    // Update x.

    // Check convergence.

    ++it;
  }

  // Indicates failure to converge.
  return std::numeric_limits<T>::quiet_NaN();
}
