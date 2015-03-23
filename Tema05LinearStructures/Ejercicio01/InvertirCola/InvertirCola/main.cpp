//
//  main.cpp
//  InvertirCola
//
//  Created by Gerardo Teruel on 3/23/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace vcn;

int main(int argc, const char * argv[]) {
    
    Queue<int> * queueToInvert = new Queue<int>();
    Stack<int> * stackInverted = new Stack<int>();
    
    queueToInvert->enqueue(1);
    queueToInvert->enqueue(2);
    queueToInvert->enqueue(3);
    queueToInvert->enqueue(4);
    
    std::cout << *queueToInvert << std::endl;
    
    int stop = queueToInvert->size();
    for (int i = 0; i < stop; i++) {
        stackInverted->push(queueToInvert->dequeue());
    }
 
    std::cout << *stackInverted << std::endl;
    
    
    delete queueToInvert;
    delete stackInverted;
}



