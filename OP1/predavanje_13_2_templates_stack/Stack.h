//
// Created by Marta on 09/09/2016.
//

#pragma once

#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    T *pstack;
    int size;
    int index;

    static const int max = 50;
public:
    Stack();
    Stack(int size);

    bool push(T&);
    bool pop();
    bool isFull() const;
    bool isEmpty() const;

    void printStack();

    ~Stack();
};

template <class T>
Stack<T>::Stack() {
    this->size = 10;
}

template <class T>
Stack<T>::Stack(int size) {
    this->size = (size > 0 && size < max) ? size : 10;
    index = -1;

    pstack = new T[size];
}

template <class T>
bool Stack<T>::push(T &element) {
    if(!isFull()) {
        pstack[++index] = element;
        return true;
    }
    return false;
}

template <class T>
bool Stack<T>::pop() {
    if(!isEmpty()) {
        pstack[index--];
        return true;
    }
    return false;
}

template <class T>
bool Stack<T>::isFull() const {
    return index == size - 1;
}

template <class T>
bool Stack<T>::isEmpty() const {
    return index == -1;
}

template <class T>
void Stack<T>::printStack() {
    for(int i=0; i<=this->index; i++) {
        cout << this->pstack[i] << " ";
    }

    cout << endl;
}

template <class T>
Stack<T>::~Stack() {
    delete [] pstack;
}