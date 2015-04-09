//
//  main.cpp
//  Ejercicio02
//
//  Created by Gerardo Teruel on 4/9/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using namespace vcn;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


LinkedList<int> * repeatedElements(LinkedList<int> * input){
    LinkedList<int> * output = new LinkedList<int>();
    int dummy;
    
    for (int i = 0; i < input->size(); i++) {
        dummy = input->first()->getInfo();
        input->removeFront();
        if (input->search(dummy)) {
            output->insertFront(dummy);
        }
    }
    
    return output;
}