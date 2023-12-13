#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import interp1d
from scipy.integrate import quad

# Data points.
time = np.arange(0, 46, 3)
energy = np.array([27.29, 23.20, 24.93, 28.72, 27.60, 19.06, 24.85, 21.54, 21.69, 23.23, 22.43, 26.36, 24.28, 22.36, 23.33, 23.00])

# Cubic interpolation.
f_interpolator = interp1d(time, energy, kind='cubic')

time_interp = np.linspace(0, 45, 1000)
energy_interp = f_interpolator(new_time)

# Plot the interpolant.
plt.plot(time, energy, 'o', time_interp, energy_interp, '-')
plt.title("Energy interpolation")
plt.show()

# Integrate over the time interval.
energy_integral = quad(f_interpolator, 0, 45)[0]
