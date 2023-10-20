<!--
title: Lecture 05
paginate: true

_class: titlepage
-->

# Lecture 05
<br>

## Functions. Templates and generic programming in C++.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 24 Oct 2023

---

# Outline

1. Advanced topics on functions
   - Function pointers
   - Functors (function objects)
   - Lambda functions
   - Function wrappers (`std::function`)
2. Generic programming and templates

---

<!--
_class: titlepage
-->

# Advanced topics on functions

---

# Functions in C++

In C++, functions are categorized as free functions or member functions (methods) of a class. Subcategories exist for normal functions and template functions, including automatic return functions.

For a free, non-template function, the typical declaration syntax is as follows:

```cpp
return_type function_name(...);

auto function_name(...) -> return_type;

auto function_name(...);
```

The first two forms are essentially equivalent, so choose the one that suits your preference. In the third scenario, the compiler deduces the return type, which will be explained in more detail later.

---

# Function names and function identifiers

A function is **identified** by:

- Its **name**, `fun` in the previous examples. More precisely, its **fully qualified name**, which includes the namespace, for instance `std::transform`.
- The number and type of its **parameters**.
- The presence of the `const` qualifier (for methods).
- The type of the enclosing class (for methods).

Two functions with different identifiers are eventually treated as **different functions**, which is the key for **function overloading**.

**:warning: The return type is NOT part of the function identifier!**

---

# Why use free functions

A function represents a mapping from input data (via its arguments) to an output provided through the returned value or, in some cases, through an argument if the corresponding parameter is a non-const reference.

As a result, a free function is typically **stateless**, meaning that two different calls to a function with the same input will yield the same output. The only exception to this rule is when a local variable is declared `static`.

Hence, you typically implement a function when your requirement is indeed a straightforward input/output mapping, akin to the standard mathematical definition of a function, $f: U \rightarrow V$.

---

# What type does a function return

In rare instances, a function returns a reference to an object passed by reference. This is usually done when concatenation is desired, with the streaming operator being a typical example.

```cpp
std::ostream &operator<<(std::ostream &os, const MyClass &obj)
{
  // ...
  return os; // Return the stream.
}
```

This enables concatenation like so:

```cpp
std::cout << x << " concatenated with " << y;
```

---

# Default parameters

In the **declaration** of a function, you can provide default values for the rightmost parameters.

```cpp
std::vector<double> cross_prod(const std::vector<double> &a,
                               const std::vector<double> &b,
                               const unsigned int ndim = 2);
```

For instance:

```cpp
a = cross_prod(c, d); // This sets ndim to 2.
```

---

# A recall of function overloading

```cpp
int fun(int i);
double fun(const double &z);
// double fun(double y); // Error: ambiguous!
....
auto x = fun(1);       // Calls fun(int).
auto y = fun(1.0);     // Calls fun(const double &).
```

The function that gives the best match of the argument types is chosen. Beware of possible ambiguities and implicit conversions!

---

# Callable objects

A callable object refers to an object that can be called as if it were a function, i.e., using the function call operator `operator()`. Callable objects include:

- **Function pointers**.
- **Functors (function objects)**: Instances of classes that overload `operator()`.
- **Lambda functions**: Introduced in C++11, they are useful for short, local functions.
- **Member function pointers**: These allow you to call member functions of a class.
  ```cpp
  class MyClass {
  public:
    int add(int x, int y) { return x + y; }
  };
  int (MyClass::*add_member_func)(int, int) = &MyClass::add;
  MyClass obj;
  int result = (obj.*add_member_func)(3, 4);
  ```

---

<!--
_class: titlepage
-->

# Function pointers

---

# Pointers to functions

```cpp
double integrand(double x);

// Pointer to a function taking a double as an input and returning a double.
using f_ptr = double (*)(double);
// Or: typedef double (*f_ptr)(double);
double integrate(double a, double b, const f_ptr fun, unsigned n);

// Passing function as a pointer.
double I = integrate(0, 3.1415, integrand, 150);
// Assigning a function pointer.
f_ptr p_int = std::sin;
I = integrate(0, 3.1415, P_int, 150);
```

The name of the function is interpreted as a pointer to that function. However, you may precede it by `&`: `f_ptr f = &integrand`.

We will see in a while a safer and more general alternative to function pointers, the function wrapper `std::function` of the STL.

---

# Dynamic function selection

You can use function pointers to select and call functions at runtime based on user input or other conditions.

```cpp
int Add(int a, int b) { return a + b; }
int Subtract(int a, int b) { return a - b; }

int main() {
    int (*operation)(int, int); // 'operation' is a function pointer.

    if (user_input == "add") {
        operation = Add;
    } else {
        operation = Subtract;
    }

    const int result = operation(10, 5);  // Calls either Add or Subtract based on user input.

    return 0;
}
```

---

<!--
_class: titlepage
-->

# Functors (function objects)

---

# Functors (Function Object)

A **function object** or **functor** is a class object which overloads the **call operator** (`operator()`). It has semantics very similar to that of a function:

```cpp
class Cube {
public:
  double m = 1.0;
  double operator()(double const &x) const { return m * x * x * x; }
};

Cube cube{3.}; // A function object, cube.m = 3.
auto y = cube(3.4); // Calls Cube::operator()(3.4).
cube.m = 9; // Modify cube.m.
auto l = cube(3.4); // Again with a different m.
auto z = Cube{}(8.0); // I create the functor on the fly.
```

If the call operator returns a `bool`, the function object is a **predicate**. If a call to the call operator does not change the data members of the object, you should declare `operator()` as `const` (as with any other method).

---

# Why functors?

**A characteristic of a functor is that it may have a state**, so it can store additional information to be used to calculate the result.

```cpp
class Calculator {
public:
    int result = 0;
};

class Add {
public:
    Calculator& calc;
    Add(Calculator& c) : calc(c) {}
    void operator()(int x, int y) { calc.result = x + y; }
};

Calculator calc;
Calculator::Add add(calc);
add(5, 3); // Result is stored in calc.result;
```

---

# Predefined functors in the Standard Template Library

Under the header `<functional>`, you find a lot of predefined functors.

```cpp
std::vector<int> i = {1, 2, 3, 4, 5};

std::vector<int> j;

std::transform(i.begin(), i.end(),    // Source.
               std::back_inserter(j), // Destination.
               std::negate<int>());

const double prod = std::accumulate(i.begin(), i.end(), 1.0, std::multiplies<int>());
```

Now `j = {-1, -2, -3, -4, -5}.`.

`std::negate<type>` is a **unary functor** provided by the standard library.

`std::back_inserter<type>` inserts the transformed elements at the end (back) of vector `j`.

---

# Some predefined functors in the STL

| Functor           | Description                      |
|-------------------|----------------------------------|
| `plus<T>`, `minus<T>` | Addition/Subtraction (Binary) |
| `multiplies<T>`, `divides<T>` | Multiplication/Division (Binary)          |
| `modulus<T>`      | Modulus (Unary)                  |
| `negate<T>`       | Negative (Unary)                 |
| `equal_to<T>`, `not_equal_to<T>` | (Non-)Equality Comparison (Binary)     |
| `greater`, `less`, `greater_equal`, `less_equal` | Comparison (Binary) |
| `logical_and<T>`, `logical_or<T>`, `logical_not<T>` | Logical AND/OR/NOT (Binary)             |

For a full list, have a look at [this web page](https://cplusplus.com/reference/functional/).

---

<!--
_class: titlepage
-->

# Lambda functions

---

# Lambda expressions

We have a very powerful syntax to create short (and inlined) functions quickly: the lambda expressions (also called lambda functions or simply lambdas). They are similar to Matlab anonymous functions, like `f = @(x) x^2`.

```cpp
auto f = [] (double x) { return 3 * x; }; // f is a lambda function.

auto y = f(9.0); // y is equal to 27.0
```

Note that I did not need to specify the return type in this case, the compiler deduces it as `decltype(3 * x)`, which returns `double`.

---

# Capture specification

The capture specification allows you to use variables in the enclosing scope inside the lambda, either by value (a local copy is made) or by reference.

- `[]`: Captures nothing
- `[&]`: Captures all variables by reference
- `[=]`: Captures all variables by making a copy
- `[=, &foo]`: Captures any referenced variable by making a copy, but capture variable `foo` by reference
- `[bar]`: Captures only `bar` by making a copy
- `[this]`: Captures the `this` pointer of the enclosing class object
- `[*this]`: Captures a copy of the enclosing class object

---

# An example of use of `[this]`

With `[this]`, we get the `this` pointer to the calling object:

```cpp
class MyClass {
public:
    void compute() const {
        auto prod = [this](double a) { x *= a; };
        std::for_each(v.begin(), v.end(), prod);
    }
private:
    double x = 1.0;
    std::vector<double> v;
};

MyClass c;
double res = c.compute();
```

Here, `compute()` uses the lambda `prod` that **changes** the member `x`. To be more explicit, you can write `this->x *= a;`.

---

<!--
_class: titlepage
-->

# Function wrappers

---

# Function wrappers

And now the **catch all function wrapper**. The class `std::function<>` declared in `<functional>` provides polymorphic wrappers that generalize the notion of a function pointer. It allows you to use any **callable object** as **first-class objects**.

```cpp
int func(int, int); // A function.
class F2 { // A functor.
public:
    int operator()(int, int) const;
}

// A vector of functions.
std::vector<std::function<int(int, int)>> tasks;
tasks.push_back(func); // Wraps a function.
tasks.push_back(F2{}); // Wraps a functor.
tasks.push_back([](int x, int y){ return x * y; }); // Wraps a lambda.
for (auto i : tasks) std::cout << i(3, 4) << endl;
```

It prints the result of `func(3, 4)`, `F2{}(3, 4)`, and `12` ($3 \times 4$).

---

# Function wrappers

Function wrappers are **very useful** when you want to have a common interface to callable objects.

**Function wrappers introduce a little overhead**, since the callable object is stored internally as a pointer, but they are extremely flexible, and often the overhead is negligible.

---

<!--
_class: titlepage
-->

# Generic programming and templates

---

# SFINAE

---

<!--
_class: titlepage
-->

# :arrow_right: Templates and generic programming<br>Standard Template Library
