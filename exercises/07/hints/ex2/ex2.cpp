#include <exception>
#include <iostream>
#include <vector>

#include "gradient_descent.hpp"

int main() {
  // Create some data points.
  const std::vector<double> x = {1, 2, 3, 4, 5};
  const std::vector<double> y = {2, 4, 6, 8, 10};

  // Create a GradientDescent object.
  GradientDescent model(0.1, 1e-12, 1000);

  try {
    // Fit the model to the data.
    model.fit(x, y);
  } catch (const std::exception &exc) {
    std::cerr << "Error: " << exc.what() << std::endl;
    return 1;
  }

  // Make some predictions.
  for (const double &x_value : x) {
    const double prediction = model.predict(x_value);
    std::cout << "Prediction for x = " << x_value << ": " << prediction
              << std::endl;
  }

  return 0;
}
