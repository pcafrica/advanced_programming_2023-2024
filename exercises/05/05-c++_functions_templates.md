<!--
title: Exercise session 05
paginate: true

_class: titlepage
-->

# Exercise session 05
<br>

## Inheritance and polymorphism in C++.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 27 Oct 2023

---

# Exercise 1: lambda functions

Starting from the `hints/ex1.cpp` source file, create a C++ program that calculates the total cost of a given a list of products.

1. Use `std::accumulate` to calculate the total cost of the products, passing a custom lambda function.

2. Display the results after each step to check for correctness.

---

# Exercise 2: function pointers, functors, and lambda functions

Starting from the `hints/ex2.cpp` source file, develop a library management system with search capabilities using lambdas and functors.

1. Using `std::sort`, sort the books:
   - In ascending order based on year, using a **function pointer** as a comparator.
   - In descending order based on year, using a **lambda function** as a comparator.
   - In ascending order based on the author name, using a **functor** as a comparator.

2. Using `std::copy_if`, fill the `filtered_books` variable by extracting from `books` only the books written by a specific author. Implement the search functionali using lambdas.

3. Display the results after each step to check for correctness.

---

# Exercise 3: function wrappers

Implement the Newton-Raphson method to approximate the root of a function.


---

# Exercise 4: templates



---

# Exercise 5: template metaprogramming

Use template metaprogramming to calculate the factorial of an integer at compile time.

1. Define a template class for calculating the factorial of an integer.

2. Instantiate the template for the integers 5, 7, and 10.

3. Use `static_assert` to ensure that values are computed at compile time rather than runtime.

4. Print the results of the factorials.

---

templates
variadic templates
explicit instantiation

---
