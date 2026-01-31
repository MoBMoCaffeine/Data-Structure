cmake_minimum_required(VERSION 3.20)
project(linkedListStack)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(linkedListStack
        linked_List_Stack.h
        linked_List_Stack.tpp
        tests.cpp)
