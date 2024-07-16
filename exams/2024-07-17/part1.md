# Part 1: Open-ended questions

## Question 1
In Bash scripting, explain the difference between using single quotes (`'`), double quotes (`"`), and backticks (`` ` ``) when working with strings and commands.<br>
Provide examples to illustrate each usage and explain when it is appropriate to use each type.

## Answer


---

## Question 2
Describe the concept of inheritance in object-oriented programming. How does inheritance promote code reuse in C++?<br>
Provide an example demonstrating the use of inheritance and explain its benefits.

## Answer


---

## Question 3
What is polymorphism in C++? How does it differ from method overloading?<br>
Provide a code example illustrating polymorphism and explain its use cases.

## Answer


---

## Question 4
Explain the role of constructors and destructors in C++ class design.<br>
Provide an example where a destructor is essential for resource management.

## Answer


---

## Question 5
What does the following C++ code snippet do? How is this technique called?<br>
How would you generalize it for non-integer (e.g., `double`) `Base` values?

```cpp
template <int Base, int Exponent>
struct Power {
    static const int value = Base * Power<Base, Exponent - 1>::value;
};

template <int Base>
struct Power<Base, 0> {
    static const int value = 1;
};
```

## Answer


---

## Question 6
In Python, what is the difference between lists and tuples?<br>

## Answer


---

## Question 7
Compare the two following Python functions. Do they provide equivalent results?<br>
Which one is more Pythonic? Which one is more efficient and why?

```python
def reverse1(lst):
    return lst[::-1]

def reverse2(lst):
    result = []
    for i in range(len(lst) - 1, -1, -1):
        result.append(lst[i])
    return result
```

## Answer


---

## Question 8
How does this difference affect their usage in programs?
Given the following Python code, which *unit tests* would you perform and why?

```python
class MathUtils:
    def add(self, a, b):
        return a + b

    def multiply(self, a, b):
        return a * b
```

## Answer


---

## Question 9
What is the purpose of the `super()` function in Python classes? How does it work in the context of multiple inheritance?<br>
Provide a real-world example.

## Answer


---

## Question 10
Explain how to handle function overloading when exposing C++ functions to Python using `pybind11`.<br>
Provide an example with a C++ class that has multiple overloaded methods.<br>
Show how to bind these methods using `pybind11` and demonstrate calling these overloaded methods from Python.

## Answer

