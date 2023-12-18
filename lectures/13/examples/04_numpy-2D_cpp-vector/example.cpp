#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>

// ----------------
// Regular C++ code
// ----------------

std::vector<double> length(const std::vector<double> &pos) {
  size_t N = pos.size() / 2;

  std::vector<double> output(3 * N);

  for (size_t i = 0; i < N; ++i) {
    output[3 * i + 0] = pos[2 * i + 0];
    output[3 * i + 1] = pos[2 * i + 1];
    output[3 * i + 2] = std::sqrt(pos[2 * i + 0] * pos[2 * i + 0] +
                                  pos[2 * i + 1] * pos[2 * i + 1]);
  }

  return output;
}

// ----------------
// Python interface
// ----------------

namespace py = pybind11;

// Wrap C++ function with NumPy array IO.
py::array
py_length(const py::array_t<double, py::array::c_style | py::array::forcecast>
              &array) {
  // Check input dimensions.
  if (array.ndim() != 2)
    throw std::runtime_error("Input should be 2-D NumPy array");
  if (array.shape()[1] != 2)
    throw std::runtime_error("Input should have size [N,2]");

  // Allocate std::vector (to pass to the C++ function).
  std::vector<double> pos(array.size());

  // Copy py::array -> std::vector.
  std::memcpy(pos.data(), array.data(), array.size() * sizeof(double));

  // Call pure C++ function.
  std::vector<double> result = length(pos);

  ssize_t ndim = 2;
  std::vector<ssize_t> shape = {array.shape()[0], 3};
  std::vector<ssize_t> strides = {sizeof(double) * 3, sizeof(double)};

  // Return 2-D NumPy array.
  return py::array(
      py::buffer_info(result.data(),  /* Data as contiguous array. */
                      sizeof(double), /* Size of one scalar. */
                      py::format_descriptor<double>::format(), /* Data type. */
                      ndim,   /* Number of dimensions. */
                      shape,  /* Shape of the matrix. */
                      strides /* Strides for each axis. */
                      ));
}

// Wrap as Python module.
PYBIND11_MODULE(example, m) {
  m.doc() = "pybind11 example plugin";

  m.def("length", &py_length, "Calculate the length of an array of vectors");
}
