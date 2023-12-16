#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

py::array_t<double> matrix_multiply(const py::array_t<double> &mat1,
                                    const py::array_t<double> &mat2) {
  const py::buffer_info buf1 = mat1.request();
  const py::buffer_info buf2 = mat2.request();

  if (buf1.ndim != 2 || buf2.ndim != 2)
    throw std::runtime_error("Expected two-dimensional arrays.");

  if (buf1.shape[1] != buf2.shape[0])
    throw std::runtime_error("Incompatible matrix dimensions.");

  const size_t rows = buf1.shape[0];
  const size_t cols = buf2.shape[1];
  const size_t inner_dim = buf1.shape[1];

  py::array_t<double> result(rows * cols);
  const py::buffer_info buf_result = result.request();

  const double *const ptr1 = static_cast<double *>(buf1.ptr);
  const double *const ptr2 = static_cast<double *>(buf2.ptr);
  double *const ptr_result = static_cast<double *>(buf_result.ptr);

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      double sum = 0.0;
      for (size_t k = 0; k < inner_dim; ++k) {
        sum += ptr1[i * inner_dim + k] * ptr2[k * cols + j];
      }
      ptr_result[i * cols + j] = sum;
    }
  }

  result.resize({rows, cols});
  return result;
}

PYBIND11_MODULE(matrix_ops, m) {
  m.def("matrix_multiply", &matrix_multiply,
        "A function which multiplies two NumPy matrices");
}
