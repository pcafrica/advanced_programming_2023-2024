# Part 1: Open-ended questions

## Question 1
Describe the concept of RAII (Resource Acquisition Is Initialization) in C++. How does RAII help in resource management?<br>
Explain how smart pointers are useful in this context and provide a code example to illustrate RAII.

## Answer


---

## Question 2
What is the difference between deep copy, shallow copy, and move in C++?<br>
Provide an example where deep copy is necessary and when move is beneficial.

## Answer


---

## Question 3
What are *lambda expressions* in C++? How do they differ from regular functions and from functors?<br>
Provide an example where a lambda expression is used to sort a collection.

## Answer


---

## Question 4
Given the following C++ code, which *unit tests* would you perform and why?

```cpp
class StringUtils {
public:
    std::string to_uppercase(const std::string& input) {
        std::string result = input;
        std::transform(result.begin(), result.end(), result.begin(), std::toupper);
        return result;
    }

    bool is_palindrome(const std::string& input) {
        std::string reversed = input;
        std::reverse(reversed.begin(), reversed.end());
        return input == reversed;
    }
};
```

## Answer


---

## Question 5
What does the following C++ code snippet do? How is this technique called?<br>
How would you generalize it for non-integer (e.g., `double`) `Base` and/or `Exponent` values?

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
Compare the two following Python functions. Do they provide equivalent results?<br>
Which one is more Pythonic? Which one is more efficient and why?

```python
def filter1(lst):
    result = []
    for i in lst:
        if i % 2 == 0:
            result.append(i)
    return result

def filter2(lst):
    return [i for i in lst if i % 2 == 0]
```

## Answer


---

## Question 7
In Python, what is the difference between mutable and immutable types?<br>
How does this difference affect the behavior of functions that modify their arguments?

## Answer


---

## Question 8
Explain the concept of encapsulation in object-oriented programming.<br>
Provide examples illustrating how encapsulation is achieved in Python classes through the use of access modifiers.

## Answer


---

## Question 9
What is the purpose of the `__init__` method in Python classes? How does it differ from the `__new__` method?
Provide a real-world example.

## Answer


---

## Question 10
Consider the following `CMakeLists.txt` script.<br>
Explain the behavior of this script and identify any potential issues or side effects that may arise when configuring and building the project using CMake.

```cmake
cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_executable main.cpp)
target_link_libraries(my_executable PRIVATE some_library)

if (NOT DEFINED SOME_OPTION)
    message(FATAL_ERROR "SOME_OPTION is not defined!")
endif()

if (SOME_OPTION)
    message(STATUS "Option SOME_OPTION is enabled.")
else()
    message(STATUS "Option SOME_OPTION is disabled.")
endif()
```

## Answer

