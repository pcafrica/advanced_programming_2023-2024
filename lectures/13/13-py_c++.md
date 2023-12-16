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

# Benchmark

c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` matrix_multiplication.cpp -o matrix_ops`python3-config --extension-suffix`

Expected Results

Typically, the C++ implementation should be significantly faster than the pure Python implementation for several reasons:

    Execution Speed: C++ is a compiled language and is generally faster than Python, an interpreted language, especially for computation-intensive tasks.

    Optimization: Compilers for C++ can optimize the code for performance, whereas Python's flexibility and dynamic typing can introduce overhead.

    Handling of Loops: C++ is more efficient in handling loops and arithmetic operations compared to Python.

Notes

    The actual performance gain can vary depending on the system, the size of the matrices, and the compiler optimizations.
    For matrix operations, libraries like NumPy in Python are highly optimized and can offer performance close to C++, but in this comparison, we are using a pure Python implementation to illustrate the difference more clearly.
    Remember that developing and maintaining C++ code requires more effort compared to Python, so the decision to use C++ should consider both performance benefits and development costs.

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
