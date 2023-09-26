<!--
title: Laboratory 1

_class: titlepage

paginate: true
_paginate: skip
-->

# Laboratory 1
<br>

## The UNIX shell. The build process.
<br>

#### Advanced Programming - SISSA, UniTS, 2023-2024

###### Pasquale Claudio Africa

###### 28 Sep 2023

---

# Exercise 1
1. Go to your home folder (*Hint:* you can either use `~` or `$HOME`).
2. Create a folder named `test1`.
3. Go inside `test1` and create a directory `test2`.
4. Go inside `test2` and then up one directory.
5. Create the following files `f1.txt`, `f2.txt`, `f3.dat`, `f4.md`, `readme.md`, `.hidden`.
6. List all files in the directory, also the hidden ones.
7. List only files with `.txt` extension (*Hint:* use `*` wildcard).
8. List files with `1`, `2`, `3` or `4` in the name (*Hint:* use `[1-4]` wildcard).
9. Move the `readme.md` in `test2`.
10. Move all txt files in `test2` in one command.
11. Remove `f3.dat`.
12. Remove all content of `test2` and the folder itself in one commands.

---

# Exercise 2: download and deflate a matrix

With `wget` you can retrieve content from web servers.

For instance, you can download a matrix from the matrix market with

```bash
wget https://math.nist.gov/pub/MatrixMarket2/NEP/mhd/mhd416a.mtx.gz
```

To unzip the file, simply type
```bash
gzip -dk mhd416a.mtx.gz
```

---

# Exercise 3
1. Create a file with the current date (one command) and display its content.
2. Count the number of lines in the matrix `mhd416a.mtx` (*Hint:* use `head`, `cat`, `wc`, and `|`).
3. List the entries of the matrix that are smaller than 1e-10 in absolute value. You can assume that all values are in exponential format and all values are greater than 1e-100 in absolute value. Count how many entries satisfy this criteria (*Hint:* use `cat`, `grep`, `wc`, and `|`).
