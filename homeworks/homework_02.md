<!--
title: Homework 02
paginate: true

_class: titlepage
-->

# Homework 02
<br>

## Implementation of a Scientific Computing Toolbox
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa, Marco Feder

###### Due date: 03 Dec 2023

---

# Objective

Develop a toolbox in C++ covering various data science and scientific computing areas. Implement at least **2** out of the following **4** components of your choice.

## Components

1. **Statistics module**
2. **Interpolation module**
3. **Numerical integration module**
4. **ODE module**

Requirements and descriptions for each module are provided below.

---

# 1. Statistics module

Implement a module to perform statistical analyses on data imported from a `CSV` file and output relevant information to a file. Parse input and output filenames from the command line.

- Implement utilities for statistical operations like mean, median, standard deviation, variance, frequency count, classification, and correlation analyses.
- Implement iterators for seamless data traversal.
- Consider using `std::variant` for storing numerical or categorical data and `std::optional` for possibly missing/NA values.
- Choose a dataset from [Kaggle](https://www.kaggle.com/datasets/) and test your implementation on it.

---

# 2. Interpolation module

Implement a module to support [composite polynomial interpolation](https://en.wikipedia.org/wiki/Polynomial_interpolation).

- Implement a common interface for all kinds of interpolation. The interface should store a list of nodes over an interval $[a, b]$ and the corresponding function values.
- The implemented class(es) should expose a call operator returning the interpolated value at a given point.
- Test your implementation through practical examples. Showcase the accuracy, efficiency, and order of convergence of each method implemented.

---

# 3. Numerical integration module

Implement a module for approximating integrals using composite numerical integration formulas of the form
$$
\int_a^b f(x) dx \approx \sum_{i=1}^N w_i f(x_i),
$$
where $\{w_i\}$ and $\{x_i\}$ are proper quadrature weights and nodes, respectively.

- Consider methods such as the [midpoint rule, the trapezoidal rule, or Simpson's rule](https://math.umd.edu/~petersd/460/numint460.pdf).
- Test your implementation through practical examples. Showcase the accuracy, efficiency, and order of convergence of each method implemented.

---

# 4. ODE module

Implement a module for solving Ordinary Differential Equations (ODEs) using [explicit Runge-Kutta methods](https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods#Explicit_Runge%E2%80%93Kutta_methods), such as Forward Euler and RK4.

- The module should handle both scalar and vector ODE problems.
- Output the solution to a `CSV` file with header columns `time, out1, out2, ..., outN`.
- Test your implementation through practical examples. Showcase the accuracy, stability, efficiency, and order of convergence of each method implemented.

---

# General guidelines

- Emphasize the use of modern C++ features, including STL containers, algorithms, iterators, smart pointers, and other utilities.
- Utilize either run-time or compile-time polymorphism (i.e., class inheritance vs. templates) based on your preference, providing motivation for your choice.
- Write error-safe code and handle exceptions properly.
- Provide clear documentation of code design, algorithms, and decisions made.
- Promote code readability, modular design, and adherence to coding standards.
- The **2** modules implemented should be part of the same framework, sharing namespaces, styling, and common utilities. However, each should be compilable as a standalone library.
- Provide sample applications demonstrating the functionality of each module.

---

# Code organization

- Organize your implementation into subfolders and files with meaningful names.
- Whenever possible, separate function declarations and definitions into different files.
- Before submission, test your code against multiple compilers (see, e.g., [GodBolt](https://godbolt.org/)) and enable the following [compilation flags](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html): 
  ```bash
  -std=c++17 -Wall -Wextra -Wpendantic -Werror
  ```

# Integration of Third-party libraries

- Feel free to integrate relevant third-party libraries (e.g., [`Boost`](https://www.boost.org/), [`Eigen`](https://eigen.tuxfamily.org/index.php?title=Main_Page), [`muParserX`](https://beltoforion.de/en/muparserx/)) and showcase their synergy with your classes.
- Discuss considerations and challenges in using third-party libraries.

---

# Submission

- Include a README file stating clearly **which modules** you decided to implement, the **group members**, and each **individual contribution**.
- Provide clear instructions for building, running, and testing your implementation or, preferably, a working compilation script.
- Add useful comments in the source code.
- Submit a **single** compressed file (named `Homework_02_Surname1_Surname2.ext`) containing all source code, the README, and any other relevant files or third-party libraries.
