cmake_minimum_required(VERSION 4.0)
project(DS)

set(CMAKE_CXX_STANDARD 14)

include_directories(Queue/circularArrayQueue)
include_directories(stack/linkedListStack)
include_directories(stack/Stack)

add_executable(DS
        Queue/circularArrayQueue/testQueue.cpp
        Queue/circularArrayQueue/circularArrayQueue.h
        stack/linkedListStack/linked_List_Stack.h
        stack/linkedListStack/linked_List_Stack.tpp
        stack/linkedListStack/tests.cpp
        stack/Stack/stack.h
        stack/Stack/stack.tpp
        stack/Stack/tests.cpp
        Queue/circularArrayQueue/circularArrayQueue.tpp)
