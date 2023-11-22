#include "statistics.hpp"
#include "gtest/gtest.h"
#include <stdexcept>

TEST(StatisticsTest, MeanEmptyVector) {
  const std::vector<double> data;
  // ...
}

TEST(StatisticsTest, MeanSingleElement) {
  const std::vector<double> data = {5.0};
  // ...
}

TEST(StatisticsTest, MeanMultipleElements) {
  const std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
  // ...
}

TEST(StatisticsTest, MeanWithNegativeValues) {
  const std::vector<double> data = {-1.0, 2.0, -3.0, 4.0, -5.0};
  // ...
}

TEST(StatisticsTest, MeanZero) {
  const std::vector<double> data = {-5.0, -4.0, -3.0, -2.0, -1.0,
                                    1.0,  2.0,  3.0,  4.0,  5.0};
  // ...
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
