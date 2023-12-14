#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt

# Load sales data.
sales_data = pd.read_csv('../sales_data.csv')

# Filter, sort, and add a new column.
filtered_sales_data = sales_data[sales_data['Region'] == 'South']
sorted_sales_data = filtered_sales_data.sort_values(by='Quantity', ascending=False)
sorted_sales_data['Total revenue'] = sorted_sales_data['Quantity'] * sorted_sales_data['Price']

# Visualize data trends.
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
sorted_sales_data.groupby('Date')['Total revenue'].sum().plot(kind='line')
plt.title('Total revenue over time')
plt.xlabel('Date')
plt.ylabel('Total revenue')

plt.subplot(1, 2, 2)
sorted_sales_data.groupby('Product')['Total revenue'].sum().plot(kind='bar')
plt.title('Total revenue by product')
plt.xlabel('Product')
plt.ylabel('Total revenue')
plt.tight_layout()
plt.show()
