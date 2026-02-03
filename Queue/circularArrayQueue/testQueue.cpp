//
// Created by Mohamed Bakr on 2/3/2026.
//

#include <cstdint>

#include "circularArrayQueue.h"
#include <iostream>
#include <cassert>
#include <stdexcept>

void test_enqueue_rear_front() {
    Queue<char> q(3);
    q.enqueue('a');
    q.enqueue('b');

    assert(q.front() == 'a');
    assert(q.rear() == 'b');
    assert(q.size() == 2);
    assert(!q.isEmpty());
}

void test_emplace() {
    Queue<int> q(2);
    q.emplace(5);
    q.emplace(15);
    assert(q.front() == 5);
    assert(q.rear() == 15);
    assert(q.size() == 2);
}

void test_dequeue() {
    Queue<char> q(3);
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');

    q.dequeue();
    assert(q.front() == 'b');
    assert(q.size() == 2);

    q.enqueue('d');
    assert(q.rear() == 'd');
    assert(q.front() == 'b');
    assert(q.size() == 3);
}

void test_empty() {
    Queue<char> q(1);

    assert(q.isEmpty());
    assert(q.size() == 0);

    q.enqueue('b');
    assert(!q.isEmpty());
}

void test_overflow() {
    Queue<char> q(1);
    q.enqueue('a');

    bool error = false;
    try {
        q.enqueue('b');
    } catch (const std::overflow_error&) {
        error = true;
    }
    assert(error);
}

void test_underflow() {
    Queue<char> q(1);
    bool error = false;

    try {
        q.dequeue();
    } catch (const std::underflow_error&) {
        error = true;
    }
    assert(error);
}


int_fast32_t main () {
    test_enqueue_rear_front();
    test_emplace();
    test_dequeue();
    test_empty();
    test_overflow();
    test_underflow();

    std::cout << "All tests passed!\n";
    return 0;
}