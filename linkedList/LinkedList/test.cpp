//
// Created by Mohamed Bakr on 3/6/2026.
//

#include<iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list;

    list.insertFront(20);
    list.insertFront(10);
    list.insertBack(70);
    list.insertBack(80);
    list.insertAt(30, 2);
    list.insertAt(40, 3);
    list.insertAt(50, 4);
    list.insertAt(60, 5);

    list.print();

    list.deleteFront();
    list.print();
    list.deleteBack();
    list.print();
    list.deleteAt(2);
    list.print();
}