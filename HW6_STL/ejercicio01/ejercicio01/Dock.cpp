//
//  Dock.cpp
//  ejercicio01
//
//  Created by Gerardo Teruel on 4/30/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Dock.h"
#include <math.h>
#include <algorithm>

int Dock::containerNum = 1;

// REQUIRES: None. 
// MODIFIES: containers.
// EFFECTS : Adds a container to the first possible stack.
// If action can be completed returns true. Otherwise false.
bool Dock::addContainer(Container & cont){
    double dummy = containerNum;
    dummy = dummy / n;
    int a = ceil(dummy);
    
    
    for (auto s : this->vectorStack) {
        if (a <= 1){
            s.push(cont);
            containerNum++;
            return true;
        }
        a--; 
    }
    return false;
}


// REQUIRES: None.
// MODIFIES: os.
// EFFECTS : Overloads stream output operator. 
ostream & operator<<(ostream & os, const Dock & duck){
    
    
    int count = 1;
    for(auto s : duck.vectorStack){
        std::cout << "Pila " << setw(3) << count << ": " << std::endl;
        stack<Container> dummy;
        
        while (!s.empty()) {
            dummy.push(s.top());
            s.pop();
        }
        
        while (!dummy.empty()) {
            Container & a = dummy.top();
            s.push(a);
            std::cout << &a << std::endl;
            
        }

        count++;
        
        std::cout << std::endl; 
    }
    return os;
}
