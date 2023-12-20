#include "data_transformer.hpp"

#include <algorithm>
#include <cmath>

void LinearScaler::apply() const {
  std::cout << "Applying linear scaling by factor " << scaling_factor
            << std::endl;

  for (double &value : source.get_data()) {
    value *= scaling_factor;
  }
}

void LogTransformer::apply() const {
  std::cout << "Applying logarithmic transformation" << std::endl;

  for (double &value : source.get_data()) {
    if (value > 0) {
      value = std::log(value);
    } else {
      value = 0;
    }
  }
}

void StandardScaler::apply() const {
  std::cout << "Applying standardization" << std::endl;

  const double min_value =
      *std::min_element(source.get_data().begin(), source.get_data().end());
  const double max_value =
      *std::max_element(source.get_data().begin(), source.get_data().end());

  for (double &value : source.get_data()) {
    value = (value - min_value) / (max_value - min_value);
  }
}
