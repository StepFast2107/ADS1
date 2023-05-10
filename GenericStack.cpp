#include "GenericStack.h"

template<typename T>
GenericStack<T>::GenericStack()   {
    capacity = 10;
    topIndex = -1;
    arr = new T[capacity];    
}

template<typename T>
GenericStack<T>::~GenericStack() {
    delete[] arr;
}

template<typename T>
GenericStack<T>::GenericStack(const GenericStack<T>& other) : capacity(other.capacity), topIndex(other.topIndex) {
    arr = new T[capacity];
    std::copy(other.arr, other.arr + capacity, arr);
}

template<typename T>
GenericStack<T>& GenericStack<T>::operator=(const GenericStack<T>& other) {
    if (this != &other) {
        delete[] arr;

        capacity = other.capacity;
        topIndex = other.topIndex;
        arr = new T[capacity];
        std::copy(other.arr, other.arr + capacity, arr);
    }
    return *this;
}

template<typename T>
bool GenericStack<T>::empty() const {
    return topIndex == -1;
}

template<typename T>
void GenericStack<T>::push(const T& x) {
    if (topIndex + 1 >= capacity) {
        T* newArr = new T[capacity * 2];
        std::copy(arr, arr + capacity, newArr);
        delete[] arr;
        arr = newArr;
        capacity *= 2;
    }

    arr[++topIndex] = x;
}

template<typename T>
void GenericStack<T>::pop() {
    if (!empty()) {
        --topIndex;
    }
}

template<typename T>
T& GenericStack<T>::top() {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return arr[topIndex];
}

template<typename T>
const T& GenericStack<T>::top() const {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return arr[topIndex];
}

template<typename T>
int GenericStack<T>::size() const {
    return topIndex + 1;
}

template<typename T>
void GenericStack<T>::print(std::ostream& os, char ofc) const {
    for (int i = 0; i <= topIndex; ++i) {
        os << arr[i];
        if (ofc != '\0' && i < topIndex) {
            os << ofc;
        }
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const GenericStack<T>& a) {
    a.print(os);
    return os;
}

template<typename T>
bool operator==(const GenericStack<T>& a, const GenericStack<T>& b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); ++i) {
        if (a.arr[i] != b.arr[i]) {
            return false;
        }
    }

    return true;
}

template<typename T>
bool operator<(const GenericStack<T>& a, const GenericStack<T>& b) {
    int size = std::min(a.size(), b.size());

    for (int i = 0; i < size; ++i) {
        if (a.arr[i] >= b.arr[i]) {
            return false;
        }
    }

    return a.size() < b.size();
}



