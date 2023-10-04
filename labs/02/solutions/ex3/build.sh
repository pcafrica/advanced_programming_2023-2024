#!/bin/bash

set -x

g++ statistics.cpp main.cpp -o main

set +x

if [ $? -eq 0 ]; then
    echo "Build successful! You can run the program using ./main"
else
    echo "Build failed."
fi
