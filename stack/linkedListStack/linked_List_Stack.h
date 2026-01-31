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
    Stack() : _top(nullptr), _size(0) {}
    ~Stack() {
        clear();
    }

    void push(const T& value) {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->next = _top;
        _top = newNode;
        ++_size;
    }

    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack Underflow: coannot pop from empty stack!");
        }
        Node<T>* temp = _top;
        _top = _top->next;
        delete temp;
        --_size;
    }

    const T& peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty: no top element!");
        }
        return _top->data;
    }
    bool isEmpty() const {
        return _top == nullptr;
    }

    size_t size() const {
        return _size;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    void display() const {
        Node<T>* temp = _top;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

};

#include "linked_List_Stack.tpp"
#endif //LINKEDLISTSTACK_LINKED_LIST_STACK_H