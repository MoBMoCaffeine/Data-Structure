#pragma once
#ifndef STATIC_ARRAY_QUEUE_H
#define STATIC_ARRAY_QUEUE_H

#define MAX_SIZE 100

namespace ds {
    namespace Static {
        template<typename T>
        class Queue {
            int size_;
            int front_, rear_;
            T queueArray[MAX_SIZE];

        public:
            Queue();

            ~Queue();

            bool isEmpty();

            bool isFull();

            void enqueue(T value);

            T dequeue();

            T front();

            T rear();

            int size();
        };
    }
}

#include "staticArrayQueue.tpp"

#endif // STATIC_ARRAY_QUEUE_H
