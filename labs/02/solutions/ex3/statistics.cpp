#include "statistics.hpp"
#include <algorithm>
#include <cmath>

namespace stat {
// Function to calculate the mean of a set of numbers.
double calculate_mean(const std::vector<double> &numbers) {
  double sum = 0.0;
  for (const double &num : numbers) {
    sum += num;
  }
  return sum / numbers.size();
}

// Function to calculate the median of a set of numbers.
double calculate_median(const std::vector<double> &numbers) {
  std::vector<double> sorted_numbers = numbers;
  std::sort(sorted_numbers.begin(), sorted_numbers.end());

  size_t size = sorted_numbers.size();
  if (size % 2 == 0) {
    // If the number of elements is even, average the middle two numbers.
    size_t mid = size / 2;
    return (sorted_numbers[mid - 1] + sorted_numbers[mid]) / 2.0;
  } else {
    // If the number of elements is odd, return the middle number.
    return sorted_numbers[size / 2];
  }
}

// Function to calculate the standard deviation of a set of numbers.
double calculate_standard_deviation(const std::vector<double> &numbers) {
  double mean = calculate_mean(numbers);
  double variance = 0.0;

  for (const double &num : numbers) {
    variance += (num - mean) * (num - mean);
  }

  return std::sqrt(variance / numbers.size());
}
} // namespace stat
