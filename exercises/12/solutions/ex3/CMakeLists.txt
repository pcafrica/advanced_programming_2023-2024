cmake_minimum_required(VERSION 3.12)
project(eigen_ops)

#find_package is having issues finding the directory of Eigen headers
# find_package(Eigen3 REQUIRED)
# if(Eigen3_FOUND)
#     message("Eigen3 Library Found")
# elseif(NOT Eigen3_FOUND)
#     error("Eigen3 Library Not Found: Please install it in order to continue")
# endif()

#If the library is installed in the /opt directory then this lines work
set(Eigen3_INCLUDE_DIRS "/opt/eigen/include/eigen3/" CACHE STRING "Path to an installation of Eigen3.")             
include_directories(SYSTEM ${Eigen3_INCLUDE_DIRS})

find_package(pybind11 REQUIRED)
include_directories(SYSTEM ${pybind11_INCLUDE_DIRS})
# message("pybind11_INCLUDE_DIRS: ${pybind11_INCLUDE_DIRS}")

pybind11_add_module(eigen_ops src/eigen_ops.cpp)
target_include_directories(eigen_ops PRIVATE include)
