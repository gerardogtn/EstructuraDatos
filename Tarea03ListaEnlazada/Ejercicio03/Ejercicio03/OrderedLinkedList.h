//
//  OrderedLinkedList.h
//  Ejercicio03
//
//  Created by Gerardo Teruel on 3/6/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef Ejercicio03_OrderedLinkedList_h
#define Ejercicio03_OrderedLinkedList_h
#include "LinkedList.h"

namespace vcn {
    
    template <class T>
    class OrderedLinkedList : public LinkedList<T> {
        Node<T> * _first = nullptr;
        int _size = 0;
        
        class Iterator {
            LinkedList<T> * _data;
            int _position;
            
        public:
            Iterator(LinkedList<T> * _adata, int _aposition)
            : _data(_adata), _position(_aposition) {}
            
            Node<T> operator *() const { return *(_data->at(_position)); }
            const  Iterator & operator ++() { ++_position; return *this; }
            bool operator != (const Iterator & it) const { return _position != it._position; }
        };
        
    public:
        OrderedLinkedList() {}
        virtual ~OrderedLinkedList();
        
        Node<T> * first();
        int size();
        bool empty();
        
        void insert(T, int);
        
        Node<T> * remove(int);
        Node<T> *  removeFront();
        Node<T> *  removeBack();
        
        void clear();
        
        Node<T> *  at(int);
        int at(Node<T> *);
        
        template <typename Tn>
        friend std::ostream & operator <<(std::ostream &, LinkedList<Tn> &);
        
        Iterator begin() { return { this, 0}; }
        Iterator end() {return {this, _size }; }
        
        Node<T> * operator [](const int);
        
    };
    
    template <typename T>
    OrderedLinkedList<T>::~OrderedLinkedList(){
        LinkedList<T>::clear();
    }
    
    template <typename T>
    Node<T> * OrderedLinkedList<T>::first(){
        LinkedList<T>::first();
    }
    
    template <typename T>
    int OrderedLinkedList<T>::size(){
        LinkedList<T>::size();
    }
    
    template <typename T>
    bool OrderedLinkedList<T>::empty(){
        LinkedList<T>::empty();
    }
    
    // TODO:
    template <typename T>
    void OrderedLinkedList<T>::insert(T element, int position){
        LinkedList<T>::insert();
    }
    
    template <typename T>
    Node<T> * remove(int position){
        LinkedList<T>::remove(position);
    }
    
    template <typename T>
    Node<T> *  removeFront(){
        LinkedList<T>::removeFront();
    }
    
    template <typename T>
    Node<T> *  removeBack(){
        LinkedList<T>::removeBack();
    }
    
    template <typename T>
    void clear(){
        LinkedList<T>::clear();
    }
    
    template <typename T>
    Node<T> *  at(int position){
        LinkedList<T>::at(position);
    }
    
    template <typename T>
    int at(Node<T> * node){
        LinkedList<T>::at(node);
    }
    
    template <typename T>
    std::ostream & operator <<(std::ostream & os, OrderedLinkedList<T> & list)
    {
        for (auto node : list )
        {
            os << node << std::endl;
        }
        
        return os;
    }

    template <typename T>
    Node<T> * OrderedLinkedList<T>::operator [](const int position)
    {
        return at(position);
    }
    
    }


#endif
