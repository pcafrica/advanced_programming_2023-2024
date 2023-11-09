#include <iomanip>
#include <iostream>
#include <random>

int main() {
  // Initialize random number generator.
  std::random_device rd;
  std::default_random_engine gen(rd());
  std::uniform_real_distribution<double> distribution(0, 1);

  // Number of random points to generate.
  const unsigned int n_points = 1e7;
  unsigned int n_points_inside_circle = 0;

  for (unsigned int i = 0; i < n_points; ++i) {
    // Generate a random point.
    const double x = distribution(gen);
    const double y = distribution(gen);

    // Check if the point is inside the circle.
    if (x * x + y * y <= 1) {
      ++n_points_inside_circle;
    }
  }

  // Calculate the estimated value of π.
  const double estimated_pi = 4.0 * n_points_inside_circle / n_points;

  // Print the result.
  std::cout << "Estimated value of π: " << std::setprecision(16) << estimated_pi
            << std::endl;

  return 0;
}
