#!/usr/bin/env python3

import seaborn as sns
import matplotlib.pyplot as plt

# Load iris dataset.
iris = sns.load_dataset('iris')

# Group by species and compute summary statistics.
grouped_iris = iris.groupby('species').agg({'sepal_length': ['mean', 'std'], 'sepal_width': ['mean', 'std']})

# Visualize statistics.
plt.figure(figsize=(12, 6))
plt.subplot(1, 2, 1)
sns.histplot(data=iris, x='sepal_length', hue='species', element='step', stat='density', common_norm=False)
plt.title('Sepal length distribution by species')

plt.subplot(1, 2, 2)
sns.scatterplot(data=iris, x='sepal_length', y='sepal_width', hue='species')
plt.title('Sepal width vs. length')
plt.show()
