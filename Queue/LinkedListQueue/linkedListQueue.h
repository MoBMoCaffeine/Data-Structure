//
// Created by Mohamed Bakr on 2/13/2026.
//

#ifndef DS_LINKEDLISTQUEUE_H
#define DS_LINKEDLISTQUEUE_H

#include <stdexcept>
#include <utility>
#include <iterator>
#include <cstddef>
namespace ds {
    namespace llist {
        template <typename T>
class Queue {
        private:
            struct Node {
                T data;
                Node* next;

                template <typename... Args>
                explicit Node(Args&&... args) : data(std::forward<Args>(args)...), next(nullptr) {}
            };
        public:
            using value_type        = T;
            using size_type         = std::size_t;
            using reference         = value_type&;
            using const_reference   = const value_type&;

        private:
            Node * head_;
            Node * tail_;
            size_type size_;
            size_type capacity_;

            template <typename... Args>
            Node* create_node(Args&&... args);

            void destroy_node(Node* node) noexcept;

            void copy_from(const Queue& other);
            void move_from(Queue&& other) noexcept;

        public:
            explicit Queue(size_type capacity = 0) noexcept;
            ~Queue() noexcept;

            Queue(const Queue& other);
            Queue& operator=(const Queue& other) ;

            Queue(Queue&& other) noexcept;
            Queue& operator=(Queue&& other) noexcept;

            bool isEmpty() const noexcept;
            bool isFull() const noexcept;
            explicit operator bool() const noexcept { return !isEmpty(); }
            size_type size() const noexcept;
            size_type capacity() const noexcept;

            reference front();
            const_reference front() const;
            reference back();
            const_reference back() const;

            void push(const T& value);

            void push(T &&value);
            void pop();
            void clear() noexcept;
            void swap(Queue& other) noexcept;

            template <typename... Args>
            void emplace(Args&&... args);

            class iterator;
            class const_iterator;

            iterator begin() noexcept;
            iterator end() noexcept;

            const_iterator begin() const noexcept;
            const_iterator end() const noexcept;
            const_iterator cbegin() const noexcept;
            const_iterator cend() const noexcept;

        };
    }
}

#include "linkedListQueue.tpp"

#endif //DS_LINKEDLISTQUEUE_H