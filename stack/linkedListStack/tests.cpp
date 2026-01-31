//
// Created by Mohamed Bakr on 1/30/2026.
//

#include "linked_List_Stack.h"
#include <cassert>
#include <iostream>

void testPushAndSize() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    assert(s.size() == 3);
    assert(s.peek() == 3);
}

void testPop() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.pop();

    assert(s.size() == 1);
    assert(s.peek() == 10);
}

void testExceptions() {
    Stack<int> s;

    try {
        s.pop();
        assert(false); // لازم ميوصلش هن
    } catch (const std::underflow_error&) {
        assert(true);
    }

    try {
        s.peek();
        assert(false);
    } catch (const std::runtime_error&) {
        assert(true);
    }
}

void testClear() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.clear();

    assert(s.isEmpty());
    assert(s.size() == 0);
}

int main() {
    testPushAndSize();
    testPop();
    testExceptions();
    testClear();

    std::cout << "All Stack tests passed successfully!\n";
    return 0;
}
