import numpy as np
import example

a = np.array([[1, 2, 1],
              [2, 1, 0],
              [-1, 1, 2]])

print('a = \n'                  , a)
print('example.det(A) = \n'     , example.det(a))
print('numpy.linalg.det(A) = \n', np.linalg.det(a))
print('example.inv(A) = \n'     , example.inv(a))
print('numpy.linalg.inv(A) = \n', np.linalg.inv(a))
