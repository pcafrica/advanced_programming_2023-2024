# Part 2: Programming exercise

## Objective
Develop a Gradient Descent optimization algorithm using C++ and integrate it with Python using pybind11. The exercise will involve creating classes for describing a problem to be optimized and implementing the gradient descent algorithm.

---

## Mathematical background

### Gradient descent: general overview
Gradient Descent is a fundamental optimization algorithm used in machine learning and statistics to minimize an arbitrary function. It's an iterative approach for finding the minimum of a function, particularly useful when the function is complex and does not have a closed-form solution.

Given a scalar multi-variate function $f(\mathbf{z})$ to optimize, the method consists of the following iterative algorithm:

1. **Initialization**: Start with an initial guess for the parameters of the function to be optimized.
2. **Gradient calculation**: Compute the gradient of the function with respect to its parameters at the current point, i.e. $\nabla f(\mathbf{z})$.
3. **Update step**: Adjust each parameters in the opposite direction of the gradient, i.e. $z_{j, \text{new}} = z_j - \alpha \frac{\partial f}{\partial z_j}$. This step is governed by a parameter $\alpha$ known as the learning rate.
4. **Iteration**: Repeat steps 2 and 3 until $||f(\mathbf{z}_\text{new})||$ is below a certain threshold, or a maximum number of iterations is reached.
5. **Output**: The final parameter values are used as the solution, ideally representing the point where the function attains its minimum value.

### Gradient descent for linear regression
In the context of linear regression, Gradient Descent is used to find the parameters (coefficients) $\theta$ of the regression model that minimize a cost function, typically the Mean Squared Error (MSE).

Given a set of points $\lbrace(\mathbf{x}^{(i)}, y^{(i)})\rbrace_{i=0}^m$ with $x_0^{(i)} = 1$ $\forall i$, the linear regression model computes a prediction $\hat{y}^{(i)}$ of the output $y^{(i)}$ as a linear combination of the input features $\mathbf{x}^{(i)}$:

$$
\hat{y}^{(i)} = \theta_0 + \theta_1 x_1^{(i)} + \dots + \theta_n x_n^{(i)}.
$$

The MSE cost function for linear regression, to be minimized with respect to the vector $\theta$, is

$$
J(\theta) = \frac{1}{2m} \sum_{i=0}^{m} (\hat{y}^{(i)} - y^{(i)})^2.
$$

The gradient of the cost function is

$$
\frac{\partial J}{\partial \theta_j}(\theta) = \frac{1}{m} \sum_{i=0}^{m} \left[(\hat{y}^{(i)} - y^{(i)}) x_j^{(i)}\right].
$$

The final values of $\theta_0, \theta_1, \dots, \theta_n$ represent the best-fit parameters for the linear model.

---

## Tasks
The goal is to implement a Gradient Descent solver to solve the following two problems:

### Problem 1.
Minimize the scalar quadratic function $f(x)=(x-1)^2$. For such a function, a moderate learning rate, such as $\alpha = 0.1$, is typically a good starting point.

### Problem 2.
Generate a set of points $\lbrace(x^{(i)}, y^{(i)})\rbrace_{i=0}^m$ such that $y^{(i)} = 4 + \frac{1}{2} x^{(i)} + \epsilon$, where $\epsilon$ is a small random noise and minimize the model $\hat{y} = \theta_0 + \theta_1 x$. A smaller learning rate, such as $\alpha = 0.01$ or $\alpha = 0.001$, is often more appropriate for such problems, especially when the data is not normalized.

1. **Design the base class for optimization problems in C++**
   1. Create an abstract base class `OptimizationProblem`. This class will serve as a blueprint for different optimization problems.
   2. Include a virtual method `double evaluate(const std::vector<double> &input)` for evaluating the objective function.
   3. Include a virtual method `std::vector<double> evaluate_gradient(const std::vector<double> &input)` for evaluating its gradient. The former two methods will be overridden in derived classes.

2. **Implement a Gradient Descent solver class**
   1. Develop a class `GradientDescent`, receiving a polymorphic `OptimizationProblem` object.
   2. Include methods for setting parameters like learning rate, maximum iterations, and convergence threshold, and for returning the final solution and the cost function evaluated at that solution.
   3. Implement the core Gradient Descent algorithm, utilizing the functions from the `OptimizationProblem` class.
   4. Ensure proper exception handling in case the algorithm fails to converge.

3. **Create specific optimization problem classes**
   1. Define classes that inherit from `OptimizationProblem` for the two problems at hand, such as `QuadraticOptimizationProblem` and `LinearRegressionProblem`.
   2. Override the objective function and gradient calculation methods specific to each problem.

4. **Configuration and compilation**
   1. Develop a CMake script for easy compilation of the C++ library.
   2. Provide clear instructions on compiling the library.

5. **Python bindings using pybind11**
   1. Bind the C++ functions, classes and their methods to Python, properly handling exceptions.
   2. Ensure the Python interface is user-friendly and adheres to Python conventions.
   3. Create Python scripts to test the functionality of the solver through the bindings.
   4. Validate the solution to Problem 1 by computing the error against the exact solution $x = 1$.
   5. Plot the solution to Problem 2, plot the cost function vs. the Gradient Descent iterations, and evaluate the MSE cost function at the optimal value.

6. **(Bonus) validation and comparison**
   1. Let the class `GradientDescent` be templated over the type of optimization problem to be solved.
   2. Validate and compare the results of Problem 1 against the [`minimize_scalar` function](https://docs.scipy.org/doc/scipy/reference/generated/scipy.optimize.minimize_scalar.html) from the Python module `scipy.optimize` and of Problem 2 against the [`linregress` function](https://docs.scipy.org/doc/scipy/reference/generated/scipy.stats.linregress.html) from the Python module `scipy.stats`.
   3. Design benchmarks to compare performance metrics between the C++ and Python implementations.
   4. Use `setuptools` to setup the build process for the Python bindings.
   5. Write tests for both the C++ and the Python implementation.
