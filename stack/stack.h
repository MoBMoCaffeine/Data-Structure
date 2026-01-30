//
// Created by Mohamed Bakr on 1/30/2026.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <cstddef>
template<typename T>
class Stack {
    T* _data;
    size_t _topIndex;
    size_t _capacity;
    void Resize();
public:
    Stack(size_t initialCapacity = 10);
    ~Stack();

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;

    bool isEmpty() const;
    size_t size() const;

    class iterator;
    class const_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

#include "stack.tpp"

#endif //STACK_STACK_H