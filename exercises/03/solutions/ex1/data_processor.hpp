#ifndef DATA_PROCESSOR_HPP__
#define DATA_PROCESSOR_HPP__

#include <algorithm>
#include <cassert>
#include <numeric>
#include <ostream>

class DataProcessor {
public:
  // Constructor.
  DataProcessor(const double *input_data, const unsigned int &input_size);

  // Copy constructor.
  DataProcessor(const DataProcessor &other);

  // Copy assignment operator.
  DataProcessor &operator=(const DataProcessor &other);

  // Destructor.
  ~DataProcessor() {
    --n_instances;
    delete[] data;
    data = nullptr;
  }

  // Sum operator.
  DataProcessor operator+(const DataProcessor &other) const;

  // Non-const access operator.
  double &operator[](const unsigned int &index) {
    assert(index >= 0 && index < size);
    return data[index];
  }

  // Const access operator.
  const double &operator[](const unsigned int &index) const {
    assert(index >= 0 && index < size);
    return data[index];
  }

  unsigned int n_elements() const { return size; }

  double min() const { return *std::min_element(data, data + size); };

  double max() const { return *std::max_element(data, data + size); };

  double compute_mean() const {
    const double sum = std::accumulate(data, data + size, 0.0);
    return sum / size;
  }

  double compute_std_dev() const;

  static unsigned int get_n_instances() { return n_instances; }

  friend std::ostream &operator<<(std::ostream &os, const DataProcessor &dp);

private:
  static unsigned int n_instances;

  unsigned int size;
  double *data;
};

double compute_correlation(const DataProcessor &dp1, const DataProcessor &dp2);

#endif /* DATA_PROCESSOR_HPP__ */
