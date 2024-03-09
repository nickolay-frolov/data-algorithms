cmake_minimum_required(VERSION 3.10) 
project(DataAlgorithms)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES 
    src/Main.cpp
    include/Sort.h
    include/ServiceSort.h
)

add_executable(DataAlgorithms ${SOURCES})
