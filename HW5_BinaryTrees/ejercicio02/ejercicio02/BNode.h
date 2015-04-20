//
//  BNode.h
//  BinaryTree
//
//  Created by Vicente Cubells Nonell on 26/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef BinaryTree_BNode_h
#define BinaryTree_BNode_h

#include <iostream>

namespace vcn {
    
    template <class T>
    class BNode {
    private:
        BNode<T> * parent = nullptr;
        BNode<T> * left = nullptr;
        BNode<T> * right = nullptr;
        
        T info;
        
    public:
        
        /* Constructores */
        BNode() { }
        BNode(const T & _info) : info (_info) { }
        BNode(const BNode<T> & );
        
        /* Destructor */
        virtual ~BNode();
        
        T getInfo() const { return info; }
        void setInfo(const T & value) { info = value; }
        
        BNode<T> * getLeft() const { return left; }
        void setLeft(BNode<T> * value) { left = value; }
        
        BNode<T> * getRight() const { return right; }
        void setRight(BNode<T> * value) { right = value; }
        
        BNode<T> * getParent() const { return parent; }
        void setParent(BNode<T> * value) { parent = value; }
        
        template <typename Tn>
        friend std::ostream & operator << (std::ostream & os, const BNode<Tn>  & node);
        
        bool operator ==(const BNode<T> & other) const;
    };
    
    template <class T>
    BNode<T>::BNode(const BNode<T> & other)
    {
        info = other.info;
        left = other.left;
        right = other.right;
        parent = other.parent;
    }
    
    template <class T>
    BNode<T>::~BNode()
    {
        info.~T();
        left = right = parent = nullptr;
    }
    
    
    template <class T>
    std::ostream & operator << (std::ostream & os, const BNode<T>  & node)
    {
        os << node.info;
        
        return os;
    }
    
    
    template <class T>
    bool BNode<T>::operator ==(const BNode<T> & other) const{
        bool output;
        
        output = info == other.info; 
        
        /*
        if ((this->getLeft() == nullptr && other-getLeft() != nullptr) || (this->getLeft() != nullptr && other-getLeft() == nullptr)){
            output = false;
        } else if ((this->getRight() == nullptr && other-getRight() != nullptr) || (this->getRight() != nullptr && other-getRight() == nullptr)){
            output = false;
        } else if (this->getLeft() == nullptr && other->getLeft() == nullptr && this->getRight() == nullptr
                  && other->getRight == nullptr){
            output = true;
        } else{
            output = this->parent->getInfo() == other->parent->getInfo();
            output = output && this->left->getInfo() == other->left->getInfo();
            output = output && this->right->getInfo() == other->right->getInfo();
        }
        */
        
        return output;
    }
}



#endif
