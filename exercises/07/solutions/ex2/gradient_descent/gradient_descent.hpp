#ifndef GRADIENT_DESCENT_HPP__
#define GRADIENT_DESCENT_HPP__

#include <vector>

class GradientDescent {
public:
  GradientDescent(const double &learning_rate, const double &tolerance,
                  const unsigned int &max_iterations)
      : learning_rate(learning_rate), tolerance(tolerance),
        max_iterations(max_iterations) {}

  void fit(const std::vector<double> &x, const std::vector<double> &y);
  double predict(const double &x) const;

private:
  double learning_rate;
  double tolerance;
  unsigned int max_iterations;

  double weight;
  double bias;
};

#endif /* GRADIENT_DESCENT_HPP__ */
