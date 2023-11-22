cmake_minimum_required(VERSION 3.12)

project(Ex07_1 VERSION 1.0
  DESCRIPTION "Exercise 1 from session 07"
  LANGUAGES CXX)

set(MUPARSERX_DIR "/opt/muparserx/" CACHE
  STRING "Path to an installation of muParserX.")
             
add_executable(ex1 ex1.cpp)
target_include_directories(ex1 PUBLIC ${MUPARSERX_DIR}/include)
target_link_directories(ex1 PUBLIC ${MUPARSERX_DIR}/lib)
target_link_libraries(ex1 muparserx)
