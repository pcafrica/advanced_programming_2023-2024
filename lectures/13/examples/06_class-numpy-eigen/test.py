import numpy as np
import example_06_class_numpy_eigen as example

a = np.arange(10)

print('a = \n', a)

array = example.CustomVectorXd(a)

print('print(array) = \n', array)

print('array.multiply(default) = \n'   , array.multiply())
print('array.multiply(factor=100) = \n', array.multiply(factor=100))

print('flip(a) = \n', example.flip(a))
