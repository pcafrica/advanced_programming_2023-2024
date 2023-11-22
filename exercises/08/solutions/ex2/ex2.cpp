#include <chrono>

#include "matrix.hpp"

int main(int argc, char **argv) {
  const size_t size = 2000;

  Matrix A(size);
  Matrix B(size);

  for (size_t i = 0; i < size; ++i) {
    A(i, i) = 10.0;
    A(i, size - 1) = 30.0;
    B(i, 0) = 1.0;
    B(i, i) = 3.0;
  }

  {
    const auto start = std::chrono::high_resolution_clock::now();
    const Matrix D = A.transpose();
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Transpose time: " << duration << " [ms] " << std::endl;
  }

  {
    const auto start = std::chrono::high_resolution_clock::now();
    const Matrix C = A * B;
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Multiply time: " << duration << " [ms] " << std::endl;
  }

  return 0;
}
