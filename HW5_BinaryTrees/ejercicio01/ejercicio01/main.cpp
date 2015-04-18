//
//  main.cpp
//  ejercicio01
//
//  Created by Gerardo Teruel on 4/17/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

// Realice un programa que dado un árbol binario, obtenga otro árbol binario
// donde sus elementos serán la suma del mismo nodo más todos los descendientes en el árbol original.


#include <iostream>
#include "BinaryTree.h"
#include "BNode.h"

using namespace vcn;
int main(int argc, const char * argv[]) {
    
    BinaryTree<int> * numeros = new BinaryTree<int>();
    
    BNode<int> * uno = new BNode<int>(1);
    numeros->insert(nullptr, uno);
    
    BNode<int> * dos = new BNode<int>(2);
    numeros->insert(uno, dos);
    
    numeros->insert(nullptr, 0);
    
    BNode<int> * tres = new BNode<int>(3);
    numeros->insert(uno, tres);
    
    BNode<int> * cuatro = new BNode<int>(4);
    numeros->insert(dos, cuatro);
    
    numeros->preOrder();
    
    numeros->sumOfDescendants();
    std::cout << std::endl;
    
    std::cout << numeros->sumOfDescendants() << std::endl;
    
    std::cout << std::endl;
    numeros->makeSumOfDescendants();
    numeros->preOrder();
    delete numeros;
    
}
