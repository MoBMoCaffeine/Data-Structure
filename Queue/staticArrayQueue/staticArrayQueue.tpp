
#include <stdexcept>

namespace ds {
    namespace Static {
        template<typename T>
        Queue<T>::Queue() {
            size_ = 0;
            front_ = -1;
            rear_ = -1;
        }
        template<typename T>
        Queue<T>::~Queue() {

        }

        template<typename T>
        bool Queue<T>::isEmpty() {
            return size_ == 0;/***(front_ == -1 || front_ > rear_)*/;
        }
        template<typename T>
        bool Queue<T>::isFull() {
            return rear_ == MAX_SIZE - 1;
            // return size_ == MAX_SIZE;
        }

        template<typename T>
        void Queue<T>::enqueue(T value) {
            if (isFull())
                throw std::overflow_error("Queue is full!");
            if (isEmpty())
                front_ = rear_ = 0;
            queueArray[++rear_] = value;
            ++size_;
        }
        template<typename T>
        T Queue<T>::dequeue() {
            if (isEmpty())
                throw std::underflow_error("Queue is empty!");
            T value = queueArray[front_++];
            --size_;
            if (front_ > rear_)
                front_ = rear_ = -1;
            return value;
        }

        template<typename T>
        T Queue<T>::front() {
            if (isEmpty())
                throw std::underflow_error("Queue is empty!");
            return queueArray[front_];
        }
        template<typename T>
        T Queue<T>::rear() {
            if (isEmpty())
                throw std::underflow_error("Queue is empty!");
            return queueArray[rear_];
        }

        template<typename T>
        int Queue<T>::size() {
            return size_;
        }
    }
}

