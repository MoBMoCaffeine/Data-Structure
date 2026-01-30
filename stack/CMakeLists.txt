cmake_minimum_required(VERSION 3.20)
project(stack CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(stack
        stack.h
        stack.tpp
        tests.cpp
)
