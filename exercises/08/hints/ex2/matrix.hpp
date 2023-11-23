#ifndef MATRIX_HPP__
#define MATRIX_HPP__

#include <iostream>
#include <vector>

class Matrix {
public:
  Matrix(size_t size) : rows(size), cols(size), data(rows * cols, 0.0) {}

  Matrix(size_t rows, size_t cols)
      : rows(rows), cols(cols), data(rows * cols, 0.0) {}

  Matrix(const Matrix &) = default;

  size_t n_rows() const { return rows; }
  size_t n_cols() const { return cols; }

  const double &operator()(size_t i, size_t j) const {
    return data[sub2ind(i, j)];
  }

  double &operator()(size_t i, size_t j) { return data[sub2ind(i, j)]; }

  Matrix transpose() const;

private:
  const size_t rows;
  const size_t cols;
  std::vector<double> data;

  inline size_t sub2ind(const size_t ir, const size_t jc) const {
    return (ir + jc * rows);
  }
};

// Matrix-matrix product: C = A * B.
Matrix operator*(const Matrix &A, const Matrix &B);

// Matrix-vector product: y = A * x.
std::vector<double> operator*(const Matrix &A, const std::vector<double> &x);

#endif /* MATRIX_HPP__ */
