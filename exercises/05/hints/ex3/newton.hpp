#ifndef NEWTON_HPP__
#define NEWTON_HPP__

class NewtonSolver {
public:
  NewtonSolver(const /* ??? */ &f, const /* ??? */ &df, const double &x0,
               const double &tolerance = 1e-12,
               const unsigned int &max_iterations = 100);

  double solve();

private:
  const /* ??? */ f;
  const /* ??? */ df;

  const double x0;
  const double tolerance;
  const unsigned int max_iterations;
};

#endif /* NEWTON_HPP__ */
