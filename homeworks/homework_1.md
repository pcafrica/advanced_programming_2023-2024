<!--
title: Lecture 02
paginate: true

_class: titlepage
-->

# Homework 1
<br>

## Implementation of a Sparse Matrix
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa, Marco Feder

###### Due date: TODO

---

<!--
_class: green
-->

# What is a sparse matrix?

Quoting from [Wikipedia](https://en.wikipedia.org/wiki/Sparse_matrix):

> [...] a *sparse matrix* or sparse array is a matrix in which most of the elements are zero.[1] There is no strict definition regarding the proportion of zero-value elements for a matrix to qualify as sparse but a common criterion is that the number of non-zero elements is roughly equal to the number of rows or columns. 

The goal of this assignment is to create a class implementing the concept of a Sparse Matrix. Storing all of the entries (zeros included) is not an option. (TODO: add example and show numbers)

---

# How to organize your code
Your project should contain three files:
- `sparse_matrix.hpp`, containing the interface of your class,
- `sparse_matrix.cpp` with the actual implementation,
- `main.cpp` main file where you test the correctness of the implementation

---

# Interface

You are required to implement an *abstract* base class `SparseMatrix` that provides an interface for the following functions:

- *Get* the number of rows
- *Get* the number of columns
- *Read* an element of the matrix
- *Write* an element of the matrix
- *Compute* the matrix-vector product with a given vector
- *Print* the matrix
- ... other utilities you may think are useful (if any)

Please stick to the following rules:

- use the header file `sparse_matrix.hpp` for the interface
- templatize your class on the type of numbers stored by the matrix
- use the following signature for the member function implementing the matrix-vector product (notice the `void` return type and that the result is stored in `dst`)
  ```C+++
  void vmult(dst,src); //performs dst=M*src (`dst` and `src`: destination and source, respectively)
  ```
- use meaningful names that reflect the behaviour of the function.
- decide which arguments of each member function should be const-qualified and which ones should not be.
**Penalties will be assigned if const-correctness will not be guaranteed by your interface.**

---

# Implementation
- Derive from the base class described above and provide an implementation in the source file `sparse_matrix.cpp`.
- //TODO: explain the idea. Each row described by a map[col_idx][value]. (or CRS)?

---

# How you compile and test your code

## Compiling
Compile your code using the following [compilation flags](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html): 

  `g++ main.cpp sparse_matrix.cpp -std=c++17 -Wall -Wpendantic -o sparse_matrix`
  

## Testing
Test the correctness of your program by checking the your matrix-vector products give expected results. Here are some tips:
- if $v= \vec{1}$, then $$\bigl(M\vec v\bigr)_i=\sum_{j=1}^{n_{cols}} M[i][j] \underbrace{v[j]}_{1}=\sum_{j=1}^{n_{cols}} M[i][j]$$ (i.e. you get the sum of $i$-th row)

- if $v=\vec e_i$ ($i$-th vector of the canonical basis), then $$M \vec e_i = \text{i-th column of $M$}$$
