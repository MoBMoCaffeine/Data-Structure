
#ifndef LINKEDLISTSTACK_LINKED_LIST_STACK_TPP
#define LINKEDLISTSTACK_LINKED_LIST_STACK_TPP

template <typename T>
Stack<T>::Stack() : _top(nullptr), _size(0) {}

template <typename T>
Stack<T>::~Stack() {
    clear();
}
template <typename T>
void Stack<T>::push(const T& value) {
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->next = _top;
    _top = newNode;
    ++_size;
}

template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack Underflow: coannot pop from empty stack!");
    }
    Node<T>* temp = _top;
    _top = _top->next;
    delete temp;
    --_size;
}

template <typename T>
const T& Stack<T>::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty: no top element!");
    }
    return _top->data;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return _top == nullptr;
}

template <typename T>
size_t Stack<T>::size() const {
    return _size;
}

template <typename T>
void Stack<T>::clear() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void Stack<T>::display() const {
    Node<T>* temp = _top;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

#endif