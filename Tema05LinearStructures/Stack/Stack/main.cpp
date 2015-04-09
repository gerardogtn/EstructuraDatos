//
//  main.cpp
//  Stack
//
//  Created by Gerardo Teruel on 3/19/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "Stack.h"

using namespace vcn;

int main(int argc, const char * argv[]) {
    
    // Define stack
    Stack<int> * pila = new Stack<int>();
    
    // Delete stack
    delete pila;
    
    // Inserte elements in stack
    pila->push(1);
    pila->push(2);
    pila->push(3);
    pila->push(4);
    
    // Display elements in stack
    std::cout << *pila << std::endl;
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
