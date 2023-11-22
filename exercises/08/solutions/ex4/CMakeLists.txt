cmake_minimum_required(VERSION 3.14)

project(statistics LANGUAGES CXX)

# GoogleTest requires at least C++14.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_mean tests/mean.cpp src/statistics.cpp src/statistics.hpp)
target_include_directories(test_mean PUBLIC "src")
target_link_libraries(test_mean GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_mean)
