//
// Created by Mohamed Bakr on 2/3/2026.
//

#ifndef DS_CIRCULARARRAYQUEUE_H
#define DS_CIRCULARARRAYQUEUE_H
#include <cstddef>
#include <stdexcept>
template <typename T>
class Queue {
    size_t _size;
    size_t _capacity;
    size_t _front;
    size_t _rear;
    T* _data;

    void alloc(size_t cap);

public:
    Queue(size_t capacity = 10);
    ~Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    Queue(Queue&& other) noexcept;
    Queue& operator=(Queue&& other) noexcept;

    bool isEmpty() const noexcept;
    bool isFull() const noexcept;
    size_t size() const noexcept;
    size_t capacity() const noexcept;

    T& front();
    T& rear();
    const T& front() const;
    const T& rear() const;

    void enqueue(const T& value);
    void dequeue();
    void clear() noexcept;
    void swap(Queue& other) noexcept;

    template <typename... Args>
    void emplace(Args&&... args);
};

#include "circularArrayQueue.tpp"

#endif //DS_CIRCULARARRAYQUEUE_H