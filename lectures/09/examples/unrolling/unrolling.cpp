#include <chrono>
#include <iostream>

double sum1(double *data, const size_t &size) {
  double sum{0};
  for (size_t j = 0; j < size; ++j)
    sum += data[j];
  return sum;
}

double sum2(double *data, const size_t &size) {
  double sum{0}, sum1{0}, sum2{0}, sum3{0};
  size_t j;
  for (j = 0; j < (size - 3); j += 4) {
    sum += data[j + 0];
    sum1 += data[j + 1];
    sum2 += data[j + 2];
    sum3 += data[j + 3];
  }
  for (; j < size; ++j)
    sum += data[j];
  sum += sum1 + sum2 + sum3;
  return sum;
}

int main() {
  constexpr size_t size = 1e9;

  double *data = new double[size];

  {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "sum1 = " << sum1(data, size) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken by sum1: " << duration.count() << " milliseconds"
              << std::endl;
  }

  {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "sum2 = " << sum2(data, size) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken by sum2: " << duration.count() << " milliseconds"
              << std::endl;
  }

  delete[] data;

  return 0;
}
