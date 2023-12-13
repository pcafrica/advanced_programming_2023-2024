<!--
title: Exercise session 11
paginate: true

_class: titlepage
-->

# Exercise session 11
<br>

## Introduction to NumPy and SciPy for scientific computing. Data visualization. Introduction to pandas for data analysis.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 14 Dec 2023

---

# Exercise 1: NumPy

1. **Array creation and manipulation**
   1. Create a 2D NumPy array of shape $5 \times 5$ filled with random integers between 1 and 10.
   2. Extract the second row, third column element, and the diagonal elements.
   3. Reshape it into a 1D array of shape $1 \times 25$.
2. **Linear algebra operations**
   1. Generate two 3x3 matrices with random integers from 1 to 10 and perform element-wise and matrix-matrix multiplication.
   2. Create a 3x3 matrix with random values, compute its inverse and determinant.
3. **Statistical analysis**
   1. Generate a 1D NumPy array with 20 random integers between 1 and 100.
   2. Calculate the mean, median, standard deviation, and variance.

---

# Exercise 2: SciPy (1/2)

1. **Solving a linear system of equations**
   1. Define a $100 \times 100$ *sparse* tridiagonal matrix $A$, with $2$ over the main diagonal, and $-1$ over the first lower and upper diagonals.
   2. Let $b = Ax_\mathrm{ex}$ where $x_\mathrm{ex} = [1, 1, \dots, 1]^T \in \mathbb{R}^{100}$
   3. Solve the linear system $Ax = b$ and compute the residual $\|b - Ax\|$ and the error $\|x - x_\mathrm{ex}\|$ in norm 1, 2 and infinity.

2. **Function optimization**
   1. Consider the function $f(x) = \sin(\pi x) \exp(-x/10)$ over the interval $[-2, 4]$.
   2. Plot the function using Matplotlib to visually identify potential minima.
   3. Use `scipy.optimize.minimize` with different initial guesses to find these minima.

---

# Exercise 2: SciPy (2/2)

3. **Data interpolation and integration**
   1. An electric vehicle charging station erogates the following series of energy measurements over time:
      ```python
      time = np.arange(0, 46, 3) # Hours.
      energy = np.array([27.29, 23.20, 24.93, 28.72, 27.60, 19.06, 24.85, 21.54, 21.69, 23.23, 22.43, 26.36, 24.28, 22.36, 23.33, 23.00]) # kW.
      ```
   2. Use SciPy to build a cubic interpolator of these data points.
   3. Evaluate the interpolator over 1000 equispaced nodes between 0 and 45 and plot the values obtained.
   3. Integrate the interpolant over $(0, 45)$.

---

# Exercise 3: pandas (1/2)

1. **DataFrame operations and visualization**
   1. Import the `sales_data.txt` dataset as a pandas DataFrame.
   2. Extract data from the 'South' region, sort them by descending 'Quantity' and add a new column 'Total revenue' $=$ 'Quantity' $\times$ 'Price'.
   3. Visualize trends of 'Total revenue' by 'Date' (line plot) and by 'Product' (bar plot).

2. **Exploratory data analysis with the *iris* dataset**
   1. Load the `iris` dataset from seaborn.
   2. Group the data by 'species' and compute summary statistics for `sepal_length` and `sepal_width`.
   3. Use seaborn to plot the histogram of the sepal length distribution for each species.
   4. Use seaborn to generate a scatter plot of sepal width vs. sepal length.

---

# Exercise 3: pandas (2/2)

3. **Time series analysis with real data**
   1. Import the `weather_data.txt` dataset.
   2. Resample the dataset to compute monthly averages.
   3. Computing a 7-day rolling mean.
   3. Visualize the original data and the rolling mean using line plots.
