cmake_minimum_required(VERSION 3.12)

project(Ex07_3 VERSION 1.0
  DESCRIPTION "Exercise 3 from session 07"
  LANGUAGES CXX)

add_library(graphics STATIC graphics_lib.cpp)
add_library(math STATIC math_lib.cpp)
target_link_libraries(graphics math)

add_executable(ex3 ex3.cpp)
target_link_libraries(ex3 graphics)
