cmake_minimum_required(VERSION 3.5)
project(eigen_ops)

find_package(Eigen3 REQUIRED)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIRS})

find_package(pybind11 REQUIRED)
include_directories(SYSTEM ${pybind11_INCLUDE_DIRS})

pybind11_add_module(eigen_ops src/eigen_ops.cpp)
target_include_directories(eigen_ops PRIVATE include)
