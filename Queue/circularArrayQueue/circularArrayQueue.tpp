
template<typename T>
void Queue<T>::alloc(size_t cap) {
    _data = new T[cap];
    _capacity = cap;
    _size = 0;
    _rear = cap - 1;
    _front = 0;
}

template<typename T>
Queue<T>::Queue(size_t capacity) {
    if (capacity <= 0) throw std::invalid_argument("capacity must be greater than 0!");
    alloc(capacity);
}

template<typename T>
Queue<T>::~Queue() {
    delete[] _data;
}

template<typename T>
Queue<T>::Queue(const Queue &other) {
    alloc(other._capacity);
    _front = other._front;
    _rear = other._rear;
    _size = other._size;
    _capacity = other._capacity;

    for (int i = 0; i < _capacity; ++i) _data[i] = other._data[i];
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue &other) {
    if (this != &other) return *this;

    Queue temp(other);
    swap(temp);
    return *this;
}

template<typename T>
Queue<T>::Queue(Queue &&other) noexcept
:_data(other._data)
,_front(other._front)
,_rear(other._rear)
,_capacity(other._capacity)
,_size(other._size) {
    other._data = nullptr;
    other._front = other._rear = 0;
}

template<typename T>
Queue<T> &Queue<T>::operator=(Queue &&other) noexcept {
    if (this == &other) return *this;

    delete[] _data;
    _data = other._data;
    _front = other._front;
    _rear = other._rear;
    _capacity = other._capacity;
    _size = other._size;

    other._data = nullptr;
    other._front = other._rear = 0;

    return *this;
}

template<typename T>
bool Queue<T>::isEmpty() const noexcept {
    return _size == 0;
}

template<typename T>
bool Queue<T>::isFull() const noexcept {
    return _size == _capacity;
}


template<typename T>
size_t Queue<T>::size() const noexcept {
    return _size;
}

template<typename T>
size_t Queue<T>::capacity() const noexcept {
    return _capacity;
}

template<typename T>
T &Queue<T>::front() {
    if (isEmpty()) throw std::underflow_error("front on empty Queue!");

    return _data[_front];
}

template<typename T>
T &Queue<T>::rear() {
    if (isEmpty()) throw std::underflow_error("rear on empty Queue!");

    return _data[_rear];
}

template<typename T>
const T &Queue<T>::front() const {
    if (isEmpty()) throw std::underflow_error("front on empty Queue!");

    return _data[_front];
}


template<typename T>
const T &Queue<T>::rear() const {
    if (isEmpty()) throw std::underflow_error("rear on empty Queue!");

    return _data[_rear];
}

template<typename T>
void Queue<T>::enqueue(const T &value) {
    if (isFull()) throw std::overflow_error("enqueue on full Queue!");

    _rear = (_rear + 1) % _capacity;
    _data[_rear] = value;
    ++_size;
}

template<typename T>
void Queue<T>::dequeue() {
    if (isEmpty()) throw std::underflow_error("dequeue on empty Queue!");

    _front = (_front + 1) % _capacity;
    --_size;
}

template<typename T>
void Queue<T>::clear() noexcept {
    _front = _size = 0;
    _rear = _capacity - 1;
}

template<typename T>
void Queue<T>::swap(Queue &other) noexcept {
    std::swap(_data, other._data);
    std::swap(_capacity, other._capacity);
    std::swap(_size, other._size);
    std::swap(_rear, other._rear);
    std::swap(_front, other._front);
}

template<typename T>
template<typename... Args>
void Queue<T>::emplace(Args &&... args) {
    if (isFull()) throw std::overflow_error("emplace on full Queue!");

    _rear = (_rear + 1) % _capacity;
    _data[_rear] = T(std::forward<Args>(args)...);
    ++_size;
}










