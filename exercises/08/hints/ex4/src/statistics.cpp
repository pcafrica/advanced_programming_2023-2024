#include "statistics.hpp"
#include <stdexcept>

double Statistics::mean(const std::vector<double> &data) {
  if (data.empty()) {
    throw std::runtime_error("Input data is empty.");
  }

  double sum = 0.0;
  for (const double &value : data) {
    sum += value;
  }

  return sum / data.size();
}
