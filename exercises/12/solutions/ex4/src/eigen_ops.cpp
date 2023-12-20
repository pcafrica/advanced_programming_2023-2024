#include "eigen_ops.hpp"

#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

using Eigen::MatrixXd;

MatrixXd matrix_multiply(const MatrixXd &m1, const MatrixXd &m2) {
  return m1 * m2;
}

MatrixXd matrix_invert(const MatrixXd &m) { return m.inverse(); }

// ----------------
// Python interface
// ----------------

namespace py = pybind11;

PYBIND11_MODULE(eigen_ops, m) {
  m.def("matrix_multiply", &matrix_multiply);
  m.def("matrix_invert", &matrix_invert);
}
