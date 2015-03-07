//
//  LinkedList.h
//  LinkedList
//
//  Created by Gerardo Teruel on 2/28/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef LinkedList_LinkedList_h
#define LinkedList_LinkedList_h

#include "Node.h"

namespace vcn {
    
    template <class T>
    class LinkedList{
        
    private:
        Node<T> * _first = nullptr;
        int _size = 0;
        
        
        class LinkedListIterator{
            
        private:
            LinkedList<T> * _data;
            int _position;
            
            
        public:
            // NOT A BIG FAN OF THIS NOTATION.
            Iterator(LinkedList<T> * _adata, int _aposition)
            : _data(_adata), _position(_aposition) {}
            
            
            Node<T> operator *() {
                return *(_adata->at(_position));
            }
            
            const Iterator & operator ++() {
                ++_position;
                return *this;
            }
            
            bool operator !=(const Iterator & it) const {
                return _position != it._position;
            }
        }
        
        
        
    public:
        LinkedList(){};
        virtual ~LinkedList(){};
        
        Node<T> * getFirst();
        int size();
        bool empty?();
        
        void insert(const T valueToInsert, const int position);
        void insert(const Node<T> * nodeToInsert, const int position);
        void insertFront(const T valueToInsert, const int position);
        void insertFront(const Node<T> * nodeToInsert);
        void insertBack(const T valueToInsert);
        void insertBack(const Node<T> * nodeToInsert);
        
        Node<T> * remove(const int position);
        Node<T> * removeFront();
        Node<T> * removeBack();
        
        void clear();
        
        Node<T> * at(const int);
        int at(const Node<T> *);
        
        template <typename Tn>
        friend std::ostream & operator <<(std::ostream &, LinkedList<Tn> &);
        
        
        Iterator begin() {
            return {this, 0}
        }
        
        Iterator end() {
            // INITIALIZATION CONSTRUCTOR.
            // YOU CAN INITIALIZE AN OBJECT AS IF IT WAS AN ARRAY.
            // C++ AUTOMATICALLY IDENTIFIES THE RETURN TYPE AND CREATES AN INSTANCE OF THAT TYPE
            // WITH THE VALUES PASSED AS PARAMETERS IN THE INITIALIZATION CONSTRUCTOR.
            return {this, _size}
        }
        
        Node<T> * operator [](const int);
    };
    
    
    template <class T>
    LinkedList<T>::~LinkedList(){}{
        
    }
    
    template <class T>
    Node<T> * LinkedList<T>::getFirst(){
        
    }
    
    template <class T>
    int LinkedList<T>::size(){
        
    }
    
    template <class T>
    bool LinkedList<T>::empty?(){
        
    }
    
    
    template <class T>
    void LinkedList<T>::insert(const T valueToInsert, const int position){
        
    }
    
    template <class T>
    void LinkedList<T>::insert(const Node<T> * nodeToInsert, const int position){
        
    }
    
    template <class T>
    void LinkedList<T>::insertFront(const T valueToInsert, const int position){
        
    }
    
    template <class T>
    void LinkedList<T>::insertFront(const Node<T> * nodeToInsert){
        
    }
    
    template <class T>
    void LinkedList<T>::insertBack(const T valueToInsert){
        
    }
    
    template <class T>
    void LinkedList<T>::insertBack(const Node<T> * nodeToInsert){
        
    }
    
    
    template <class T>
    Node<T> * LinkedList<T>::remove(const int position){
        
    }
    
    template <class T>
    Node<T> * LinkedList<T>::removeFront(){
        
    }
    
    template <class T>
    Node<T> * LinkedList<T>::removeBack(){
        
    }
    
    
    template <class T>
    void LinkedList<T>::clear(){
        
    }
    
    
    template <class T>
    Node<T> * LinkedList<T>::at(const int){
        
    }
    
    template <class T>
    int LinkedList<T>::at(const Node<T> *){
        
    }
    
    template <class Tn>
    std::ostream & operator <<(std::ostream &, LinkedList<Tn> &){
        
    }
    
    
    
    
}


#endif
