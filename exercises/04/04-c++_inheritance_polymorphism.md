<!--
title: Exercise session 04
paginate: true

_class: titlepage
-->

# Exercise session 04
<br>

## Inheritance and polymorphism in C++.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 19 Oct 2023

---

# Exercise: inheritance and polymorphism for data analysis

In the context of data analysis, create a C++ program that models different types of data sources and transformation objects.

1. Define an abstract class `DataSource` with attributes and methods that represent common properties of data sources. Create derived classes such as `FileDataSource` and `ConsoleDataSource`.
2. Define an abstract class `DataTransformer` with a virtual method for data transformation. Create derived classes such as `LinearScaler`, `LogTransformer`, and `StandardScaler` that implement specific data transformation methods.
3. Test all functionalities by prompting the user with proper questions.

---

# Exercise 1

1. Define an abstract class `DataSource` with a string attribute `name`, a vector `data`, a method `display_info()` and a pure virtual method `read_data()`.
2. Implement a constructor and a virtual destructor in the `DataSource` class with.
3. Create derived classes `FileDataSource` and `VectorDataSource` that inherit from `DataSource`.
4. Implement constructors for all classes to model different data source types. For example, `FileDataSource` should initialize a `filename` and an input file, `ConsoleDataSource` should have a default constructor.
2. Implement destructors for the derived classes. For example, the `FileDataSource` constructor should open the file, and its destructor should close it.

---

# Exercise 2

1. Implement the `read_data()` methods. `FileDataSource::read_data()` should import values from a file (see `data.txt` as an example), whereas `ConsoleDataSource::read_data()` should read a list of values from the standard input.
2. Create objects of these classes and demonstrate inheritance. For example, create a `FileDataSource` object and call `display_info()` and `read_data()` methods to read and display data from a file. 
3. Ensure that resources associated with data sources are properly managed during construction and destruction.

---

# Exercise 3

1. Define a base class `DataTransformer`, bound to `DataSource` by polymorphic composition. `DataTransformer` should have a pure virtual method `transform()` that transforms the `data` vector in the corresponding `DataSource`.
2. Create derived classes `LinearScaler`, `LogTransformer`, and `StandardScaler` that inherit from `DataTransformer`.
3. Override the `transform()` method in each derived class to provide specific data transformation. For example, `LinearScaler` scales the data by multiplying them by a given scaling factor, `LogTransformer` applies a logarithmic transformation and sets negative entries to `0`, and `StandardScaler` performs standardization to the $[0, 1]$ interval.

---

# Exercise 4

1. Use the `DataSource` and the `DataTransformer` hierarchy polymorphically. In particular, the program should prompt the user to import data either from a file or from console, and to select the transformation method.
2. Display the original and the transformed data.

---

# Extensions

1. In case a `FileDataSource` is selected, prompt the user to specify the filename from the console.
2. In case a `LinearScaler` is selected, prompt the user to specify the scaling factor from the console.
3. Add a new class to the `DataSource` hierarchy to import a given field from an input `CSV` file (see `data.csv` as an example).
4. Write a class or method to overwrite the original data from the text or `CSV` file with the transformed ones.
