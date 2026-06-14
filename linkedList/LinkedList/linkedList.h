//
// Created by Mohamed Bakr on 3/6/2026.
//

#ifndef DS_LINKEDLIST_H
#define DS_LINKEDLIST_H
#include <iostream>
#include <stdexcept>

template<typename T>
struct Node {
    T data;
    Node<T> *next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template<typename T>
class LinkedList {
    Node<T> *head;
    Node<T> *tail;
    int     size;

public:
    LinkedList() {
        head = tail = nullptr;
        size = 0;
    }

    ~LinkedList() {
       clear();
    }

    bool isEmpty() {
        return head == nullptr;
        // return size == 0;
    }

    int getSize() const {
        return size;
    }

    void insertFront(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

        ++size;
    }

    void insertBack(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
        }

        ++size;
    }

    void insertAt(T data, int position) {
        if (position < 0 or position > size)
            throw std::out_of_range("Position out of range!");

        if (position == 0) {
            insertFront(data);
            return;
        }

        if (position == size) {
            insertBack(data);
            return;
        }
        Node<T> *newNode = new Node<T>(data);
        Node<T> *current = head;

        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        ++size;
    }

    void deleteFront() {
        if (isEmpty())
            throw std::out_of_range("List is empty!");

        Node<T> *temp = head;
        head = head->next;

        delete temp;
        --size;

        if (size == 0) tail = nullptr;
    }
    void deleteBack() {
        if (isEmpty())
            throw std::out_of_range("List is empty!");

        if (size == 1) {
            delete head;
            head = tail = nullptr;
            size = 0;
            return;
        }

        Node<T> *current = head;

        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;

        --size;
    }
    void deleteAt(int position) {
        if (position < 0 or position > size)
            throw std::out_of_range("Position out of range!");

        if (position == 0) {
            deleteFront();
            return;
        }

        if (position == size - 1) {
            deleteBack();
            return;
        }

        Node<T> *current = head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }

        Node<T> *temp = current->next;
        current->next = temp->next;

        delete temp;
        --size;
    }

    T getAt(int position) {
        if (position < 0 or position > size)
            throw std::out_of_range("Position out of range!");

        Node<T> *current = head;
        for (int i = 0; i < position; ++i) {
            current = current->next;
        }
        return current->data;
    }

    int search(T data) {
        Node<T> *current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == data)
                return index;

            current = current->next;
            ++index;
        }
        return -1;
    }
    void print() const {
        Node<T> *current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }
    void clear() {
        while (!isEmpty()) {
            deleteFront();
        }
    }
};
#endif //DS_LINKEDLIST_H
