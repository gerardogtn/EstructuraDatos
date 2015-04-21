//
//  main.cpp
//  BinaryTreeModified
//
//  Created by Gerardo Teruel on 4/13/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "BinaryTree.h"

using namespace vcn; 

int main(int argc, const char * argv[]) {
    BinaryTree<int> * numeros  = new BinaryTree<int>();
    BinaryTree<int> * numeros2 = new BinaryTree<int>();
    BinaryTree<int> * numeros3 = new BinaryTree<int>();
    
    BNode<int> * uno = new BNode<int>(1);
    numeros->insert(nullptr, uno);
    
    BNode<int> * dos = new BNode<int>(2);
    numeros->insert(uno, dos);
    
    numeros->insert(nullptr, 0);
    
    BNode<int> * tres = new BNode<int>(3);
    numeros->insert(uno, tres);
    
    BNode<int> * cuatro = new BNode<int>(4);
    numeros->insert(dos, cuatro);
    
    
    numeros2 = numeros->copy();
    
    numeros->preOrder();
    std::cout << std::endl;
    numeros2->preOrder();
    
    std::cout << (numeros->isSymmetric()? "Symmetric predicate doesn't work" : "Symmetric predicate works") << std:: endl;
    
    BNode<int> * ONE = new BNode<int>(1);
    numeros3->insert(nullptr, ONE);
    numeros3->insert(ONE, 2);
    numeros3->insert(ONE, 2);
    
    std::cout << (numeros3->isSymmetric()? "Symmetric predicate works" : "Symmetric predicate doesn't work") << std:: endl;
    std::cout << std::endl;
    numeros3->preOrder();
    
    delete numeros;
    delete numeros2;
    delete numeros3;

}
