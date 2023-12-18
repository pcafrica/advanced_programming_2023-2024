cmake_minimum_required(VERSION 3.5)
project(example)

find_package(pybind11 REQUIRED)
include_directories(SYSTEM ${pybind11_INCLUDE_DIRS})

pybind11_add_module(example example.cpp)
