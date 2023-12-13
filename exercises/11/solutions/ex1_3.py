#!/usr/bin/env python3

import numpy as np

n = 20

# Generate a 1D array with random integers.
random_array = np.random.randint(1, 101, size=n)

# Calculate mean, median, standard deviation, and variance.
mean = np.mean(random_array)
median = np.median(random_array)
std_dev = np.std(random_array)
variance = np.var(random_array)
