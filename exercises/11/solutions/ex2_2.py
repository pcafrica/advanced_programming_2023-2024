#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import minimize

# Define the function.
def f(x):
    return np.sin(np.pi * x) * np.exp(-x/10)

# Plot the function.
x = np.linspace(-2, 4, 1000)
y = f(x)
plt.plot(x, y)
plt.title("Function with multiple minima")
plt.show()

# Optimize using different initial guesses.
result1 = minimize(f, x0=-0.5)
result2 = minimize(f, x0=1.5)
result3 = minimize(f, x0=3.5)

print(f"x1 = {result1.x[0]}, f(x1) = {result1.jac[0]}")
print(f"x2 = {result2.x[0]}, f(x2) = {result2.jac[0]}")
print(f"x3 = {result3.x[0]}, f(x3) = {result3.jac[0]}")
