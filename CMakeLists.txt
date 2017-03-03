cmake_minimum_required(VERSION 3.6)
project(algorithms_and_data_structures)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Heap.cpp)

add_executable(heap ${SOURCE_FILES})