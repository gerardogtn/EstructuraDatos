//
//  Stack.h
//  Stack
//
//  Created by Gerardo Teruel on 3/19/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef Stack_Stack_h
#define Stack_Stack_h

#include "Node.h"
#include "LinkedList.h"


namespace vcn{

template <class T>
class Stack : private LinkedList<T> {
    
public:
    Stack() {};
    virtual ~Stack();
    
    int size();
    bool isEmpty();
    
    Node<T> * top();
    Node<T> * pop();
    void push(T);
    void push(Node<T> *);
    
    template<typename Tn>
    friend std::ostream & operator <<(std::ostream &, Stack<Tn> &);
    
};

template<typename T>
Stack<T>::Stack() : LinkedList<T>(){
    
}

template<typename T>
Stack<T>::~Stack(){
    this->clear();
}

template<typename T>
int Stack<T>::size(){
    
}

template<typename T>
bool Stack<T>::isEmpty(){
    return LinkedList<T>::isEmpty();
}

template<typename T>
Node<T> * top(){
    return this->first();
}

template<typename T>
Node<T> * pop(){
    return this->removeFront();
    
}

template<typename T>
void Stack<T>::push(T value){
    this->insertFront(value);
}

template<typename T>
void Stack<T>::push(Node<T> * node){
    this->insertFront(node);
    

}

template<typename T>
std::ostream & operator <<(std::ostream & os, Stack<T> & stack){
    
    for(auto i :stack){
        os << i;
    }
    
    return os;
}


}

#endif
