# Part 2: Programming exercise

## Objective
Create an advanced C++ library for matrix operations (like matrix multiplication, inversion, and determinant calculation) using object-oriented and generic programming paradigms. Integrate this library with Python using pybind11, and conduct a performance comparison between the C++ implementation and the Python-bound version.

---

## Tasks
1. **C++ codebase**
   1. Design a base `Matrix` class with common attributes.
   2. Create specialized classes (e.g., `SquareMatrix`, `DiagonalMatrix`) inheriting from the base class.
   3. Utilize templates to allow different data types (e.g., `float`, `double`, `complex`, ...).
   4. Implement functions for multiplication, inversion, and determinant calculation and whatever functionality you find relevant using class methods and/or friend functions.

2. **Configuration and compilation**
   1. Develop a CMake script for easy compilation of the C++ library.
   2. Provide clear instructions on compiling the library.

3. **Python bindings using pybind11**
   1. Bind the C++ functions, classes and their methods to Python.
   2. Ensure the Python interface is user-friendly and adheres to Python conventions.
   3. Create Python scripts to test the functionality of the matrix operations through the bindings.

4. **(Bonus) validation and comparison**
   1. Validate and compare the results against a Python library like NumPy.
   2. Design benchmarks to compare performance metrics between the C++ and Python implementations.
   3. Include tests with various matrix sizes and types.
