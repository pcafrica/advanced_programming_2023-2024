#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

#include <Eigen/LU>

// ----------------
// Regular C++ code
// ----------------

Eigen::MatrixXd inv(const Eigen::MatrixXd &xs) { return xs.inverse(); }

double det(const Eigen::MatrixXd &xs) { return xs.determinant(); }

// ----------------
// Python interface
// ----------------

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
  m.doc() = "pybind11 example plugin";

  m.def("inv", &inv);

  m.def("det", &det);
}
