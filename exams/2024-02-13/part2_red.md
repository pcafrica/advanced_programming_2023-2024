# Part 2: Programming exercise

## Objective
Develop a solver for tridiagonal linear systems of equations using C++ and integrate it with Python through pybind11. This exercise involves writing code to describe a problem that needs solving and implementing the linear solver.

---

## Mathematical background

Consider a linear system of the form

$$
A\mathbf{u} = \mathbf{f}.
$$

### Method: Thomas algorithm
Thomas algorithm, also known as the tridiagonal matrix algorithm (TDMA), is a simplified form of Gaussian elimination that is specifically designed to efficiently solve tridiagonal systems of equations.

A tridiagonal system is one in which each row of the matrix `A` involves at most three elements: one on the diagonal, one immediately above the diagonal (superdiagonal), and one immediately below the diagonal (subdiagonal).

Consider a tridiagonal system of `n` linear equations, whose $i$-th row can be represented as:

```
a[i]*u[i-1] + b[i]*u[i] + c[i]*u[i+1] = f[i], for i = 0, 1, ..., n-1,
```

where:

- `a[i]` is the subdiagonal element, with `a[0]` being undefined,
- `b[i]` is the diagonal element,
- `c[i]` is the superdiagonal element, with `c[n-1]` being undefined,
- `u[i]` is the $i$-th element of the unknown vector,
- `f[i]` is the $i$-th element of the right-hand side vector.

The goal is to find the solution vector `u`.

The steps of the Thomas algorithm are:

```
// Step 1.
for i = 1 to n-1:
    m = a[i] / b[i-1]
    b[i] = b[i] - m * c[i-1]
    f[i] = f[i] - m * f[i-1]

// Step 2.
u[n-1] = f[n-1] / b[n-1]
   
for i = n-1 down to 1:
    u[i-1] = (f[i-1] - c[i-1] * u[i]) / b[i-1]
```

### Problem: Heat diffusion
The following equation can be used to model temperature diffusion in a 1D slab:

$$
-\frac{\mathrm{d}^2 u}{\mathrm{d}x^2} = f(x),
$$

where $u$ is the temperature, $x$ is the spatial variable, and $f(x) = -\sin(\pi x)$ represents the heat source term.

Consider the domain $[0, 1]$, with boundary conditions $u(0) = u(1) = 0$.

By dividing the domain into $N + 1$ equally spaced intervals, with $h=\frac{L}{N+1}$​ being the distance between two consecutive points, we obtain $N+2$ points $\lbrace{}x_i\rbrace{}_{i=0}^{N+1}$ such that $x_i = i h$. The value of the temperature $u_i$ at each point $i$ can be computed numerically by solving the following linear system of equations:

$$
A \mathbf{u} = \mathbf{f},
$$

where

$$
A = \begin{bmatrix}
1 & 0 & 0 & \cdots & \cdots & \cdots & \cdots & 0\\
1 & -2 & 1 & 0 & & & & \vdots\\
0 & 1 & -2 & 1 & \ddots & & & \vdots\\
\vdots & 0 & \ddots & \ddots & \ddots & \ddots & & \vdots\\
\vdots & & \ddots & \ddots & \ddots & \ddots & 0 & \vdots\\
\vdots & & & \ddots & 1 & -2 & 1 & 0\\
\vdots & & & & 0 & 1 & -2 & 1\\
0 & \cdots & \cdots  & \cdots & \cdots & 0 & 0 & 1\\
\end{bmatrix},
\quad
\mathbf{u} = \begin{bmatrix}
u_0 \\
u_1 \\
\vdots \\
u_{N+1}
\end{bmatrix},
\quad
\mathbf{f} = \begin{bmatrix}
0 \\
f(x_1) h^2 \\
f(x_2) h^2 \\
\vdots \\
f(x_N) h^2 \\
0
\end{bmatrix}.
$$

The above linear system is tridiagonal, thus it can be solved using the Thomas algorithm.

---

## Tasks

1. (5 points) **Implement an abstract `Matrix` class**:
   1. Implement an abstract `Matrix` class in C++, defining common matrix attributes and (possibly pure virtual) methods, such as getting the number of rows and columns, accessing elements, printing, and whatever functionality you find relevant using class methods and/or friend functions.
   2. Include a **pure virtual** method `std::vector<double> solve(const std::vector<double> &f)` that solves a linear system given a right-hand side $f$ and returns its solution.
   3. Derive a `TridiagonalMatrix` class from `Matrix`. Implement proper constructors to initialize it given the diagonal vectors `a`, `b`, and `c`. Override the `solve` method to implement the Thomas algorithm.

2. (3 points) **Solve the heat diffusion problem**:
   1. Create a class `HeatDiffusion` representing the heat diffusion problem and exposing its relevant parameters (domain, boundary conditions, forcing term).
   2. `HeatDiffusion` should create and store a `TridiagonalMatrix` object as a class member and use it to solve the heat equation.

3. (2 points) **Configuration and compilation**
   1. Develop a CMake script for easy compilation of the C++ library.
   2. Provide clear instructions on compiling the library.

4. (5 points) **Python bindings using pybind11**:
   1. Bind the C++ functions, classes and their methods to Python.
   2. Ensure the Python interface is user-friendly and adheres to Python conventions.
   3. Write a Python script that solves the heat equation using the provided C++ solver exposed through pybind11.
   
5. **(Bonus) `ThomasSolver` class development**:
   1. Use muParserX in `HeatDiffusion` to parse the functions $f(x)$ and $u_\mathrm{ex}(x)$ from input strings.
   2. Define `ThomasSolver` as a template class to allow it to work with any matrix type that supports the necessary operations (accessing elements, etc.). The template parameter represents the matrix type.
   3. Implement the Thomas algorithm within the `ThomasSolver` class, making sure the implementation does not assume anything specific about the matrix type beyond the necessary operations.
   4. Instantiate the `ThomasSolver` class with `TridiagonalMatrix` and with Eigen's `SparseMatrixXd` class.
   5. Use `setuptools` to setup the build process for the Python bindings.
   6. Write tests for both the C++ and the Python implementation.
