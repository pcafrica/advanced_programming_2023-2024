<!--
title: Exercise session 12
paginate: true

_class: titlepage
-->

# Exercise session 12
<br>

## Integrating C++ and Python codes.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 21 Dec 2023

---

# Exercise 1: binding classes and magic methods

Provide Python bindings using pybind11 for the code provided as the solution to exercise 1 from session 03.

1. Bind the `DataProcessor` class and its member functions. Using a lambda function, expose a constructor taking a Python list as an input, to be converted to a `std::vector` and invoking the actual constructor.
2. Provide Python bindings for the addition (`__add__`), the read (`__getitem__`) and write (`__setitem__`) access, and the output stream (`__str__`) operators.
3. Package the Python module with the compiled C++ library using `setuptools`.
4. Write a Python script to replicate the functionalities implemented in the `main.cpp` file.

---

# Exercise 2: binding polymorphic classes

Provide Python bindings using pybind11 for the code provided as the solution to exercise 2 from session 04.

# decorators, ... exceptions

---

# Exercise 3: binding class templates

Provide Python bindings using pybind11 for the code provided as the solution to exercise 2 from session 05.

---

# Exercise 4: binding with external libraries

1. Implement C++ functions using the Eigen library to perform matrix-matrix multiplication and matrix inversion.
2. Provide Python bindings using pybind11 for the code implemented.
3. Use CMake and `setuptools` to setup the build process.
4. Write a Python script to test the performance of the Eigen-based operations. Implement a `log_execution_time` decorator to print the execution time of a function.
5. Compare the execution time of these operations to equivalent operations in NumPy (e.g., `numpy.matmul` for multiplication and `numpy.linalg.inv` for inversion). Use a large matrix (e.g., $1000 \times 1000$) of random integers between 0 and 1000 for the test.
