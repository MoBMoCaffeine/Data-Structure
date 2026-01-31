#ifndef  STACK_TPP
#define STACK_TPP

#include <stdexcept>

template<typename T>
Stack<T>::Stack(size_t initialCapacity) : _capacity(initialCapacity), _topIndex(0) {
    _data = new T[_capacity];
}

template<typename T>
Stack<T>::~Stack() {
    delete[] _data;
}

template<typename T>
void Stack<T>::Resize() {
    _capacity *= 2;
    T* newData = new T[_capacity];
    for (size_t i = 0; i < _topIndex; i++) {
        newData[i] = _data[i];
    }
    delete[] _data;
    _data = newData;
}
template<typename T>
void Stack<T>::push(const T &value) {
    if (_topIndex == _capacity) {
        Resize();
    }
    _data[_topIndex++] = value;
}

template<typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("pop() called on an empty stack!");
    }
    --_topIndex;
}

template<typename T>
T &Stack<T>::top() {
    if (isEmpty()) {
        throw std::out_of_range("top() called on an empty stack!");
    }
    return _data[_topIndex - 1];
}

template<typename T>
const T &Stack<T>::top() const {
    if (isEmpty()) {
        throw std::out_of_range("top() called on an empty stack!");
    }
    return _data[_topIndex - 1];
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return _topIndex == 0;
}

template<typename T>
size_t Stack<T>::size() const {
    return _topIndex;
}

// iterators
template<typename T>
class Stack<T>::iterator {
    T* _ptr;
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;

    explicit iterator(T* ptr) : _ptr(ptr) {}
    T& operator*() const { return *_ptr; }
    iterator& operator++() { --_ptr; return *this; }
    bool operator!=(const iterator& rhs) const { return _ptr != rhs._ptr; }
};

template<typename T>
class Stack<T>::const_iterator {
    const T* _ptr;
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;

    explicit const_iterator(const T* p) : _ptr(p) {}
    const T& operator*() const { return *_ptr; }
    const_iterator& operator++() { --_ptr; return *this; }
    bool operator!=(const const_iterator& other) const { return _ptr != other._ptr; }
};

template<typename T>
typename Stack<T>::iterator Stack<T>::begin() {
    return iterator(_data + _topIndex - 1);
}

template<typename T>
typename Stack<T>::iterator Stack<T>::end() {
    return iterator(_data - 1);
}

template<typename T>
typename Stack<T>::const_iterator Stack<T>::begin() const {
    return const_iterator(_data + _topIndex - 1);
}

template<typename T>
typename Stack<T>::const_iterator Stack<T>::end() const {
    return const_iterator(_data - 1);
}


#endif
