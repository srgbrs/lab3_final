#ifndef QueueHeader_h
#define QueueHeader_h

#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue {
    struct elem {
        T data;
        elem *next;
    };
    elem *top;
    
public:
    Queue();
    Queue(const T &obj);
    ~Queue();
    void push(T value);
    void pop();
    bool empty();
    void print();
    T front();
};

template <typename T>
Queue<T>::Queue() {
    top = NULL;
}

template <typename T>
Queue<T>::Queue(const T &obj) {
    this->top = NULL;
}

template <typename T>
Queue<T>::~Queue()
{
    while (top) {
        if (!top->next) {
            top = NULL;
            break;
        }
        elem *del = top;
        top = top->next;
        delete del;
    }
}

template <typename T>
void Queue<T>::push(T value)
{
    elem *tmp = new elem;
    tmp->data = value;
    tmp->next = top;
    top = tmp;
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) {
        cout << "Queue is empty\n";
        return;
    }
    if (!top->next) {
        top = NULL;
        return;
    }
    elem *prev = top;
    elem *end = top;
    while (end->next) {
        prev = end;
        end = end->next;
    }
    prev->next = NULL;
    delete end;
}

template <typename T>
bool Queue<T>::empty() {
    if (top == NULL) {
        return true;
    }
    return false;
}

template <typename T>
void Queue<T>::print() {
    elem *current = top;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
T Queue<T>::front() {
    if (empty()) {
        cout << "Queue is empty.\n";
        return 0;
    }
    else {
        elem *end;
        end = top;
        while (end->next) {
            end = end->next;
        }
        return end->data;
    }
}



#endif /* QueueHeader_h */
