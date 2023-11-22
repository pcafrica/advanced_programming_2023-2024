#include "statistics.hpp"
#include "gtest/gtest.h"
#include <stdexcept>

TEST(StatisticsTest, MeanEmptyVector) {
  const std::vector<double> data;
  EXPECT_THROW(
      {
        try {
          Statistics::mean(data);
        } catch (const std::runtime_error &exc) {
          EXPECT_STREQ("Input data is empty.", exc.what());

          throw;
        }
      },
      std::runtime_error);
}

TEST(StatisticsTest, MeanSingleElement) {
  const std::vector<double> data = {5.0};
  EXPECT_EQ(5.0, Statistics::mean(data));
}

TEST(StatisticsTest, MeanMultipleElements) {
  const std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
  EXPECT_EQ(3.0, Statistics::mean(data));
}

TEST(StatisticsTest, MeanWithNegativeValues) {
  const std::vector<double> data = {-1.0, 2.0, -3.0, 4.0, -5.0};
  EXPECT_EQ(-0.6, Statistics::mean(data));
}

TEST(StatisticsTest, MeanZero) {
  const std::vector<double> data = {-5.0, -4.0, -3.0, -2.0, -1.0,
                                    1.0,  2.0,  3.0,  4.0,  5.0};
  EXPECT_EQ(0.0, Statistics::mean(data));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
