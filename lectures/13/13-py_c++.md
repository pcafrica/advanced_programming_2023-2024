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
