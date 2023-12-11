<!--
title: Lecture 12
paginate: true

_class: titlepage
-->

# Lecture 12
<br>

## Introduction to NumPy and SciPy for scientific computing. Data visualization. Introduction to pandas for data analysis.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 12 Dec 2023

---

# Outline

1. The role of Python in modern scientific computing

2. NumPy
   - Introduction
   - Creating and manipulating arrays
   - Linear and matrix algebra
   - Data processing and beyond

3. Overview of SciPy
   - Relationship between NumPy and SciPy
   - Core modules in SciPy
   - Interpolation with Scipy
   - Optimization with SciPy
   - Integration with SciPy
   - Solving differential equations with SciPy

4. Plotting
   - Overview of Matplotlib for plotting
   - Creating basic 2D plots using Matplotlib
   - Creating basic 3D plots using Matplotlib
   - Introduction to seaborn

---

<!--
_class: titlepage
-->

# The role of Python in modern scientific computing

---

# The role of Python in modern scientific computing

Slide 1: Title

    Title: "The Crucial Role of Python in Scientific Computing"
    Subtitle: "Empowering Scientific Discovery Through Python"

Slide 2: Introduction

    Opening Statement: "Python, a versatile programming language, has become a cornerstone in the realm of scientific computing."
    Key Points:
        Flexible and readable syntax.
        Broad ecosystem of libraries and tools.

Slide 3: Python's Versatility

    Key Message: "Python's flexibility accommodates a wide range of scientific disciplines."
    Examples:
        Physics, biology, chemistry, astronomy, and more.
        Adaptability for diverse scientific tasks.

Slide 4: Widely Adopted Libraries

    Key Message: "Python owes much of its scientific prowess to its rich library ecosystem."
    Examples:
        NumPy, SciPy, and Pandas for data manipulation.
        Matplotlib and Seaborn for visualization.
        TensorFlow and PyTorch for machine learning.

Slide 5: Accessibility for Researchers

    Key Message: "Python lowers entry barriers for researchers and scientists."
    Points to Highlight:
        Easy to learn and teach.
        Readable syntax enhances collaboration.
        Extensive documentation and community support.

Slide 6: Open Source Collaboration

    Key Message: "Python thrives on collaboration within the open-source community."
    Highlights:
        Crowdsourced development and improvement.
        Shared libraries and tools benefit the entire community.
        Encourages transparency and innovation.

Slide 7: Reproducibility and Workflow

    Key Message: "Python facilitates reproducible and streamlined workflows."
    Key Features:
        Jupyter Notebooks for interactive and documented analysis.
        Integration with version control systems.
        Seamless transition from research to production.

Slide 8: Scalability and Performance

    Key Message: "Python's performance capabilities meet the demands of scientific computing."
    Points to Emphasize:
        NumPy and SciPy optimizations.
        Integration with high-performance computing (HPC) environments.
        Interface with compiled languages for critical sections.

Slide 9: Real-world Applications

    Key Message: "Python plays a pivotal role in groundbreaking scientific applications."
    Examples:
        Simulations, data analysis, image processing.
        Climate modeling, drug discovery, and genomic research.

Slide 10: Conclusion

    Closing Statement: "Python's impact on scientific computing is profound and continues to shape the future of research and discovery."
    Call to Action: "Explore the dynamic world of Python in scientific computing and join the community driving innovation."
    
---

<!--
_class: titlepage
-->

# NumPy

---

# Introduction

The `NumPy` module plays a crucial role in Python's numerical computation, providing high-performance structures for vectors, matrices, and multidimensional data. Implemented in C and Fortran, it excels in vectorized operations, showcasing superior performance.

To utilize `NumPy`, import the module, such as:

```python
import numpy as np
```

Within the `NumPy` package, arrays represent vectors, matrices, and higher-dimensional datasets.

---

# Creating `NumPy` arrays

Initializing `NumPy` arrays can be achieved through various methods:

- Conversion from Python lists or tuples.
- Utilizing dedicated array-generating functions such as `np.arange`, `np.linspace`, etc.
- Reading data from external files.

---

# From lists

For instance, creating vector and matrix arrays from Python lists is accomplished using the `np.array` function:

```python
# A vector: the argument is a Python list.
v = np.array([1, 2, 3, 4])

# A matrix: the argument is a nested Python list.
M = np.array([[1, 2], [3, 4]])
```

Both `v` and `M` are instances of the `ndarray` type provided by the `NumPy` module.

---

# Array shape

Distinguishing between array shapes can be done using the `ndarray.shape` property:

```python
v.shape
```

> (4,)

```python
M.shape
```

> (2, 2)

---

# Lists vs. NumPy arrays

While `NumPy.ndarray` may seem similar to Python lists, using Python lists for numerical computations is suboptimal due to their generality and dynamic typing. In contrast, `NumPy` arrays are statically typed, homogeneous, memory-efficient, and support efficient mathematical operations implemented in compiled languages like C and Fortran.

---

# `dtype` (1/2)

The `dtype` (data type) property reveals the type of an array's data:

```python
M.dtype
```

> dtype('int64')

Attempting to assign an incompatible type raises an error:

```python
M[0, 0] = "hello"
```

> ValueError: invalid literal for long() with base 10: 'hello'

---

# `dtype` (2/2)

Explicitly defining the array data type during creation is possible using the `dtype` keyword argument:

```python
M = np.array([[1, 2], [3, 4]], dtype=complex)
```

Common data types for `dtype` include `int`, `float`, `complex`, `bool`, and others. Additionally, bit sizes like `int64`, `int16`, `float128`, and `complex128` can be specified.

---

# Using array-generating functions (1/2)

For larger arrays, manual initialization becomes impractical, leading to the use of array-generating functions in `NumPy`:

```python
x = np.arange(0, 10, 1)  # Arguments: start, stop, step.

# Using linspace, where both end points are included.
x = np.linspace(0, 10, 25)

x = np.logspace(0, 10, 10, base=np.e)

x, y = np.mgrid[0:5, 0:5]  # Similar to 'meshgrid' in MATLAB.
```

---

# Using array-generating functions (2/2)

Additional array-generating functions include random number generation, diagonal matrices, zeros, and ones:

```python
np.random.rand(5, 5)  # Uniform random numbers in [0, 1].
np.random.randn(5, 5)  # Standard normal distributed random numbers.
np.diag([1, 2, 3])  # Diagonal matrix.
np.diag([1, 2, 3], k=1)  # Diagonal with an offset from the main diagonal.
np.zeros((3, 3))
np.ones((3, 3))
```

---

# File I/O (1/2)

## Comma-separated values (CSV)

Reading data from comma-separated values (CSV) files into `NumPy` arrays is accomplished using `np.genfromtxt`:

```python
data = np.genfromtxt('filename.csv')
data.shape
```

Storing a `NumPy` array to a CSV file can be done with `np.savetxt`:

```python
M = random.rand(3, 3)
np.savetxt("random-matrix.csv", M)
np.savetxt("random-matrix.csv", M, fmt='%.5f')  # fmt specifies the format.
```

---

# File I/O (2/2)

## NumPy's native file format

`NumPy` provides its own file format for storing and reading array data using `np.save` and `np.load`:

```python
np.save("random-matrix.npy", M)

np.load("random-matrix.npy")
```

---

# Manipulating arrays

## Indexing

Array elements are accessed using square brackets and indices for reading and writing:

```python
# v is a vector, taking one index.
v[0]

# M is a matrix, taking two indices.
M[1, 1]

# Omitting an index returns the whole row or a N-1 dimensional array.
M[1]

M[1, :]  # Row 1.
M[:, 1]  # Column 1.
```

---

# Index slicing

Index slicing (`M[lower:upper:step]`) extracts portions of an array:

```python
A = np.array([1, 2, 3, 4, 5])
A[1:3]
A[0:2] = [-2, -3]

A[::]  # Lower, upper, and step default to the beginning, end, and 1.
A[::2]  # Step is 2, lower and upper default to the beginning and end.
A[:3]  # First three elements
A[3:]  # Elements from index 3

# Negative indices count from the end of the array.
A[-1]  # The last element in the array.
A[-3:]  # The last three elements.
```

---

# Fancy indexing

Fancy indexing involves using an array or list in place of an index:

```python
row_indices = [1, 2, 3]
A[row_indices]

col_indices = [1, 2, -1]
A[row_indices, col_indices]
```

Index masks, arrays of type `bool`, can also be used to select elements:

```python
mask = np.array([True, False, True])
A[mask]

x = np.arange(0, 10, 0.5)
mask = (5 < x) * (x < 7.5)
x[mask]
```

---

# Linear algebra (1/2)

Efficient numerical calculations with Python/NumPy rely on **vectorizing** code, emphasizing matrix and vector operations like matrix-matrix multiplication.

## Scalar-array operations

Arithmetic operators are employed for scalar-array operations:

```python
v1 = np.arange(0, 5)
v1 * 2
v1 + 2
A * 2
A +2
```

---

# Linear algebra (2/2)

## Element-wise array-array operations

When we add, subtract, multiply and divide arrays with each other, the default behavior is **element-wise** operations:

```python
A * A
v1 * v1
```

If we multiply arrays with compatible shapes, we get an element-wise multiplication of each row:

```python
A * v1
```

---

# Matrix algebra (1/2)

What about matrix multiplication? There are two ways. We can either use the `dot` function, which applies a matrix-matrix, matrix-vector, or inner vector multiplication to its arguments:

```python
np.dot(A, A)
np.dot(A, v1)
np.dot(v1, v1)
```

Alternatively, we can cast the array objects to the type `matrix`. This changes the behavior of the standard arithmetic operators `+`, `-`, `*` to use matrix algebra.

```python
M = np.matrix(A)
v = np.matrix(v1).T  # Make it a column vector.
M * M
M * v
v.T * v  # Inner product.
v + M * v
```

---

# Matrix algebra (2/2)

## Inverse and determinant

```python
np.linalg.inv(M)  # Same as M.I.
M.I * M

np.linalg.det(M)
np.linalg.det(M.I)
```

---

# Data processing

NumPy provides various functions to calculate statistics of datasets in arrays. Here are some examples:

```python
np.mean(data[:, 3])
np.std(data[:, 3]), np.var(data[:, 3])
np.min(data[:, 3])
np.max(data[:, 3])

np.sum(d)  # Sum up all elements.
np.prod(d + 1)  # Product of all elements.
np.cumsum(d)  # Cumulative sum.
np.cumprod(d + 1)  # Cumulative product.

np.trace(A)  # Same as: np.diag(A).sum()
```

---

# Calculations with higher-dimensional data

When functions such as `min`, `max`, etc. are applied to multidimensional arrays, it is sometimes useful to apply the calculation to the entire array or on a row or column basis. Using the `axis` argument, we can specify how these functions should behave:

```python
M = random.rand(3, 3)

m.max()  # Global max.
m.max(axis=0)  # Max in each column.
m.max(axis=1)  # Max in each row.
```

Many other functions and methods in the `array` and `matrix` classes accept the same (optional) `axis` keyword argument.

---

# Reshaping, resizing, and stacking arrays

The shape of a NumPy array can be modified without copying the underlying data, making it a fast operation even for large arrays:

```python
A
n, m = A.shape
B = A.reshape((1, n * m))

B[0, 0:5] = 5  # Modify the array.
A  # The original variable is also changed. B is only a different view of the same data.
```

We can also use the function `flatten` to make a higher-dimensional array into a vector. But this function creates a copy of the data:

```python
B = A.flatten()
B[0:5] = 10
```

---

# Adding a new dimension: `newaxis`

With `newaxis`, we can insert new dimensions in an array, for example converting a vector to a column or row matrix:

```python
v = np.array([1, 2, 3])
np.shape(v)
```

> (3,)

```python
# Make a column matrix of the vector v.
v[:, np.newaxis]
```

---

# Stacking and repeating arrays (1/2)

Using functions `repeat`, `tile`, `vstack`, `hstack`, and `concatenate`, we can create larger vectors and matrices from smaller ones:

```python
a = np.array([[1, 2], [3, 4]])
# Repeat each element 3 times.
np.repeat(a, 3)
```

> array(\[1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4])

```python
# Tile the matrix 3 times.
np.tile(a, 3)
```

> array(\[\[1, 2, 1, 2, 1, 2], \[3, 4, 3, 4, 3, 4])

---

# Stacking and repeating arrays (2/2)

```python
b = np.array([[5, 6]])

# Add a new row.
np.concatenate((a, b), axis=0)
# Same as:
np.vstack((a, b))

# Add a new column.
np.concatenate((a, b.T), axis=1)
# Same as:
np.hstack((a, b.T))
```

---

# Reference vs. deep copy

To achieve high performance, assignments in Python usually do not copy the underlying objects. This is important, for example, when objects are passed between functions to avoid an excessive amount of memory copying when it is not necessary:

```python
A = np.array([[1, 2], [3, 4]])

B = A  # B is referring to the same array data as A.
B[0, 0] = 10  # Changing B affects A.

C = np.copy(A)  # Deep copy.
C[0, 0] = -5  # If we modify C, A is not affected.
```

---

# Iterating over array elements (1/2)

Generally, we want to avoid iterating over the elements of arrays whenever possible. The Python `for` loop is the most convenient way to iterate over an array when necessary:

```python
v = np.array([1, 2, 3, 4])
for element in v:
    print(element)

M = np.array([[1, 2], [3, 4]])
for row in M:
    print("row", row)
    for element in row:
        print(element)
```

---

# Iterating over array elements (2/2)

When we need to iterate over each element of an array and modify its elements, it is convenient to use the `enumerate` function to obtain both the element and its index in the `for` loop:

```python
for row_idx, row in enumerate(M):
    print("row_idx", row_idx, "row", row)
    
    for col_idx, element in enumerate(row):
        print("col_idx", col_idx, "element", element)
       
        # Update the matrix M: square each element.
        M[row_idx, col_idx] = element ** 2
```

---

# Vectorizing functions (1/2)

As mentioned several times, to achieve good performance, we should avoid looping over elements in our vectors and matrices and instead use vectorized algorithms. The first step is to make sure that functions work with vector inputs:

```python
def Heaviside(x):
    """
    Scalar implementation of the Heaviside step function.
    """
    if x >= 0:
        return 1
    else:
        return 0

Heaviside(np.array([-3, -2, -1, 0, 1, 2, 3]))
```

> ValueError: The truth value of an array with more than one element is ambiguous. Use a.any() or a.all()

---

# Vectorizing functions (2/2)

Implement the function to accept a vector input from the beginning:

```python
def Heaviside(x):
    """
    Vector-aware implementation of the Heaviside step function.
    """
    return 1 * (x >= 0)

Heaviside(np.array([-3, -2, -1, 0, 1, 2, 3]))
```

See also the NumPy function `vectorize`.

---

# Using arrays in conditions

When using arrays in conditions, for example `if` statements and other boolean expressions, use `any` or `all`, requiring that any or all elements in the array evaluate to `True`:

```python
if (M > 5).any():
    print("At least one element in M is larger than 5.")

if (M > 5).all():
    print("All elements in M are larger than 5.")
```

---

# Type casting

Since NumPy arrays are *statically typed*, the type of an array does not change once created. But we can explicitly cast an array of some type to another using the `astype` functions (see also the similar `asarray` function). This always creates a new array of new type:

```python
M.dtype
```

> dtype('int64')

```python
M2 = M.astype(float)
M3 = M.astype(bool)
```

---

# Further reading

- [NumPy Documentation](http://NumPy.scipy.org)
- [Tentative NumPy Tutorial](http://scipy.org/Tentative_NumPy_Tutorial)
- [NumPy for MATLAB Users](http://scipy.org/NumPy_for_Matlab_Users) - A NumPy guide for MATLAB users.

---

<!--
_class: titlepage
-->

# SciPy

---

<!--
_class: titlepage
-->

# Data visualization

---

<!--
_class: titlepage
-->

# Pandas

---

<!--
_class: titlepage
-->

# :arrow_right:
