cmake_minimum_required(VERSION 4.0)
project(LinkedList)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LinkedList
        linkedList.h
        linkedList.tpp
        test.cpp)
