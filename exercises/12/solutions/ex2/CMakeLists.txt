cmake_minimum_required(VERSION 3.5)
project(newton_solver)

find_package(pybind11 REQUIRED)
include_directories(SYSTEM ${pybind11_INCLUDE_DIRS})

pybind11_add_module(newton_solver newton.cpp newton_py.cpp)
