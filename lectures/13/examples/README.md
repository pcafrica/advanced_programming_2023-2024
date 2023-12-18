# Examples

## [01_py-list-set-dict_cpp-vector-set-map](01_py-list-set-dict_cpp-vector-set-map)

This example features one function `modify` that takes a list (read-only), multiplies all entries by two, and returns it as a list of doubles (see [`example.cpp`](01_py-list-set-dict_cpp-vector-set-map/example.cpp)).

Also a template function creating a `std::map` given the lists of keys and values is shown.

From Python these functions are contained in a simple module `example` (see [`test.py`](01_py-list_cpp-vector/test.py)).

The purpose of this example is to show how to make a function accept a list/set, how to convert this to the standard C++ `std::vector`/`std::set`, and how to return a new `std::vector` or `std::map`. Note that the actual operation is not very important, it is the interface that is illustrated.

To compile, either employ CMake, whereby the compilation instructions are read from [`CMakeLists.txt`](01_py-list-set-dict_cpp-vector-set-map/CMakeLists.txt) by subsequently:

```bash
mkdir build && cd build
cmake ..
make
```

Or, compile directly using:

```bash
g++ -O3 -Wall -shared -std=c++11 -fPIC \
    $(python3 -m pybind11 --includes) \
    example.cpp -o example$(python3-config --extension-suffix)
```

Run the example by:

```bash
python3 test.py
```

In order to be able to import the compiled module in Python, add the folder containing your dynamic library to the environment variable `PYTHONPATH` accordingly.

## [02_py-nested-list_cpp-nested-vector](02_py-nested-list_cpp-nested-vector)

Same as the [previous example](#01_py-list-set-dict_cpp-vector-set-map), but with a nested list.

## [03_numpy-1D_cpp-vector](03_numpy-1D_cpp-vector)

A function `modify` that converts the entries from a one-dimensional array to integers, and then multiplies these entries by 10.

The purpose of this example is to show how to make a function accept a one-dimensional NumPy array, how to convert this to the standard C++ `std::vector`, and how to return a one-dimensional NumPy array. Note that the interface generated using pybind11 is so flexible that it even accepts list inputs on the Python side.

## [04_numpy-2D_cpp-vector](04_numpy-2D_cpp-vector)

One function `length`. This function accepts a 'matrix' in which comprises a list of 2-D position vectors, as rows. The result is again a 'matrix' with for each row the "x" and "y" position, and the length of the 2-D position vector.

## [05_numpy-2D_cpp-eigen](05_numpy-2D_cpp-eigen)

Two functions `det` and `inv` that use the Eigen library. 

The purpose of this example is to show how trivial the interaction between C++/Eigen and Python/NumPy is.

## [06_class-numpy-eigen](06_class-numpy-eigen)

A custom `CustomVectorXd` class with one function `multiply`. This class uses the Eigen library. It also includes a default argument.

Furthermore, this example has a function `flip` (totally unrelated to the custom `CustomVectorXd` class). It's purpose is to show how to return a new `Eigen::VectorXi` (or NumPy array).

## [07_cpp-overload-scalar](07_cpp-overload-scalar)

One overloaded function `multiply`. This function acts 'differently' if it is called with `int` arguments or `double` arguments. Notice that the default behavior of pybind11 is quite robust. When calling the function with one `int` and one `double` argument, the module will choose the `double` version of `multiply` (and will cast the `int` argument to a `double`).

To compile, make sure that at least the C++14 standard is used, for example by including `-std=c++14` as compiler argument.

## [08_cpp-overload-eigen](08_cpp-overload-eigen)

Similar to the [previous example](#08cpp-overload-eigen), but with Eigen arguments (i.e. NumPy arguments from the Python side).

To compile, make sure that at least the C++14 standard is used.

## [09_numpy_cpp-custom-matrix](09_numpy_cpp-custom-matrix)

This example includes a custom matrix class in C++ (in `matrix.hpp`). This class is coupled to a NumPy-array using a simple interface (in `pybind_matrix.hpp`). Consequently the functions (in `example.cpp`) do not necessitate any special wrapper code.

See also [this](https://stackoverflow.com/questions/42645228/cast-numpy-array-to-from-custom-c-matrix-class-using-pybind11) discussion of Stack Overflow.

## [10_enum](10_enum)

This example features a way to interface with an enumerator in C++. In principle the interface is straightforward but warrants a 'trick'. Here a submodule is used to be able to interact with the enumerator in the same way as in C++.

## [11_class-parent-child](11_class-parent-child)

This example contains a classical example where one or more classes are derived from a certain parent or template. This particular example contains two animals, a `Dog` and a `Cat`, that are both derived from a generic `Animal` class. There is a function `talk` that accepts the generic `Animal` and thus any of the derived classes. 
This particular case requires more involved interface, as is described in [the documentation](https://pybind11.readthedocs.io/en/stable/advanced/classes.html).
