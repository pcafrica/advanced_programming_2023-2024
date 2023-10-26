#include "newton.hpp"
#include <cmath>
#include <limits>

NewtonSolver::NewtonSolver(const /* ??? */ &f,
                           const  /* ??? */ &df,
                           const double &x0, const double &tolerance,
                           const unsigned int &max_iterations)
    : f(f), df(df), x0(x0), tolerance(tolerance),
      max_iterations(max_iterations) {}

double NewtonSolver::solve() {
  double x = x0;

  unsigned int it = 0;

  while (it < max_iterations) {
    // Update x.

    // Check convergence.

    ++it;
  }

  // Indicates failure to converge.
  return std::numeric_limits<double>::quiet_NaN();
}
