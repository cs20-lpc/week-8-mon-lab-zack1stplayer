#include "ArrayStack.hpp"

template <typename T>
ArrayStack<T>::ArrayStack(int i) : Stack<T>::Stack() {
    this->maxSize = i;
    this->buffer = new T[this->maxSize];
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    this->length = 0;
    if (this->buffer != nullptr) {
        delete[] this->buffer;
        this->buffer = nullptr;
    }
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    this->length = 0;
    this->maxSize = copyObj.maxSize;
    this->buffer = new T[this->maxSize];
    while (this->length < copyObj.length) {
        this->buffer[this->length++] = copyObj.buffer[this->length];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    if (isEmpty()) {
        throw string("peek(): Stack is empty, could not peek top value");
    }
    return this->buffer[this->length - 1];
}

template <typename T>
void ArrayStack<T>::pop() {
    if (isEmpty()) {
        throw string("pop(): Stack is empty, could not pop top value");
    }
    this->buffer[--this->length] = T();
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    if (isFull()) {
        throw string("push(): Stack is full, could not push new value");
    }
    if (this->buffer == nullptr) {
        this->buffer = new T[this->maxSize];
    }
    this->buffer[this->length++] = elem;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    if (isEmpty()) {
        throw string("rotate(): Stack is empty, could not rotate");
    }
    
    switch (dir) {
    case Stack<T>::LEFT:
        rotateLeft();
        break;
    case Stack<T>::RIGHT:
        rotateRight();
        break;
    
    default:
        break;
    }
}

template <typename T>
void ArrayStack<T>::rotateLeft() {
    T tempVar = this->buffer[this->length - 1];
    for (int i = (this->length - 1); i > 0; i--) {
        this->buffer[i] = this->buffer[i - 1];
    }
    this->buffer[0] = tempVar;
}

template <typename T>
void ArrayStack<T>::rotateRight() {
    T tempVar = this->buffer[0];
    for (int i = 0; i < (this->length - 1); i++) {
        this->buffer[i] = this->buffer[i + 1];
    }
    this->buffer[this->length - 1] = tempVar;
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}

