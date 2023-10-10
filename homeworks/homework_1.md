<!--
title: Homework 01
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

The goal of this assignment is to create a class implementing the concept of a Sparse Matrix. Storing all of its entries (zeros included) is not an option.

---

# How to organize your code
Your project should contain three files:
- `sparse_matrix.hpp`, containing the interface of your class,
- `sparse_matrix.cpp` with the actual implementation,
- `main.cpp` main file where you test the correctness of the implementation

## Compiling
Compile your code using the following [compilation flags](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html): 

  `g++ main.cpp sparse_matrix.cpp -std=c++17 -Wall -Wpendantic -o sparse_matrix`

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
- use the following signature for the member function implementing the matrix-vector product (notice the `void` return type and that the result is stored in `dst`)
  ```C+++
  void vmult(dst,src); //performs dst=M*src (`dst` and `src`: destination and source, respectively)
  ```
- use meaningful names that reflect the behaviour of the function.
- carefully decide which arguments of each member function should be const-qualified and which ones should not be.
- **Penalties will be assigned if const-correctness will not be guaranteed by your interface.**
---

# Implementation

## Storage schemes
The general idea is that we want to store only the nonzero entries of the matrix in such a way that we are able to perform common operations such as matrix-vector products. In this homework, you are asked to implement and validate two popular storage schemes: **Coordinate** format and **CSR**(compressed sparse row format). For the sake of clarity, let's consider the following matrix:

$$A =\begin{pmatrix}
0 & 0 & 3 & 0 & 4\\
0 & 0 & 5 & 0 & 7\\
0 & 0 & 0 & 0 & 0\\
0 & 2 & 0 & 6 & 0\\
\end{pmatrix}$$

### Coordinate format
  $A$ can be stored using three arrays of length *NNZ*:
  - An array containing all the nonzero values `(Value)`,
  - An array of integers containing their row indices `(Row)`,
  - An array of integers containing their column indices `(Column)`.

For the example at hand, we decide to store them *by row*:
  - `Value= [3,4,5,7,2,6]`
  - `Row =   [0,0,1,1,3]`
  - `Column=[2,4,2,4,1,3]`



### CSR
This format employs again three arrays to represent $A$:
  - An array containing all the nonzero values `(Value)` (length *NNZ*),
  - An array of integers containing their column indices `(Column)` (length *NNZ*),
  - An array of integers with the cumulative number of nonzero entries up to the i-th row (excluded) `(IA)`. The length of such array is $m+1$, being $m$ the number of rows of $A$.
  
  In such a way, the number of nonzero elements in the $i$-th row is: `IA[i+1]-IA[i]`. Notice that `IA[0]=0`. 

  $A$ is represented in the following way:
- `Value= [3,4,5,7,2,6]`
- `Column=[2,4,2,4,1,3]`
- `IA=[0,2,4,4,6]`
  
---

### What you are required to do:
1. Derive from the base class described above and write one class for each one of the storage schemes. Do this in `sparse_matrix.cpp`.
2. Implement the operations required by the interface for both storage schemes.
3. Provide a utility function in order to go back and forth from *Coordinate format* to *CRS*.

### Validation
Provide some tests (you can add them in `main.cpp`) in order to assess the correctness of your program. Here are some tips:
- if $v= \vec{1}$, then $$\bigl(M\vec v\bigr)_i=\sum_{j=1}^{n_{cols}} M[i][j] \underbrace{v[j]}_{1}=\sum_{j=1}^{n_{cols}} M[i][j]$$ (i.e. you get the sum of $i$-th row)

- if $v=\vec e_i$ ($i$-th vector of the canonical basis), then $$M \vec e_i = \text{i-th column of $M$}$$
- ... your choice!

- ***Bonus: templatize your class on the type of number stored by the matrix***