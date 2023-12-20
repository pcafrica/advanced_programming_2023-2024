#include "newton.hpp"

#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(newton_solver, m) {
  py::class_<NewtonSolver<double>>(m, "NewtonSolverDouble")
      .def(py::init<const std::function<double(const double &)> &,
                    const std::function<double(const double &)> &,
                    const double &, const double &, const unsigned int &>(),
           py::arg("f"), py::arg("df"), py::arg("x0"),
           py::arg("tolerance") = 1e-12, py::arg("max_iterations") = 100)
      .def("solve", &NewtonSolver<double>::solve);

  py::class_<NewtonSolver<std::complex<double>>>(m, "NewtonSolverComplex")
      .def(py::init<const std::function<std::complex<double>(
                        const std::complex<double> &)> &,
                    const std::function<std::complex<double>(
                        const std::complex<double> &)> &,
                    const std::complex<double> &, const double &,
                    const unsigned int &>(),
           py::arg("f"), py::arg("df"), py::arg("x0"),
           py::arg("tolerance") = 1e-12, py::arg("max_iterations") = 100)
      .def("solve", &NewtonSolver<std::complex<double>>::solve);

  // Translate C++ exception to Python exception.
  py::register_exception<std::runtime_error>(m, "RuntimeError");
}
