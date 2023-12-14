#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt

# Load weather data.
weather_data = pd.read_csv('../weather_data.csv', parse_dates=['Date'], index_col='Date')

# Resample for monthly averages and compute a 7-day rolling mean.
monthly_avg = weather_data.resample('M').mean()
rolling_mean = weather_data.rolling(window=7).mean()

# Visualize original data and rolling mean.
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
weather_data['Temperature'].plot(kind='line', label='Original')
plt.title('Daily temperature')
plt.xlabel('Date')
plt.ylabel('Temperature (°C)')

plt.subplot(1, 2, 2)
rolling_mean['Temperature'].plot(kind='line', label='7-day rolling mean', color='red')
plt.title('7-day rolling mean of temperature')
plt.xlabel('Date')
plt.ylabel('Temperature (°C)')
plt.tight_layout()
plt.show()
