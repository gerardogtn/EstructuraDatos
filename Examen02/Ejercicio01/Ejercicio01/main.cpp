//
//  main.cpp
//  Ejercicio01
//
//  Created by Gerardo Teruel on 4/9/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "Stack.h"
using namespace vcn;

void decimalToBinary(const int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    decimalToBinary(9);
    return 0;
}

void decimalToBinary(const int n){
    int a = n;
    int element = 0;
    
    Stack<int> * binaryRep = new Stack<int>();
    
    
    while(a / 2 > 0){
        element = a % 2;
        binaryRep->push(element);
        a = a / 2;
    }
    binaryRep->push(a);
    
    std::cout<< *binaryRep<< std::endl;
}