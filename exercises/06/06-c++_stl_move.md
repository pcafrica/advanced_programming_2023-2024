<!--
title: Exercise session 06
paginate: true

_class: titlepage
-->

# Exercise session 06
<br>

## The Standard Template Library, smart pointers and move semantics.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 09 Nov 2023

---

# Exercise 1: Monte Carlo estimate of $\pi$

In this exercise, you will perform a Monte Carlo simulation to estimate $\pi$.

1. Consider the square $[0, 1]^2$ and the quarter-circle centered at $(0, 0)$ with radius $1$.
2. Generate random points within the square.
3. Count how many of these random points fall within the quarter-circle.
4. After generating a sufficient number of random points, you can estimate

$$
\pi \approx \frac{4 \cdot \text{Number of points inside the quarter-circle}}{\text{Total number of generated points}}.
$$

To improve estimation accuracy, try to increase the number of random points in your simulation.

---

# Exercise 2: STL containers and algorithms

1. **Generate a vector**: Create a vector named `random_numbers` that contains 100 random integers between 0 and 9.
2. **Sort the vector**: Create a new vector named `sorted_numbers` by sorting the `random_numbers` vector in ascending order, with repetitions.
3. **Remove duplicates while sorting**: Create a new vector named `sorted_unique_numbers` by sorting the `random_numbers` vector and removing duplicate entries.
4. **Remove duplicates without sorting**: Create a new vector named `unsorted_unique_numbers` by printing unique entries from the `random_numbers` in the same order they appear, without repetitions.

---

# Exercise 3: Word frequency analysis

The file `input.txt` contains a list of random complete sentences in English. Develop a C++ program that reads the file, calculates the frequency of each word in the text, and outputs the word-frequency pairs to a new file in a dictionary format.

Write a C++ program to process the input text file by splitting it into words and counting the occurrences of each unique word. Spaces and punctuation should be discarded.

The program should generate a new file (named `output.txt`) containing the word-frequency pairs in a dictionary format. Each line in the output file should consist of a word followed by its frequency, separated by a colon or any other suitable delimiter.
 
**(Bonus)**: sort the output by frequency, in descending order. If two words have the same frequency, then sort them alphabetically.

---

# Exercise 4: Move semantics for efficient data transfers

Define a class Vector that represents a one-dimensional vector of double values, stored as a raw pointer `double * data`.

1. Implement a **move constructor** for the `Vector` class that transfers ownership of the underlying data from the source vector to the destination vector. The move constructor should ensure that the source vector's data is no longer accessible after the transfer.
2. Define a **copy** and a **move assignment operator** for the `Vector` class that allows for the efficient transfer of ownership of the underlying data from one Vector object to another. Similar to the move constructor, the move assignment operator should ensure that the source vector's data is no longer accessible after the transfer.
3. Compare the performance of copying and moving large vectors using both copy semantics and move semantics. Measure the time taken to copy and move vectors by increasing the input size from $2^20$ to $2^30$ elements. Analyze the results and observe the performance gain achieved by using move semantics.
