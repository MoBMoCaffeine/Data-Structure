//
// Created by Mohamed Bakr on 1/30/2026.
//

#include <cassert>
#include <iostream>
#include "stack.h"

void test_push_pop() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.pop();
    assert(s.top() == 1);
}

void test_iterator() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    int expected[] = {30, 20, 10};
    int i = 0;

    for (int x : s) {
        assert(x == expected[i++]);
    }
}

int main() {
    test_push_pop();
    test_iterator();
    std::cout << "All tests passed!\n";
}
