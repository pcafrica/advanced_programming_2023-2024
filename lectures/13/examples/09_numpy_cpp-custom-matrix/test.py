import numpy as np
import example

a = np.arange(5)
b = np.arange(5)

print(example.multiply(a, b))

a = np.arange(25).reshape(5, 5)
b = np.arange(25).reshape(5, 5)

print(example.multiply(a, b))

a = np.arange(125).reshape(5, 5, 5)
b = np.arange(125).reshape(5, 5, 5)

print(example.multiply(a, b))
