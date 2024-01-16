# Part 1: Open-ended questions

## Question 1
In Object Oriented Programming, what is *polymorphism*? In C++, what is the difference between dynamic and static polymorphism?<br>
Provide a real-world example for at least one of the two techniques.

## Answer


---

## Question 2
Using template metaprogramming, write a C++ code that, without any use of `for` or `while` loops, prints the first 100 integer numbers.

## Answer


---

## Question 3
What is *move semantics* in C++? What is the meaning of *lvalue* and *rvalue* expressions, and how are they related to move semantics?<br>
Provide an example where move semantics might be beneficial.

## Answer


---

## Question 4
Given the following C++ code, which *unit tests* would you perform and why?

```cpp
class Geometry {
public:
    double calculate_circle_area(double radius) {
        if (radius < 0) {
            throw std::invalid_argument("Radius cannot be negative.");
        }
        return 3.14159 * radius * radius;
    }

    double calculate_rectangle_area(double length, double width) {
        if (length < 0 || width < 0) {
            throw std::invalid_argument("Length and width cannot be negative.");
        }
        return length * width;
    }
};
```

## Answer


---

## Question 5
What is the difference between local variables and cache variables in CMake? What are shell environment variables and how to access them from a CMake script?<br>
Provide some examples.

## Answer


---

## Question 6
Compare the two following Python functions. Which one is more *Pythonic*? Which one is more efficient and why?

```python
def square1(lst):
    result = []
    for i in lst:
        result.append(i * i)
    return result

def square2(lst):
    return [i * i for i in lst]
```

## Answer


---

## Question 7
In Python, what is the difference between positional and keyword arguments?<br>
How to enforce that a function receives an input parameter of a _given_ type (e.g., an integer or a string)?

## Answer


---

## Question 8
What is *context management* in Python and which methods should a class expose in order to be able to use it?

## Answer


---

## Question 9
Vectorize the following Python function that calculates the square of each element in a list, so that it can efficiently work with NumPy arrays.<br>
What are some advantages and disadvantages of the vectorized function?

```python
def square_elements(my_list):
    squared_list = []
    for item in my_list:
        squared_list.append(item ** 2)
    return squared_list
```

## Answer


---

## Question 10
Given the following compilation command, what is the meaning of each line/flag and what are they used for?

```bash
g++ \
    -std=c++11 \
    -O3 \
    -shared \
    -fPIC \
    $(python3 -m pybind11 --includes) \
    $(python3-config --cflags --ldflags --libs) \
    example.cpp \
    -o example$(python3-config --extension-suffix)
```

## Answer

