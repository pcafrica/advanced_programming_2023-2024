#define STR_(x) #x
#define STR(x) STR_(x)

#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

#include <iostream>

#include <Eigen/LU>

// ------------------
// Regular C++ header
// ------------------

// A custom vector-class, with one method "multiply".
class CustomVectorXd {
public:
  CustomVectorXd(const Eigen::VectorXd &data);

  Eigen::VectorXd multiply(double factor = 1.);

private:
  Eigen::VectorXd m_data;
};

// ----------------
// Regular C++ code
// ----------------

// Class-constructor: store the input "Eigen::VectorXd".
CustomVectorXd::CustomVectorXd(const Eigen::VectorXd &data) : m_data(data) {}

// Return the custom vector, multiplied by a factor.
Eigen::VectorXd CustomVectorXd::multiply(double factor) {
  std::cout << "C++ bindings, version " << STR(VERSION_INFO) << std::endl;

  return factor * m_data;
}

// A function that has nothing to do with the class.
// The point is to show how one can return a "Eigen::VectorXd" by copy.
Eigen::VectorXi flip(const Eigen::VectorXi &array) {
  std::cout << "C++ bindings, version " << STR(VERSION_INFO) << std::endl;

  const auto N = array.size();

  Eigen::VectorXi out(N);

  for (auto i = 0; i < N; ++i)
    out[array.size() - i - 1] = array[i];

  return out;
}

// ----------------
// Python interface
// ----------------

namespace py = pybind11;

PYBIND11_MODULE(example_06_class_numpy_eigen, m) {
  m.doc() = "pybind11 example plugin";

  m.def("flip", &flip);

  // "__repr__()" or "__str__()" are invoked whenever print(array)
  // is called from Python on an object "array" of type "CustomVectorXd".
  py::class_<CustomVectorXd>(m, "CustomVectorXd")
      .def(py::init<Eigen::VectorXd>())
      .def("multiply", &CustomVectorXd::multiply, py::arg("factor") = 1.)
      .def("__repr__", [](const CustomVectorXd &a) {
        return "<example_06_class_numpy_eigen.CustomVectorXd>";
      });
}
