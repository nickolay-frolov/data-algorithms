cmake_minimum_required(VERSION 3.10) 
project(SortAlgorithms)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES 
    src/Main.cpp
    include/Sort.h
    include/ServiceSort.h
)

add_executable(SortAlgorithms ${SOURCES})
