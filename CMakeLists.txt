cmake_minimum_required(VERSION 3.15)
project(Algos)

set(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES /Library/Developer/CommandLineTools/usr/include/c++/v1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(main main.cpp)