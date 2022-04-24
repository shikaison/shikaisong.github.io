cmake_minimum_required(VERSION 3.21)
project(data-structure)

set(CMAKE_C_STANDARD 99)

add_executable(data-structure
        main.cpp
        Inc/chain.h
        Inc/graph.h
        Inc/main.h
        Inc/order.h
        Inc/stack.h
        Inc/tree.h
        Inc/maze.h
        linear-list/chain.cpp
        linear-list/graph.cpp
        linear-list/order.cpp
        linear-list/stack.cpp
        linear-list/tree.cpp
        linear-list/maze.cpp
        )
include_directories(Inc)
file(GLOB_RECURSE SOURCES "linear-list/*.*")

