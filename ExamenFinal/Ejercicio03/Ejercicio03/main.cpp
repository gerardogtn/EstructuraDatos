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
BinaryTree<char> * buildTree(string preOrder, string inOrder, BNode<char> * outputRoot); 

int main(int argc, const char * argv[]) {
    BinaryTree<int> * numeros  = new BinaryTree<int>();
    
    BNode<int> * uno = new BNode<int>(1);
    numeros->insert(nullptr, uno);
    
    BNode<int> * dos = new BNode<int>(2);
    numeros->insert(uno, dos);
    
    BNode<int> * cero = new BNode<int>(0);
    numeros->insert(nullptr, cero);
    
    BNode<int> * tres = new BNode<int>(3);
    numeros->insert(uno, tres);
    
    BNode<int> * cuatro = new BNode<int>(4);
    numeros->insert(dos, cuatro);
    
    numeros->preOrder();
    BinaryTree<char> * test = buildTree("GEAIBMCLDFKJH", "IABEGLDCFMKHJ");
    test->preOrder();
    
}


// REQUIRES: preOrder and inOrder have the same length.
// MODIFIES: None.
//  EFFECTS: Builds a string from an in-order and pre-order stream of characters.
BinaryTree<char> * buildTree(string preOrder, string inOrder){
    BNode<char> * outputRoot = new BNode<char>();
    outputRoot->setInfo(preOrder[0]);
    return buildTree(preOrder, inOrder, outputRoot);
}

// REQUIRES: preOrder and inOrder have the same length.
// MODIFIES: None.
// EFFECTS : Builds a string from an in-order and pre-order stream of characters and a root outputRoot.
BinaryTree<char> * buildTree(string preOrder, string inOrder, BNode<char> * outputRoot){
    BinaryTree<char> * output = new BinaryTree<char>();
    output->setRoot(outputRoot);
    string dummy;
    for (int i = 1 ; i < inOrder.size(); i++) {
        dummy = dummy + preOrder[i];
        if (inOrder[i] == outputRoot->getInfo()) {
            break;
        }
    }
    cout << dummy << endl;
    return output; //STUB
}
