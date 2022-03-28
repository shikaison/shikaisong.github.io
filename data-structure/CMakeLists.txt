cmake_minimum_required(VERSION 3.21)
project(data_structure C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(Inc)
include_directories(linear-list)

add_executable(data_structure
        Inc/chain.h
        Inc/chain_stack.h
        Inc/main.h
        Inc/order.h
        Inc/stack.h
        linear-list/chain.c
        linear-list/chain_stack.c
        linear-list/order.c
        linear-list/stack.c
        main.c)
