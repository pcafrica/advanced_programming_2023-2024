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

<div class="columns">
<div>

1. 

2. pybind11

3. Live examples

</div>
<div>

4.

5. 

</div>
</div>

Part of these notes is re-adapted from [these lectures](http://github.com/jrjohansson/scientific-python-lectures) ([CC BY 3.0 DEED](https://creativecommons.org/licenses/by/3.0/) license).

---

<!--
_class: titlepage
-->

# Title

---

Pybind11 is a lightweight, header-only library that connects C++ types with Python. This tool is crucial for creating Python bindings of existing C++ code. Its design and functionality are similar to the Boost.Python library but with a focus on simplicity and minimalism. Pybind11 stands out for its ability to avoid the complexities associated with Boost, a comprehensive suite of utility libraries, by leveraging C++11 features.

[Documentation Link](https://pybind11.readthedocs.io/en/stable/index.html)

---

# Examples

The examples provided are adapted and extended versions from [this GitHub repository](https://github.com/tdegeus/pybind11_examples). They demonstrate the use of Pybind11 in various scenarios. Remember to load the necessary modules, like Pybind11 and Eigen, before starting.

---

# How to Compile

To compile C++ code with Pybind11, use the following command:
```bash
g++ -std=gnu++11 -O3 -shared -fPIC     -isystem /path/to/pybind11/include     $(python3-config --cflags --ldflags --libs)     example.cpp -o example.so
```

Alternatively, you can use CMake with the provided `CMakeLists.txt`.

---

# How to Compile (Using CMake) and Run

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

# Benchmark

c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` matrix_multiplication.cpp -o matrix_ops`python3-config --extension-suffix`

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


# Section


---

# How to setup `pybind11`

```bash
wget https://github.com/pybind/pybind11/archive/refs/tags/v2.11.1.tar.gz
tar xzvf v2.11.1.tar.gz
cd pybind11-2.11.1/
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/opt/pybind11
[sudo] make -j<N> install
```

---

# Further readings

- [pybind11 documentation](https://pybind11.readthedocs.io/en/stable/)

---

<!--
_class: titlepage
-->

# :arrow_right: Integrating C++ and Python codes.
