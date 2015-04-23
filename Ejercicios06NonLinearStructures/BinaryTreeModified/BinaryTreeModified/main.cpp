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
    
    BNode<int> * uno = new BNode<int>(1);
    numeros->insert(nullptr, uno);
    
    BNode<int> * dos = new BNode<int>(2);
    numeros->insert(uno, dos);
    
    numeros->insert(nullptr, 0);
    
    BNode<int> * tres = new BNode<int>(3);
    numeros->insert(uno, tres);
    
    BNode<int> * cuatro = new BNode<int>(4);
    numeros->insert(dos, cuatro);
    

    std::cout << (numeros->isBrother(dos, tres)? "Brother works" : "Brother doesn't work") << std::endl;
    std::cout << (numeros->isBrother(uno, tres)? "Brother doesn't work" : "Brother works") << std::endl;
    std::cout << (numeros->isBrother(dos, cuatro)? "Brother doesn't work" : "Brother works") << std::endl;
    
    delete numeros;

}
