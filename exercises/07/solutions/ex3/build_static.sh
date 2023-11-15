#!/bin/bash

set -x

# Generate libmath.a.
g++ -c math_lib.cpp
ar rs libmath.a math_lib.o

# Generate libgraphics.a.
g++ -c graphics_lib.cpp 
ar rs libgraphics.a graphics_lib.o

# Compile ex3.
g++ -c ex3.cpp

# Link.
# These are all wrong:
g++ ex3.o -L. -lmath -lgraphics -o ex3

g++ -L. -lmath -lgraphics ex3.o -o ex3

g++ -L. -lgraphics -lmath ex3.o -o ex3

# Correct:
g++ ex3.o -L. -lgraphics -lmath -o ex3

rm -rf *.o *.a ex3

set +x
