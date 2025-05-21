#include "template.h"

template <class T> void Stack<T>::push(T item){
    stack_.push_back(item);
}

template <class T> T Stack<T>::pop(){
    return stack_.back();
}

template <class T> bool Stack<T>::empty(){
    return stack_.empty();
}

template <class T> int Stack<T>::size(){
    return stack_.size();
}