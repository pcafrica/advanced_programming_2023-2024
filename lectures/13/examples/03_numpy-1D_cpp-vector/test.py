import numpy as np
import example

a = [0, 1, 2, 3, 4, 5]
b = example.multiply(a)

print('input list = ', a)
print('output     = ', b)

a = np.arange(10)
b = example.multiply(a)

print('input list = ', a)
print('output     = ', b)
