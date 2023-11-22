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
