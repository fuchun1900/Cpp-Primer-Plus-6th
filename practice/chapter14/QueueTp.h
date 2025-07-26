# ifndef QUEUETP_H_
# define QUEUETP_H_
#include <iostream>
#include <string>

template <typename T>
class QueueTp {
private:
    const int LEN = 10;
    T * data;
    int top;
public:
    QueueTp()
        : data(new T[LEN]), top(0) {}
    QueueTp(int len)
        : data(new T[len]), top(0) {}
    QueueTp(const QueueTp & q)
        : data(new T[q.LEN]), top(q.top) {
        for (int i = 0; i < top; ++i) {
            data[i] = q.data[i];
        }
    }
    QueueTp & operator=(const QueueTp & q) {
        if (this == &q) {
            return *this; // handle self-assignment
        }
        delete[] data; // free existing memory
        data = new T[q.LEN]; // allocate new memory
        top = q.top;
        for (int i = 0; i < top; ++i) {
            data[i] = q.data[i];
        }
        return *this;
    }
    ~QueueTp() {
        delete[] data;
    }
    bool isFull() const {
        return top >= LEN;
    }
    bool isEmpty() const {
        return top == 0;
    }
    bool enqueue(const T & item);
    bool dequeue(T & item);
    T & front() const;
    T & back() const;
};
#endif // QUEUETP_H_

template <typename T>
bool QueueTp<T>::enqueue(const T & item) {
    if (isFull()) {
        return false; // queue is full
    }
    data[top++] = item; // add item to the queue
    return true;
}
template <typename T>
bool QueueTp<T>::dequeue(T & item) {
    if (isEmpty()) {
        return false; // queue is empty
    }
    item = data[0]; // get the front item
    for (int i = 1; i < top; ++i) {
        data[i - 1] = data[i]; // shift items left
    }
    --top; // decrease the count of items
    return true;
}
template <typename T>
T & QueueTp<T>::front() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data[0]; // return the front item
}
template <typename T>
T & QueueTp<T>::back() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data[top - 1]; // return the back item
}

