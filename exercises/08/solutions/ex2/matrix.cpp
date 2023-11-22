#include "matrix.hpp"
#include <cassert>

Matrix Matrix::transpose() const {
  Matrix result(n_cols(), n_rows());

  for (size_t i = 0; i < result.n_rows(); ++i) {
    for (size_t j = 0; j < result.n_cols(); ++j) {
      result(i, j) = (*this)(j, i);
    }
  }

  return result;
}

Matrix operator*(const Matrix &A, const Matrix &B) {
  assert(A.n_cols() == B.n_rows());

  Matrix result(A.n_rows(), B.n_cols());

  // for (size_t i = 0; i < result.n_rows(); ++i)
  //   for (size_t j = 0; j < result.n_cols(); ++j)
  //     for (size_t k = 0; k < A.n_cols(); ++k)
  //       result(i, j) += A(i, k) * B(k, j);

  const Matrix At = A.transpose();

  for (size_t i = 0; i < result.n_rows(); ++i)
    for (size_t j = 0; j < result.n_cols(); ++j)
      for (size_t k = 0; k < A.n_cols(); ++k)
        result(i, j) += At(k, i) * B(k, j);

  return result;
}

std::vector<double> operator*(const Matrix &A, const std::vector<double> &x) {
  assert(A.n_cols() == x.size());

  std::vector<double> y(A.n_rows());

  for (size_t i = 0; i < y.size(); ++i)
    for (size_t j = 0; j < A.n_cols(); ++j)
      y[i] += A(i, j) * x[j];

  return y;
}
