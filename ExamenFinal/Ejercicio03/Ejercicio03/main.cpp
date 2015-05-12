//
//  main.cpp
//  Ejercicio03
//
//  Created by Gerardo Teruel on 5/12/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "BinaryTree.h"
using namespace vcn;

BinaryTree<char> * buildTree(string preOrder, string inOrder);
BNode<char> * buildTree(string preOrder, string inOrder, BNode<char> * outputRoot);

int main(int argc, const char * argv[]) {
    BinaryTree<char> * test = buildTree("GEAIBMCLDFKJH", "IABEGLDCFMKHJ");
    test->preOrder();
    
}


// REQUIRES: preOrder and inOrder have the same length.
// MODIFIES: None.
//  EFFECTS: Builds a string from an in-order and pre-order stream of characters.
BinaryTree<char> * buildTree(string preOrder, string inOrder){
    BinaryTree<char> * output = new BinaryTree<char>();
    BNode<char> * outputRoot = new BNode<char>();
    outputRoot->setInfo(preOrder[0]);
    output->setRoot(buildTree(preOrder, inOrder, outputRoot));
    return output;
}

// REQUIRES: preOrder and inOrder have the same length.
// MODIFIES: inOrder and preOrder strings.
// EFFECTS : Builds a string from an in-order and pre-order stream of characters and a root outputRoot.
BNode<char> * buildTree(string preOrder, string inOrder, BNode<char> * outputRoot){
    BNode<char> * left = nullptr;
    BNode<char> * right = nullptr;
    
    for (int i = 1 ; i < inOrder.size(); i++) {
        if (inOrder[i] == outputRoot->getInfo()) {
            left = new BNode<char>(preOrder[1]);
            right = new BNode<char>(preOrder[i+1]);
            inOrder.erase(inOrder.begin() + i - 1);
            preOrder.erase(preOrder.begin());
            
            // Pasar a izquierdo el preOrder y  inOrder desde el inicio hasta i -1.
            left = buildTree(preOrder, inOrder, left);
            // Pasar a izquierdo el preOrder y  inOrder desde i-1 hasta el final.
            right = buildTree(preOrder, inOrder, right);
            
            break;
        }
    }
 
    outputRoot->setLeft(left);
    outputRoot->setRight(right);
    return outputRoot;
}
