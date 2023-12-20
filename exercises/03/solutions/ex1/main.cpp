#include "data_processor.hpp"
#include <iostream>

int main() {
  const double input1[] = {2.43, -0.86, 7.19, 4.57, 1.68, 9.32, 5.75};
  const double input2[] = {0.73, -0.45, 0.12, 0.88, -0.67, 0.34, -0.92};

  const DataProcessor dp1(input1, 7); // Testing constructor.

  const DataProcessor dp2 = dp1; // Testing copy constructor.

  DataProcessor dp3(input2, 7);
  dp3 = dp1; // Testing copy assignment operator.

  std::cout << "dp1: " << dp1 << std::endl;
  std::cout << "dp2: " << dp2 << std::endl;
  std::cout << "dp3: " << dp3 << std::endl;
  std::cout << "Number of elements in dp1: " << dp1.n_elements() << std::endl;
  std::cout << "Number of elements in dp2: " << dp2.n_elements() << std::endl;
  std::cout << "Number of elements in dp3: " << dp3.n_elements() << std::endl;

  std::cout << "Minimum value of dp1: " << dp1.min() << std::endl;
  std::cout << "Maximum value of dp1: " << dp1.max() << std::endl;
  std::cout << "Mean of dp1: " << dp1.compute_mean() << std::endl;
  std::cout << "Standard deviation of dp1: " << dp1.compute_std_dev()
            << std::endl;

  const DataProcessor dp4(input2, 7);
  std::cout << "dp4: " << dp4 << std::endl;
  {
    DataProcessor dp5 = dp1 + dp4;
    std::cout << "dp5: " << dp5 << std::endl;
    std::cout << "Minimum value of dp5: " << dp5.min() << std::endl;
    std::cout << "Maximum value of dp5: " << dp5.max() << std::endl;

    // Constant view, so that const version of operator[] is called as a
    // read access operator.
    const DataProcessor &dp5_const = dp5;
    std::cout << "dp5[3]: " << dp5_const[3] << std::endl;
    dp5[3] = 0.0;
    std::cout << "dp5[3]: " << dp5_const[3] << std::endl;
  }

  std::cout << "Number of DataProcessor instances: "
            << DataProcessor::get_n_instances() << std::endl;

  const double correlation = compute_correlation(dp1, dp4);
  std::cout << "Correlation between dp1 and dp4: " << correlation << std::endl;

  return 0;
}
