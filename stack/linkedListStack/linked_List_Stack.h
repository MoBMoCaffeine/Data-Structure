//
// Created by Mohamed Bakr on 1/31/2026.
//

#ifndef LINKEDLISTSTACK_LINKED_LIST_STACK_H
#define LINKEDLISTSTACK_LINKED_LIST_STACK_H

#include <iostream>
#include <stdexcept>
template <typename T>
struct Node {
    T data;
    Node<T>* next;
    // Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class Stack {
    Node<T>* _top;
    size_t _size;

public:
    Stack();
    ~Stack();

    void push(const T& value);
    void pop();
    const T& peek() const;
    bool isEmpty() const;
    size_t size() const;

    void clear();

    void display() const;

};

#include "linked_List_Stack.tpp"
#endif //LINKEDLISTSTACK_LINKED_LIST_STACK_H