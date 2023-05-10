#ifndef GENERICSTACK_H
#define GENERICSTACK_H

#include <iostream>
//#include <BasicContainer.h>

template<typename T>
class GenericStack// : public BasicContainer<T>
{
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    GenericStack();

    ~GenericStack();

    GenericStack(const GenericStack<T>& other);

    GenericStack<T>& operator=(const GenericStack<T>& other);

    bool empty() const;

    void push(const T& x);

    void pop();

    T& top();

    const T& top() const;

    int size() const;

    void print(std::ostream& os, char ofc = '\0') const;

    friend std::ostream& operator<<(std::ostream& os, const GenericStack<T>& a);

    friend bool operator==(const GenericStack<T>& a, const GenericStack<T>& b);

    friend bool operator<(const GenericStack<T>& a, const GenericStack<T>& b);
};


#endif // GENERICSTACK_H

