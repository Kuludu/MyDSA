#include "MyStack.h"
using namespace MyStackNamespace;

template <class T>
MyStack<T>::MyStack() {
    top_element = root_element;
}

template <class T>
MyStack<T>::~MyStack() {
    while ( top_element != root_element ) {
        Element<T> *prev_element = top_element->prev;
        delete top_element;
        top_element = prev_element;
    }
    
    delete top_element;
}

template <class T>
unsigned int MyStack<T>::size() const {
    return stack_size;
}

template <class T>
bool MyStack<T>::isempty() const {
    if ( stack_size == 0 )
        return true;
    else
        return false;
}

template <class T>
void MyStack<T>::push(const T &x) {
    ++stack_size;
    Element<T> *push_element = new Element<T>;
    push_element->value = x;
    push_element->prev = top_element;
    top_element = push_element;
}

template <class T>
bool MyStack<T>::pop() {
    if ( stack_size <= 0 )
        return false;
    else {
        --stack_size;
        Element<T>* prev_element = top_element->prev;
        delete top_element;
        top_element = prev_element;
    }

    return true;
}

template <class T>
T MyStack<T>::top() const {
    return top_element->value;
}
