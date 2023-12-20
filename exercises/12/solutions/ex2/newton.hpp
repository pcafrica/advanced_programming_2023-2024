#ifndef NEWTON_HPP__
#define NEWTON_HPP__

#include <functional>

template <typename T> class NewtonSolver {
public:
  NewtonSolver(const std::function<T(const T &)> &f,
               const std::function<T(const T &)> &df, const T &x0,
               const double &tolerance = 1e-12,
               const unsigned int &max_iterations = 100);

  T solve();

private:
  const std::function<T(const T &)> f;
  const std::function<T(const T &)> df;
  const T x0;
  const double tolerance;
  const unsigned int max_iterations;
};

#endif /* NEWTON_HPP__ */
