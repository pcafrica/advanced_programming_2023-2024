import numpy as np
import example

a = np.array([[1, 2, 1],
              [2, 1, 0],
              [-1, 1, 2]])
b = 10

print(example.multiply(a.astype(int), int(b)))
print(example.multiply(a.astype(float), float(b)))
