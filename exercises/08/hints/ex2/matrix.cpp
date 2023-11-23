#include "matrix.hpp"
#include <cassert>

Matrix Matrix::transpose() const {
  std::cerr << "Error: Matrix::transpose not implemented." << std::endl;
  return Matrix(0);
}

Matrix operator*(const Matrix &A, const Matrix &B) {
  assert(A.n_cols() == B.n_rows());
  std::cerr << "Error: operator* not implemented." << std::endl;
  return Matrix(0);
}

std::vector<double> operator*(const Matrix &A, const std::vector<double> &x) {
  assert(A.n_cols() == x.size());

  std::vector<double> y(A.n_rows());

  for (size_t i = 0; i < y.size(); ++i)
    for (size_t j = 0; j < A.n_cols(); ++j)
      y[i] += A(i, j) * x[j];

  return y;
}
