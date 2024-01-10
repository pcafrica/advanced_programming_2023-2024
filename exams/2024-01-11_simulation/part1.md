# Part 1: Open-ended questions

## Question 1
In a UNIX shell, what is the difference between the single pipe (`command1 | command2`) and the double pipe (`command1 || command2`) operators?<br>
Provide a minimal working example for each of the two.

## Answer


---

## Question 2
Which types of constructor can be defined for a C++ class?<br>
Provide some examples for a class representing a 3D tensor.

## Answer


---

## Question 3
Write a C++ function template called sum that accepts a half-open range $[begin, end)$ (as iterators) of int objects and returns the sum of the sequence.

## Answer


---

## Question 4
What is the meaning of the following C++ code?

```cpp
template <typename T, template <typename> class Container>
class ContainerWrapper {
private:
    Container<T> data;
};
```

How to instantiate a `ContainerWrapper` object?

## Answer


---

## Question 5
In C++, what are the key differences in behavior and usage when functions return values by direct value, by pointer, and by reference?

## Answer


---

## Question 6
What are the similarities and differences in object-oriented features between C++ and Python?<br>
How does the implementation of concepts like inheritance and polymorphism vary in these two languages?

## Answer


---

## Question 7
How does Boolean indexing work in NumPy for vectorized data selection?<br>
Give an example of filtering data in an array based on a condition.

## Answer


---

## Question 8
How to handle an exception in Python?<br>
Illustrate the syntax of rasing and catching exceptions with an example.

## Answer


---

## Question 9
The following Python code snippet is meant to create a list named `another_list` with elements 1 and 2.<br>
Find the error and fix it.

```python
def append_to_list(element, target_list=[]):
    target_list.append(element)
    return target_list

my_list = append_to_list(1)
another_list = append_to_list(2)
```

## Answer


---

## Question 10
How does pybind11 handle default arguments in C++ functions when exposed to Python?

## Answer

