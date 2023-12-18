#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>

std::vector<std::vector<double>>
matrix_multiply(const std::vector<std::vector<double>> &mat1,
                const std::vector<std::vector<double>> &mat2) {
  const size_t rows = mat1.size();
  const size_t cols = mat2[0].size();
  const size_t inner_dim = mat2.size();

  std::vector<std::vector<double>> result(rows, std::vector<double>(cols, 0));
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      for (size_t k = 0; k < inner_dim; ++k) {
        result[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }

  return result;
}

namespace py = pybind11;

PYBIND11_MODULE(matrix_ops, m) {
  m.def("matrix_multiply", &matrix_multiply,
        "A function which multiplies two NumPy matrices");
}
