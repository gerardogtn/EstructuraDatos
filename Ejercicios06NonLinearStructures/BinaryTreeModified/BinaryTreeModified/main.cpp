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
    
    BNode<int> * uno = new BNode<int>(1);
    numeros->insert(nullptr, uno);
    
    BNode<int> * dos = new BNode<int>(2);
    numeros->insert(uno, dos);
    
    numeros->insert(nullptr, 0);
    
    BNode<int> * tres = new BNode<int>(3);
    numeros->insert(uno, tres);
    
    BNode<int> * cuatro = new BNode<int>(4);
    numeros->insert(dos, cuatro);
    
    
    numeros2 = numeros2->copy(numeros); 
    
    numeros->preOrder();
    std::cout << std::endl;
    numeros2->preOrder();
    
    
    delete numeros;
    delete numeros2;

}
