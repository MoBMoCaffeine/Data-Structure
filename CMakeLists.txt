cmake_minimum_required(VERSION 4.0)
project(DS)

set(CMAKE_CXX_STANDARD 14)

include_directories(Queue/circularArrayQueue)
include_directories(Queue/LinkedListQueue)
include_directories(stack/linkedListStack)
include_directories(stack/Stack)

add_executable(testCircularQueue
        Queue/circularArrayQueue/testQueue.cpp
        Queue/circularArrayQueue/circularArrayQueue.h
        Queue/circularArrayQueue/circularArrayQueue.tpp
)

add_executable(testLinkedListQueue
        Queue/LinkedListQueue/testLLQueue.cpp
        Queue/LinkedListQueue/linkedListQueue.h
        Queue/LinkedListQueue/linkedListQueue.tpp
)

add_executable(testLinkedListStack
        stack/linkedListStack/tests.cpp
        stack/linkedListStack/linked_List_Stack.h
        stack/linkedListStack/linked_List_Stack.tpp
)

add_executable(testStack
        stack/Stack/tests.cpp
        stack/Stack/stack.h
        stack/Stack/stack.tpp
)
