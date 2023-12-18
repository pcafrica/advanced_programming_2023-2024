#include <pybind11/pybind11.h>

#include <iostream>

// ----------------
// Regular C++ code
// ----------------

double multiply(double a, double b) {
  std::cout << "double" << std::endl;
  return a * b;
}

int multiply(int a, int b) {
  std::cout << "int" << std::endl;
  return a * b;
}

// ----------------
// Python interface
// ----------------

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
  m.doc() = "pybind11 example plugin";

  m.def("multiply", py::overload_cast<int, int>(&multiply));
  m.def("multiply", py::overload_cast<double, double>(&multiply));
}
