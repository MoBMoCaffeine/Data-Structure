#include "linked_List_Stack.h"
using namespace ds::llist;

template <typename T>
Queue<T>::Queue(size_type capacity) noexcept : head_(nullptr), tail_(nullptr), size_(0),  capacity_(capacity) {}

template <typename T>
Queue<T>::~Queue() noexcept {
    clear();
}

template <typename T>
template <typename... Args>
typename Queue<T>::Node*
    Queue<T>::create_node(Args&&... args) {
    return new Node(std::forward<Args>(args)...);
}

template <typename T>
void Queue<T>::destroy_node(Node* node) noexcept {
    delete node;
}

template<typename T>
void Queue<T>::copy_from(const Queue &other) {
    Queue temp(other.capacity_);

    for (Node* cur = other.head_; cur; cur = cur->next)
        temp.push(cur->data);

    swap(temp);
}

template<typename T>
Queue<T>::Queue(const Queue & other) : Queue(other.capacity_) {
    copy_from(other);
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue & other) {
    if (this != &other) {
        Queue temp(other);
        swap(temp);
    }
    return *this;
}

template<typename T>
void Queue<T>::move_from(Queue &&other) noexcept {
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;
    capacity_ = other.capacity_;

    other.head_ = other.tail_ = nullptr;
    other.size_ = 0;
}

template<typename T>
Queue<T>::Queue(Queue &&other) noexcept {
    move_from(std::move(other));
}

template<typename T>
Queue<T> &Queue<T>::operator=(Queue &&other) noexcept {
    if (this != &other) {
        clear();
        move_from(std::move(other));
    }
    return *this;
}

template<typename T>
bool Queue<T>::isEmpty() const noexcept {
    return size_ == 0;
}

template<typename T>
bool Queue<T>::isFull() const noexcept {
    return capacity_ && size_ >= capacity_;
}


template<typename T>
typename Queue<T>::size_type Queue<T>::size() const noexcept {
    return size_;
}

template<typename T>
typename Queue<T>::size_type Queue<T>::capacity() const noexcept {
    return capacity_;
}

template<typename T>
typename Queue<T>::reference Queue<T>::front() {
    if (isEmpty()) throw std::out_of_range("Queue is empty!");
    return head_->data;
}

template<typename T>
typename Queue<T>::const_reference Queue<T>::front() const {
    if (isEmpty()) throw std::out_of_range("Queue is empty!");
    return head_->data;
}

template<typename T>
typename Queue<T>::reference Queue<T>::back() {
    if (isEmpty()) throw std::out_of_range("Queue is empty!");
    return tail_->data;
}

template<typename T>
typename Queue<T>::const_reference Queue<T>::back() const {
    if (isEmpty()) throw std::out_of_range("Queue is empty!");
    return tail_->data;
}

template<typename T>
void Queue<T>::push(const T &value) {
    if (isFull()) throw std::overflow_error("Queue is full!");

    Node* new_node = create_node(value);

    if (isEmpty()) {
        head_ = tail_ = new_node;
    } else {
        tail_->next = new_node;
        tail_ = new_node;
    }

    ++size_;

}

template<typename T>
auto Queue<T>::push(T &&value) -> void {
    if (isFull()) throw std::overflow_error("Queue is full!");

    Node* new_node = create_node(std::move(value));

    if (isEmpty()) {
        head_ = tail_ = new_node;
    } else {
        tail_->next = new_node;
        tail_ = new_node;
    }

    ++size_;
}


template<typename T>
template<typename... Args>
void Queue<T>::emplace(Args &&... args) {
    if (isFull()) throw std::overflow_error("Queue is full!");

    Node* new_node = create_node(std::forward<Args>(args)...);

    if (isEmpty()) head_ = tail_ = new_node;
    else {
        tail_->next = new_node;
        tail_ = new_node;
    }
    ++size_;
}

template<typename T>
void Queue<T>::pop() {
    if (isEmpty()) throw std::underflow_error("Queue is empty!");

    Node* old_head = head_;
    head_ = head_->next;

    destroy_node(old_head);
    --size_;

    if (!size_) tail_ = nullptr;
}

template<typename T>
void Queue<T>::clear() noexcept {
    Node* current = head_;
    while (current) {
        Node* next = current->next;
        destroy_node(current);
        current = next;
    }
    head_ = tail_ = nullptr;
    size_ = 0;
}

template<typename T>
void Queue<T>::swap(Queue &other) noexcept {
    using std::swap;
    swap(head_, other.head_);
    swap(tail_, other.tail_);
    swap(capacity_, other.capacity_);
    swap(size_, other.size_);
}

template<typename T>
class Queue<T>::iterator {
    Node* current_;
public:
    using iterator_category     = std::forward_iterator_tag;
    using value_type            = T;
    using reference             = T&;
    using pointer               = T*;
    using difference_type       = std::ptrdiff_t;


    iterator(Node* ptr = nullptr) : current_(ptr) {}

    reference operator*() const { return current_->data; }
    pointer operator->() const { return &current_->data; }

    iterator& operator++() {
        current_ = current_->next;
        return *this;
    }

    bool operator==(const iterator& other) const {
        return current_ == other.current_;
    }

    bool operator!=(const iterator& other) const {
        return current_ != other.current_;
    }

    iterator operator++(int) {
        iterator tmp = *this;
        ++(*this);
        return tmp;
    }

};

template<typename T>
typename Queue<T>::iterator Queue<T>::begin() noexcept {
    return iterator(head_);
}

template<typename T>
typename Queue<T>::iterator Queue<T>::end() noexcept {
    return iterator(nullptr);
}

template<typename T>
class Queue<T>::const_iterator {
    const Node* current_;
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type        = T;
    using reference         = const T&;
    using pointer           = const T*;
    using difference_type   = std::ptrdiff_t;


    const_iterator(const Node* ptr = nullptr)
        : current_(ptr) {}

    reference operator*() const { return current_->data; }
    pointer operator->() const { return &current_->data; }

    const_iterator& operator++() {
        current_ = current_->next;
        return *this;
    }

    const_iterator operator++(int) {
        const_iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator==(const const_iterator& other) const {
        return current_ == other.current_;
    }

    bool operator!=(const const_iterator& other) const {
        return current_ != other.current_;
    }
};

template<typename T>
typename Queue<T>::const_iterator
Queue<T>::begin() const noexcept {
    return const_iterator(head_);
}

template<typename T>
typename Queue<T>::const_iterator
Queue<T>::end() const noexcept {
    return const_iterator(nullptr);
}

template<typename T>
typename Queue<T>::const_iterator Queue<T>::cbegin() const noexcept { return const_iterator(head_); }

template<typename T>
typename Queue<T>::const_iterator Queue<T>::cend() const noexcept  { return const_iterator(nullptr); }











