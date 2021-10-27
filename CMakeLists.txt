cmake_minimum_required(VERSION 3.15)
project(Algos)

set(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES /Library/Developer/CommandLineTools/usr/include/c++/v1)

add_executable(Algos NumberTheory/EulerFunc.cpp Sort/Piramid.cpp String/SuffixArray.cpp)