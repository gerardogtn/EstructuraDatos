//
//  BinaryTree.h
//  BinaryTree
//
//  Created by Vicente Cubells Nonell on 06/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef BinaryTree_BinaryTree_h
#define BinaryTree_BinaryTree_h

#include "BNode.h"

namespace vcn {

    template <class T>
    class BinaryTree {
    private:
        BNode<T> * root = nullptr;
        
    public:
        BinaryTree() {}
        virtual ~BinaryTree();
        
        bool empty();
        
        void clear();
        void clear(BNode<T> * node);
        
        BNode<T> * getRoot() const;
        void setRoot(BNode<T> * node);
        
        bool insert(BNode<T> * parent, T value);
        bool insert(BNode<T> * parent, BNode<T> * value);
        
        void preOrder() const;
        void preOrder(BNode<T> * node) const;
        
        void inOrder() const;
        void inOrder(BNode<T> * node) const;
        
        void postOrder() const;
        void postOrder(BNode<T> * node) const;
        
        void isLeaf() const;
        void isLeaf(BNode<T> * node) const;
        
        void ancestors(BNode<T> * node) const;
        
        
        // NEW METHODS //
        bool isBrother(const BNode<T> * nodeA, const BNode<T> * nodeB)     const;
        bool isAncestor(const BNode<T> * nodeA, const BNode<T> * parent)   const;
        bool isDescendant(const BNode<T> * nodeA, const BNode<T> * nodeB)  const;
        
        void printCousins(BNode<T> * node)           const;
        void printcousins(int level)                 const;
        void printAncestors(const BNode<T> * node)   const;
        void printDescendants(const BNode<T> * node) const;
        
        void printLongestPath() const;
        int  getLevel(BNode<T> * node) const;
        int  getDepth(BNode<T> * node) const;
        int  getLongestSize() const;
        
        int sumOfDescendants() const;
        int sumOfDescendants(const BNode<T> * node) const;
        
        void makeSumOfDescendants();
        void makeSumOfDescendants( BNode<T> * node);
        
        void reflect();
        void reflect(BNode<T> * node);
        
        bool equals(const BinaryTree<T> * b) const;
        bool equals(const BNode<T> *nodeA,   const BNode<T> *nodeB)   const;
        bool operator==(const BinaryTree<T> & a) const;
        
        BinaryTree<T> * copy();
        BNode<T> * copy(const BNode<T> * node);
        
        bool isSymmetric();
        
        
     };
    
    template <class T>
    BinaryTree<T>::~BinaryTree()
    {
        clear();
    }
    
    template <class T>
    bool BinaryTree<T>::empty()
    {
        return root == nullptr;
    }
    
    template <class T>
    void BinaryTree<T>::clear()
    {
        clear(root);
    }
    
    template <class T>
    void BinaryTree<T>::clear(BNode<T> * node)
    {
        if (node) {
            clear(node->getLeft());
            clear(node->getRight());
            
            delete node;
        }
    }
    
    template <class T>
    BNode<T> * BinaryTree<T>::getRoot() const
    {
        return root;
    }
    
    template <class T>
    void BinaryTree<T>::setRoot(BNode<T> * node)
    {
        if (!empty()) {
            node->setLeft(root);
            root->setParent(node);
            root = node;
        }
        else {
            root = node;
        }
    }
    
    template <class T>
    bool BinaryTree<T>::insert(BNode<T> * parent, T value)
    {
        BNode<T> * node = new BNode<T>(value);
        bool inserted = insert(parent, node);
        
        if (!inserted) delete node;
        
        return inserted;
    }
    
    template <class T>
    bool BinaryTree<T>::insert(BNode<T> * parent, BNode<T> * value)
    {
        bool inserted = false;
        
        if (empty() || !parent) {
            setRoot(value);
            inserted = true;
        }
        else {
            if (!parent->getLeft()) {
                parent->setLeft(value);
                value->setParent(parent);
                inserted = true;
            }
            else if (!parent->getRight()) {
                parent->setRight(value);
                value->setParent(parent);
                inserted = true;
            }
        }
        
        return inserted;
    }
    
    template <class T>
    void BinaryTree<T>::preOrder() const
    {
        preOrder(root);
    }
    
    template <class T>
    void BinaryTree<T>::preOrder(BNode<T> * node) const
    {
        if (node) {
            /* Procesar el nodo */
            std::cout << *node << std::endl;
            
            /* Invocar a los hijos */
            preOrder(node->getLeft());
            preOrder(node->getRight());
  
        }
    }
    
    template <class T>
    void BinaryTree<T>::inOrder() const
    {
        inOrder(root);
    }
    
    template <class T>
    void BinaryTree<T>::inOrder(BNode<T> * node) const
    {
        if (node) {
            
            /* Invocar al hijo izquierdo */
            inOrder(node->getLeft());
            
            /* Procesar el nodo */
            std::cout << *node << std::endl;
            
            /* Invocar al hijo derecho */
            inOrder(node->getRight());
        }
    }
    
    template <class T>
    void BinaryTree<T>::postOrder() const
    {
        postOrder(root);
    }
    
    template <class T>
    void BinaryTree<T>::postOrder(BNode<T> * node) const
    {
        if (node) {
            /* Invocar a los hijos */
            postOrder(node->getLeft());
            postOrder(node->getRight());
            
            /* Procesar el nodo */
            std::cout << *node << std::endl;
        }
    }
    
    template <class T>
    void BinaryTree<T>::isLeaf() const
    {
        isLeaf(root);
    }
    
    template <class T>
    void BinaryTree<T>::isLeaf(BNode<T> * node) const
    {
        if (node) {
            if (!node->getLeft() && !node->getRight()) {
                std::cout << *node << std::endl;
            }
            else {
                isLeaf(node->getLeft());
                isLeaf(node->getRight());
            }
        }
    }
    
    template <class T>
    void BinaryTree<T>::ancestors(BNode<T> * node) const
    {
        if (node) {
            std::cout << *node << " -> ";
            ancestors(node->getParent());
        }
    }
 
    // ************************************************************
    // *               MY METHODS START HERE:                     *
    // ************************************************************
    
    
    // MODIFIES: None
    // REQUIRES: None
    // EFFECTS:  Returns true if both nodes parents are equal. And nodeA is a direct descendant of nodeB's
    // parent. And nodeB is a direct descendant of nodeA's parent. False otherwise.
    // 
    template <class T>
    bool BinaryTree<T>::isBrother(const BNode<T> * nodeA, const BNode<T> * nodeB) const{
        if (nodeA && nodeB){
            return nodeA->isBrother(nodeB);
        }
        return false;
    }
    
   
    
    // MODIFIES: None.
    // REQUIRES: None.
    // EFFECTS:  Returns true if one of nodeA's parents is equal to parent.
    // Returns true if parent is an ancestor of nodeA.
    template <class T>
    bool BinaryTree<T>::isAncestor(const BNode<T> * parent, const BNode<T> * nodeA)   const{
        if (parent && nodeA && nodeA->getParent()){
            BNode<T> * nodeAParent = nodeA->getParent();
            if (nodeAParent == parent)
                return true;
            else{
                return isAncestor(parent, nodeAParent);
            }
        }
        return false;
    }
    
    // MODIFIES: None.
    // REQUIRES: None.
    // EFFECTS:  Returns true if descendant is one of the left or right nodes (or thereof descendants)
    // of nodeA. False otherwise.
    // Returns true if descendant is a descendant of nodeA. 
    template <class T>
    bool BinaryTree<T>::isDescendant(const BNode<T> * descendant, const BNode<T> * nodeA) const{
        bool output = false;
        
        if(descendant && nodeA){
            output = output || nodeA->getRight() == descendant;
            output = output || nodeA->getLeft() == descendant;
            
            output = output || isDescendant(descendant, nodeA->getRight());
            output = output || isDescendant(descendant, nodeA->getLeft());
        }
        
        
        return output;
        
    }
    
    // MODIFIES:
    // REQUIRES:
    // EFFECTS:
    //
    // TODO: METHOD
    template <class T>
    void BinaryTree<T>::printCousins(BNode<T> * node)     const{
        
        
    }
    
    // MODIFIES:
    // REQUIRES:
    // EFFECTS:
    //
    // TODO: METHOD
    template <class T>
    void BinaryTree<T>::printcousins(int level)           const{
        
        
    }
    
    // MODIFIES: None.
    // REQUIRES: None.
    // EFFECTS: Prints the ancestors of a node.
    template <class T>
    void BinaryTree<T>::printAncestors(const BNode<T> * node)   const{
        ancestors(node);
    }
    
    // MODIFIES: None.
    // REQUIRES: None.
    // EFFECTS:  Prints the descendants of a node.
    template <class T>
    void BinaryTree<T>::printDescendants(const BNode<T> * node) const{
        if (node) {
            std::cout << *node << " -> ";
            printDescendants(node->getLeft());
            printDescendants(node->getRight());
        }
        
    }
    
    // MODIFIES:
    // REQUIRES:
    // EFFECTS:
    //
    // TODO: METHOD
    template <class T>
    void BinaryTree<T>::printLongestPath() const{
        
        
    }
    
    // MODIFIES:
    // REQUIRES:
    // EFFECTS:
    //
    // TODO: METHOD
    template <class T>
    int  BinaryTree<T>::getLevel(BNode<T> * node) const{
        
        return -1; // STUB
    }
    
    // MODIFIES: None
    // REQUIRES: - On first iteration root is the root of the tree.
    // EFFECTS:  Returns the depth of the tree.
    //           If the node is null OR doesn't belong to the tree, returns -1.
    // Gets the depth of a node in  a tree.
    
    // TODO: OPTIMIZE SUCH THAT THERE ISN'T A COMPARISON TO ROOT ON EACH ITERATION.
    /*template <class T>
    int  BinaryTree<T>::getDepth(BNode<T> * node, int currentDepth, BNode<T> * root) const{
        
        if (node) {
            if(node == root){
                return currentDepth;
            } else if (root->getRight() == node || root->getLeft() == node){
                return ++currentDepth;
            } else if (node->getRight() == nullptr && node->getLeft() == nullptr){
                return -1;
            }else{
                return getDepth(node, ++currentDepth, root->getRight());
                return getDepth(node, ++currentDepth, root->getLeft());
            }
        }else{
            return -1;
        }
    }
    */
    // MODIFIES: None.
    // REQUIRES: None.
    // EFFECTS:  Returns the depth of the tree.
    //           If the node is null OR doesn't belong to the tree, returns -1.
    // Gets the depth of a node in  a tree.
    template <class T>
    int  BinaryTree<T>::getDepth(BNode<T> * node) const{
        return getDepth(node, 0, root);
    }
    
    
    // MODIFIES:
    // REQUIRES:
    // EFFECTS:
    //
    // TODO: METHOD.
    template <class T>
    int  BinaryTree<T>::getLongestSize() const{
        return -1; // STUB
    }
    
    
    // REQUIRES: None.
    // MODIFIES: None.
    //  EFFECTS: RETURNS THE SUM OF ALL THE DESCENDANTS OF A BINARY TREE.
    //
    template <class T>
    int BinaryTree<T>::sumOfDescendants() const{
        return sumOfDescendants(root);
    }
    
    // REQUIRES: None.
    // MODIFIES: None.
    //  EFFECTS: RETURNS THE SUM OF ALL THE DESCENDANTS OF A GIVEN NODE.
    //
    template <class T>
    int BinaryTree<T>::sumOfDescendants(const BNode<T> * node)const{
        
        int output = 0;
        if (node){
            output = output + node->getInfo();
            output = output + sumOfDescendants(node->getLeft());
            output = output + sumOfDescendants(node->getRight());
        }
        return output;
    }
    
    
    // REQUIRES: None.
    // MODIFIES: this.
    //  EFFECTS: Makes each node equal to the sum of its descendants.
    template <class T>
    void BinaryTree<T>::makeSumOfDescendants(){
        makeSumOfDescendants(root);
    }
    
    // REQUIRES: None.
    // MODIFIES: this.
    //  EFFECTS: Makes each node equal to the sum of its descendants.
    template <class T>
    void BinaryTree<T>::makeSumOfDescendants(BNode<T> * node){
        
        if (node){
            node->setInfo(sumOfDescendants(node));
            makeSumOfDescendants(node->getLeft());
            makeSumOfDescendants(node->getRight());
        }
    }
    
    
    // REQUIRES: None.
    // MODIFIES: this.
    //  EFFECTS: Reflects this tree.
    template <class T>
    void BinaryTree<T>::reflect(){
        reflect(root);
    }
    
    // REQUIRES: None.
    // MODIFIES: this.
    //  EFFECTS: Reflects this tree.
    template <class T>
    void BinaryTree<T>::reflect(BNode<T> * node){
        if (node){
            // Switch left and right nodes.
            BNode<T> * buffer = node->getLeft();
            node->setLeft(node->getRight());
            node->setRight(buffer);
            
            // Recursively reflects the rest of the tree. 
            reflect(node->getLeft());
            reflect(node->getRight());
        }
    }
    
    
    // REQUIRES: None.
    // MODIFIES: None
    //  EFFECTS: Produces true if the info in every node of a matches the info in every node of b.
    template <class T>
    bool BinaryTree<T>::equals(const BinaryTree<T> * b) const{
        return equals( this->getRoot(), b->getRoot());
    }
    
    
    // REQUIRES: None.
    // MODIFIES: None
    //  EFFECTS: Produces true if the info in every node of a matches the info in every node of b.
    template <class T>
    bool BinaryTree<T>::equals(const BNode<T> * nodeA, const BNode<T> * nodeB) const{
        bool output = false;
        if (nodeA && nodeB){
            output = (*nodeA == *nodeB);
            output = output && equals(nodeA->getLeft(),  nodeB->getLeft());
            output = output && equals(nodeA->getRight(), nodeB->getRight());
        } else if(!nodeA && !nodeB){
            output = true; 
        }
        return output;
    }
    
    
    // REQUIRES: None.
    // MODIFIES: None
    //  EFFECTS: Produces true if the info in every node of a matches the info in every node of b.
    template <class T>
    bool BinaryTree<T>::operator == (const BinaryTree<T> & b) const{
        return this->equals(&b);
    }
    
    // REQUIRES: None.
    // MODIFIES: None.
    //  EFFECTS: Copies a binary tree.
    template <class T>
    BinaryTree<T> * BinaryTree<T>::copy(){
        BinaryTree<T> * output = new BinaryTree<T>();
        BNode<T> * node = new BNode<T>();
        node = copy(this->getRoot());
        output->insert(nullptr, node);
        return output;
    }
    
    // REQUIRES: None.
    // MODIFIES: None.
    //  EFFECTS: Returns the copy of a node (including all its descendants.)
    template <class T>
    BNode<T> * BinaryTree<T>::copy(const BNode<T> * node){
        if (node){
            BNode<T> * output = new BNode<T>();
            output->setInfo(node->getInfo());
            output->setRight(copy(node->getRight()));
            output->setLeft(copy(node->getLeft()));
            return output;
        }
        return nullptr; 
    }

    
    
    // REQUIRES: None.
    // MODIFIES: None
    //  EFFECTS: Produces true if the reflection of a tree is equal to the original true. False otherwise.
    // Returns true if the tree is symmetric.
    template <class T>
    bool BinaryTree<T>::isSymmetric(){
        BinaryTree<T> * reflection = this->copy();
        reflection->reflect();
        bool output = (*this == *reflection);
        delete reflection;
        return output;
    }
    
}

#endif
