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
    BNode<int> * unoA = new BNode<int>(1);
    numeros->insert(nullptr, uno);
    numeros2->insert(nullptr, unoA);
    std::cout << (numeros->equals(numeros, numeros2)? "This works" : "This doesn't work") << std::endl;
    
    BNode<int> * dos = new BNode<int>(2);
    BNode<int> * dosA = new BNode<int>(2);
    numeros->insert(uno, dos);
    numeros2->insert(unoA, dosA);
    std::cout << (numeros->equals(numeros, numeros2)? "This works" : "This doesn't work") << std::endl;
    std::cout << (*numeros == *numeros2? "This works" : "This doesn't work") << std::endl;
    
    numeros->insert(nullptr, 0);
    numeros2->insert(nullptr, 0);
    std::cout << (numeros->equals(numeros, numeros2)? "This works" : "This doesn't work") << std::endl;
    std::cout << (*numeros == *numeros2? "This works" : "This doesn't work") << std::endl;
    
    BNode<int> * tres = new BNode<int>(3);
    BNode<int> * tresA = new BNode<int>(3);
    numeros->insert(uno, tres);
    numeros2->insert(unoA, tresA);
    std::cout << (numeros->equals(numeros, numeros2)? "This works" : "This doesn't work") << std::endl;
    std::cout << (*numeros == *numeros2? "This works" : "This doesn't work") << std::endl;
    
    BNode<int> * cuatro = new BNode<int>(4);
    BNode<int> * cuatroA = new BNode<int>(4);
    numeros->insert(dos, cuatro);
    numeros2->insert(dosA, cuatroA);
    std::cout << (numeros->equals(numeros, numeros2)? "This works" : "This doesn't work") << std::endl;
    std::cout << (*numeros == *numeros2? "This works" : "This doesn't work") << std::endl;
    
    numeros->preOrder();
    std::cout << std::endl;
    numeros2->preOrder();
    
    
    delete numeros;
    delete numeros2;

}
