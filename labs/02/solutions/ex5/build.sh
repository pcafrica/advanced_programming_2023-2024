#!/bin/bash

set -x

mkdir -p build
g++ -Iinclude/ src/calculator.cpp -c -o build/calculator.o
g++ -Iinclude/ src/main.cpp -c -o build/main.o
g++ build/calculator.o build/main.o -o build/calculator

set +x

if [ $? -eq 0 ]; then
    echo "Build successful! You can run the program using ./build/calculator"
else
    echo "Build failed."
fi
