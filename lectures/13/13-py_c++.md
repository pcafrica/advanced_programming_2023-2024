<!--
title: Lecture 13
paginate: true

_class: titlepage
-->

# Lecture 13
<br>

## Integrating C++ and Python codes.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 19 Dec 2023

---

# Outline

1. Integrating C++ and Python

2. pybind11
   - Installation
   - Basics
   - Binding object-oriented code

3. Building

3. Examples

Part of these notes is re-adapted from [the official pybind11 documentation](https://github.com/pybind/pybind11/tree/master/docs) ([license](LICENSE_pybind11.md)).

Part of the lecture examples is re-adapted from [this repository](https://github.com/tdegeus/pybind11_examples) ([license](LICENSE_pybind11_examples.md)).

---

<!--
_class: titlepage
-->

# Integrating C++ and Python

---

# Prova

---

<!--
_class: titlepage
-->

# pybind11: installation

---

# pybind11 overview

pybind11 is a lightweight, header-only library that connects C++ types with Python. This tool is crucial for creating Python bindings of existing C++ code. Its design and functionality are similar to the Boost.Python library but with a focus on simplicity and minimalism. Pybind11 stands out for its ability to avoid the complexities associated with Boost, a comprehensive suite of utility libraries, by leveraging C++11 features.

[Documentation link](https://pybind11.readthedocs.io/en/stable/index.html)

---

# How to install

There are multiple methods to acquire the pybind11 source, available on [GitHub](https://github.com/pybind/pybind11). The recommended approaches include via PyPI, through Conda, building from source, or importing it as a Git submodule.

## Include with PyPI

Pybind11 can be installed as a Python package from PyPI using Pip:

```bash
pip install pybind11
```

For direct availability in your environment root, use:

```bash
pip install "pybind11[global]"
```

This approach is advisable for virtual environments or within a `pyproject.toml` file, especially when using system Python, to avoid unwanted directory changes.

---

# How to install

## Include with conda-forge

Conda users can obtain pybind11 via conda-forge:

```bash
conda install -c conda-forge pybind11
```

## Global install with brew

For macOS and Linux users, the brew package manager offers pybind11. Install it using:

```bash
brew install pybind11
```

---

# How to install

## Build from source

If you prefer to build from source, use the following commands:

```bash
wget https://github.com/pybind/pybind11/archive/refs/tags/v2.11.1.tar.gz
tar xzvf v2.11.1.tar.gz

cd pybind11-2.11.1/
mkdir build && cd build

cmake .. -DCMAKE_INSTALL_PREFIX=/opt/pybind11
[sudo] make -j<N> install
```

---

# How to install

## Include as a submodule

For Git-based projects, pybind11 can be incorporated as a submodule. In your Git repository, execute the following commands:

```bash
git submodule add -b stable ../../pybind/pybind11 extern/pybind11
git submodule update --init
```

This method assumes dependency placement in `extern/`. If not using GitHub, substitute with the complete https or ssh URL. Remember, some servers might require the `.git` extension.

After setup, include `extern/pybind11/include` in your project, or employ pybind11's integration tools.

---

<!--
_class: titlepage
-->

# pybind11: basics

---

# First steps

This sections demonstrates the basic features of pybind11. Before getting
started, make sure that development environment is set up to compile the
included set of test cases.

# Compiling the test cases

1. Linux/macOS

On Linux  you'll need to install the **python-dev** or **python3-dev** packages as
well as **cmake**. On macOS, the included python version works out of the box,
but **cmake** must still be installed.

After installing the prerequisites, run

```bash
mkdir build
cd build
cmake ..
make check -j 4
```

---

The last line will both compile and run the tests.

1. Windows

On Windows, only **Visual Studio 2017** (MSVC 14.1) and newer are supported, adding the [`/permissive`](https://docs.microsoft.com/en-us/cpp/build/reference/permissive-standards-conformance?view=vs-2017) compiler flag

To compile and run the tests:

```batch
mkdir build
cd build
cmake ..
cmake --build . --config Release --target check
```

This will create a Visual Studio project, compile and run the target, all from the
command line.

---

# Note

If all tests fail, make sure that the Python binary and the testcases are compiled for the same processor type and bitness (i.e. either **i386** or **x86_64**). You can specify **x86_64** as the target architecture for the generated Visual Studio project using `cmake -A x64 ..`.

# Header and namespace conventions

For brevity, all code examples assume that the following two lines are present:

```cpp
#include <pybind11/pybind11.h>
namespace py = pybind11;
```

Some features may require additional headers, but those will be specified as needed.

---

# Creating bindings for a simple function

Let's start by creating Python bindings for an extremely simple function, which
adds two numbers and returns their result:

```cpp
int add(int i, int j) {
    return i + j;
}
```

For simplicity, we'll put both this function and the binding code into
a file named :file:`example.cpp` with the following contents:

---

```cpp
#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");
}
```

In practice, implementation and binding code will generally be located in separate files.

The `PYBIND11_MODULE` macro creates a function that will be called when an
`import` statement is issued from within Python. The module name (`example`)
is given as the first macro argument (it should not be in quotes). The second
argument (`m`) defines a variable of type `py::module_ <module>` which
is the main interface for creating bindings. The method `module_::def`
generates binding code that exposes the `add()` function to Python.

---

# Note

Notice how little code was needed to expose our function to Python: all details regarding the function's parameters and return value were automatically inferred using template metaprogramming. This overall approach and the used syntax are borrowed from Boost.Python, though the underlying implementation is very different.

pybind11 is a header-only library, hence it is not necessary to link against
any special libraries and there are no intermediate (magic) translation steps.
On Linux, the above example can be compiled using the following command:

```bash
c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) example.cpp -o example$(python3-config --extension-suffix)
```

---

# Note

If you used `include_as_a_submodule` to get the pybind11 source, then use `$(python3-config --includes) -Iextern/pybind11/include` instead of `$(python3 -m pybind11 --includes)` in the above compilation, as explained in `building_manually`.

For more details on the required compiler flags on Linux and macOS, see
`building_manually`. For complete cross-platform compilation instructions,
refer to the `compiling` page.

The `python_example`_ and `cmake_example`_ repositories are also a good place
to start. They are both complete project examples with cross-platform build
systems. The only difference between the two is that `python_example`_ uses
Python's `setuptools` to build the module, while `cmake_example`_ uses CMake
(which may be preferable for existing C++ projects).

python_example: https://github.com/pybind/python_example
cmake_example: https://github.com/pybind/cmake_example

Building the above C++ code will produce a binary module file that can be
imported to Python. Assuming that the compiled module is located in the
current directory, the following interactive Python session shows how to
load and execute the example:

```python
import example
example.add(1, 2)
```
> 3

---

# Keyword arguments

With a simple code modification, it is possible to inform Python about the
names of the arguments ("i" and "j" in this case).

```cpp
m.def("add", &add, "A function which adds two numbers",
      py::arg("i"), py::arg("j"));
```

`arg` is one of several special tag classes which can be used to pass
metadata into `module_::def`. With this modified binding code, we can now
call the function using keyword arguments, which is a more readable alternative
particularly for functions taking many parameters:

```python
import example
example.add(i=1, j=2)
```
> 3L

The keyword names also appear in the function signatures within the documentation.

```python
help(example)
```
> ...
> FUNCTIONS
>     add(...)
>         Signature : (i: int, j: int) -> int
> 
>         A function which adds two numbers

A shorter notation for named arguments is also available:

```cpp
// Regular notation.
m.def("add1", &add, py::arg("i"), py::arg("j"));
// Shorthand.
using namespace pybind11::literals;
m.def("add2", &add, "i"_a, "j"_a);
```

The :var:`_a` suffix forms a C++11 literal which is equivalent to `arg`.
Note that the literal operator must first be made visible with the directive
`using namespace pybind11::literals`. This does not bring in anything else
from the `pybind11` namespace except for literals.

---

# Default arguments

Suppose now that the function to be bound has default arguments, e.g.:

```cpp
int add(int i = 1, int j = 2) {
    return i + j;
}
```

Unfortunately, pybind11 cannot automatically extract these parameters, since they are not part of the function's type information. However, they are simple to specify using an extension of `arg`:

```cpp
m.def("add", &add, "A function which adds two numbers",
      py::arg("i") = 1, py::arg("j") = 2);
```

The default values also appear within the documentation.

```python
help(example)
```
> ....
> FUNCTIONS
>    add(...)
>        Signature : (i: int = 1, j: int = 2) -> int
>
>        A function which adds two numbers

The shorthand notation is also available for default arguments:

```cpp
// Regular notation.
m.def("add1", &add, py::arg("i") = 1, py::arg("j") = 2);
// Shorthand.
m.def("add2", &add, "i"_a=1, "j"_a=2);
```

# Exporting variables

To expose a value from C++, use the `attr` function to register it in a
module as shown below. Built-in types and general objects (more on that later)
are automatically converted when assigned as attributes, and can be explicitly
converted using the function `py::cast`.

```cpp
PYBIND11_MODULE(example, m) {
    m.attr("the_answer") = 42;
    py::object world = py::cast("World");
    m.attr("what") = world;
}
```

These are then accessible from Python:

```python
import example
example.the_answer # Output: 42
example.what # Output: 'World'
```

---

# Supported data types

A large number of data types are supported out of the box and can be used
seamlessly as functions arguments, return values or with `py::cast` in general.
For a full overview, see the :doc:`advanced/cast/index` section.

---

<!--
_class: titlepage
-->

# pybind11: binding object-oriented code

---

<!--
_class: titlepage
-->

# pybind11: building

---

# How to Compile

To compile C++ code with Pybind11, use the following command:
```bash
g++ -std=gnu++11 -O3 -shared -fPIC -isystem /path/to/pybind11/include $(python3-config --cflags --ldflags --libs) example.cpp -o example.so
```

Alternatively, you can use CMake with the provided `CMakeLists.txt`.

---

# How to Compile (using CMake) and run

To compile and run your Pybind11 code with CMake, follow these steps:
```bash
cd /path/to/example/
mkdir build && cd build
cmake -Dpybind11_DIR=${mkPybind11Prefix} ..
make
```
For running the compiled module, adjust your `PYTHONPATH` accordingly.

---

# Using `setup.py`

`setup.py` is a Python script commonly used in Python projects for tasks like building, distributing, and installing module packages. In Pybind11, it compiles and links C++ code into Python modules.

Below is a basic `setup.py` file structure for Pybind11:

```python
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys
import setuptools

class get_pybind_include(object):
    # Helper class to determine the pybind11 include path
    def __str__(self):
        import pybind11
        return pybind11.get_include()

ext_modules = [
    Extension(
        'your_module_name',  # Name of the module
        ['your_module.cpp'],  # C++ source files
        include_dirs=[
            get_pybind_include(),  # Path to pybind11 includes
            '/path/to/other/includes',  # Additional include paths
        ],
        language='c++'
    ),
]

setup(
    name='your_module_name',
    version='0.1',
    author='Your Name',
    author_email='your.email@example.com',
    description='A Python module using Pybind11',
    long_description='',
    ext_modules=ext_modules,
    install_requires=['pybind11>=2.5.0'],  # pybind11 requirement
    cmdclass={'build_ext': build_ext},
    zip_safe=False,
)
```

---

# Steps to use `setup.py`

1. **Create the `setup.py` file**: Place it in your project's root directory.

2. **Modify the file**: Change 'your_module_name' and 'your_module.cpp' to your module's name and C++ source file name. Adjust paths as needed.

3. **Build the module**:
   ```bash
   python setup.py build_ext --inplace
   ```
   This compiles the C++ code into a shared object file (.so).

4. **Install the module**:
   ```bash
   python setup.py install
   ```

---

# Notes

- Ensure Pybind11 and necessary libraries are installed.
- `get_pybind_include` locates the Pybind11 headers.
- Add complex compilation options or multiple C++ source files as needed.

---

<!--
_class: titlepage
-->

# Examples

---

# Benchmark

```bash
g++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` matrix_multiplication.cpp -o matrix_ops`python3-config --extension-suffix`
```

**Expected results**
Typically, the C++ implementation should be significantly faster than the pure Python implementation for several reasons:
- Execution Speed: C++ is a compiled language and is generally faster than Python, an interpreted language, especially for computation-intensive tasks.
- Optimization: Compilers for C++ can optimize the code for performance, whereas Python's flexibility and dynamic typing can introduce overhead.
- Handling of loops: C++ is more efficient in handling loops and arithmetic operations compared to Python.

---

# Notes

- The actual performance gain can vary depending on the system, the size of the matrices, and the compiler optimizations.
- For matrix operations, libraries like NumPy in Python are highly optimized and can offer performance close to C++, but in this comparison, we are using a pure Python implementation to illustrate the difference more clearly.
- Remember that developing and maintaining C++ code requires more effort compared to Python, so the decision to use C++ should consider both performance benefits and development costs.

---

# Examples

The examples provided are adapted and extended versions from [this GitHub repository](https://github.com/tdegeus/pybind11_examples). They demonstrate the use of Pybind11 in various scenarios. Remember to load the necessary modules, like Pybind11 and Eigen, before starting.

---

# Further readings

- [pybind11 documentation](https://pybind11.readthedocs.io/en/stable/)
- [Using pybind11](https://people.duke.edu/~ccc14/sta-663-2016/18G_C++_Python_pybind11.html)

---

<!--
_class: titlepage
-->

# :tada: That's all Folks!
