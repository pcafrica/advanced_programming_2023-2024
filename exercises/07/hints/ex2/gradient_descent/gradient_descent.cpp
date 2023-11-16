#include "gradient_descent.hpp"
#include <exception>
#include <iostream>

void GradientDescent::fit(const std::vector<double> &x,
                          const std::vector<double> &y) {
  weight = 0;
  bias = 0;

  unsigned int i = 0;

  for (; i < max_iterations; ++i) {
    double loss = 0;
    for (size_t j = 0; j < x.size(); ++j) {
      const double prediction = weight * x[j] + bias;

      const double error = prediction - y[j];
      loss += error * error;

      weight += learning_rate * error * x[j];
      bias += learning_rate * error;
    }

    loss /= x.size();

    if (loss < tolerance) {
      break;
    }
  }

  if (i == max_iterations) {
    throw std::runtime_error("Gradient descent dit not converge!");
  }
}

double GradientDescent::predict(const double &x) const {
  return weight * x + bias;
}
