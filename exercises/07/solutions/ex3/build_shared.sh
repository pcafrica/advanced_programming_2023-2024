#!/bin/bash

set -x

# Generate libmath.so.
g++ -c -fPIC math_lib.cpp
g++ -shared math_lib.o -o libmath.so

# Generate libgraphics.so.
g++ -c -fPIC graphics_lib.cpp 
g++ -shared graphics_lib.o -o libgraphics.so

# Compile ex3.
g++ -c ex3.cpp

# Link.
# These are all wrong:
g++ ex3.o -L. -lmath -lgraphics -o ex3

g++ -L. -lmath -lgraphics ex3.o -o ex3

g++ -L. -lgraphics -lmath ex3.o -o ex3

# Correct:
g++ ex3.o -L. -lgraphics -lmath -o ex3

rm -rf *.o *.so ex3

set +x
