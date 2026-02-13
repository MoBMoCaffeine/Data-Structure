#include "linkedListQueue.h"
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace ds::llist;

/* ============================================================
   Helper Type to Track Object Lifetime & Move/Copy Behavior
   ============================================================ */

struct Tracked {
    static int constructions;
    static int destructions;
    static int copies;
    static int moves;

    int value;

    Tracked(int v = 0) : value(v) { ++constructions; }

    Tracked(const Tracked& other) : value(other.value) {
        ++copies;
        ++constructions;
    }

    Tracked(Tracked&& other) noexcept : value(other.value) {
        ++moves;
        ++constructions;
    }

    ~Tracked() { ++destructions; }

    static void reset() {
        constructions = destructions = copies = moves = 0;
    }
};

int Tracked::constructions = 0;
int Tracked::destructions = 0;
int Tracked::copies = 0;
int Tracked::moves = 0;


/* ============================================================
   Basic Functional Tests
   ============================================================ */

void test_basic_push_pop() {
    Queue<int> q(3);

    q.push(1);
    q.push(2);
    q.push(3);

    assert(q.front() == 1);
    assert(q.back() == 3);
    assert(q.size() == 3);

    q.pop();
    assert(q.front() == 2);
    assert(q.size() == 2);

    q.pop();
    q.pop();

    assert(q.isEmpty());
}


/* ============================================================
   Capacity Tests
   ============================================================ */

void test_capacity_limits() {
    Queue<int> q(2);

    q.push(1);
    q.push(2);

    bool thrown = false;
    try {
        q.push(3);
    } catch (const std::overflow_error&) {
        thrown = true;
    }

    assert(thrown);
}


/* ============================================================
   Underflow Test
   ============================================================ */

void test_underflow() {
    Queue<int> q;

    bool thrown = false;
    try {
        q.pop();
    } catch (const std::underflow_error&) {
        thrown = true;
    }

    assert(thrown);
}


/* ============================================================
   Copy Constructor Test
   ============================================================ */

void test_copy_constructor() {
    Queue<int> q;
    for (int i = 0; i < 5; ++i)
        q.push(i);

    Queue<int> copy(q);

    assert(copy.size() == q.size());

    for (int i = 0; i < 5; ++i) {
        assert(copy.front() == q.front());
        copy.pop();
        q.pop();
    }
}


/* ============================================================
   Copy Assignment Test
   ============================================================ */

void test_copy_assignment() {
    Queue<int> q1;
    Queue<int> q2;

    for (int i = 0; i < 5; ++i)
        q1.push(i);

    q2 = q1;

    assert(q2.size() == 5);
    assert(q1.size() == 5);
}


/* ============================================================
   Move Constructor Test
   ============================================================ */

void test_move_constructor() {
    Queue<int> q;

    for (int i = 0; i < 5; ++i)
        q.push(i);

    Queue<int> moved(std::move(q));

    assert(moved.size() == 5);
    assert(q.size() == 0);
}


/* ============================================================
   Move Assignment Test
   ============================================================ */

void test_move_assignment() {
    Queue<int> q1;
    for (int i = 0; i < 5; ++i)
        q1.push(i);

    Queue<int> q2;
    q2 = std::move(q1);

    assert(q2.size() == 5);
    assert(q1.size() == 0);
}


/* ============================================================
   Self Assignment Test
   ============================================================ */

void test_self_assignment() {
    Queue<int> q;

    for (int i = 0; i < 5; ++i)
        q.push(i);

    q = q;  // self copy
    assert(q.size() == 5);

    q = std::move(q); // self move
    assert(q.size() == 5);
}


/* ============================================================
   Iterator Tests
   ============================================================ */

void test_iterator() {
    Queue<int> q;
    for (int i = 0; i < 5; ++i)
        q.push(i);

    int expected = 0;
    for (auto it = q.begin(); it != q.end(); ++it) {
        assert(*it == expected++);
    }

    // range-based for
    expected = 0;
    for (int v : q) {
        assert(v == expected++);
    }
}


/* ============================================================
   Const Iterator Test
   ============================================================ */

void test_const_iterator() {
    Queue<int> q;
    for (int i = 0; i < 5; ++i)
        q.push(i);

    const Queue<int>& cq = q;

    int expected = 0;
    for (auto it = cq.cbegin(); it != cq.cend(); ++it) {
        assert(*it == expected++);
    }
}


/* ============================================================
   Clear Test
   ============================================================ */

void test_clear() {
    Queue<int> q;
    for (int i = 0; i < 10; ++i)
        q.push(i);

    q.clear();
    assert(q.isEmpty());
}


/* ============================================================
   Lifetime Test (Memory Safety)
   ============================================================ */

void test_lifetime() {
    Tracked::reset();

    {
        Queue<Tracked> q;
        q.emplace(1);
        q.emplace(2);
        q.emplace(3);
    }

    assert(Tracked::constructions == Tracked::destructions);
}


/* ============================================================
   Stress Test
   ============================================================ */

void stress_test() {
    Queue<int> q;

    for (int i = 0; i < 100000; ++i)
        q.push(i);

    for (int i = 0; i < 100000; ++i)
        q.pop();

    assert(q.isEmpty());
}


/* ============================================================
   MAIN
   ============================================================ */

int main() {

    test_basic_push_pop();
    test_capacity_limits();
    test_underflow();
    test_copy_constructor();
    test_copy_assignment();
    test_move_constructor();
    test_move_assignment();
    test_self_assignment();
    test_iterator();
    test_const_iterator();
    test_clear();
    test_lifetime();
    stress_test();

    std::cout << "All Advanced Tests Passed Successfully!\n";
}
