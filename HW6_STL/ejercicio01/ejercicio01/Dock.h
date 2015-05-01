//
//  Dock.h
//  ejercicio01
//
//  Created by Gerardo Teruel on 4/30/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef __ejercicio01__Dock__
#define __ejercicio01__Dock__
#include "Container.h"
#include <vector>
#include <stack>

class Dock{
    // PUN INTENDED :P
    friend ostream & operator<<(ostream & os, const Dock & duck); 
    
private:
    const int n  = 3; //Amount of containers per stack.
    const int m  = 5; //Amount of stacks.
    vector<stack<Container>> vectorStack;
    
public:
    
    Dock() {
        vectorStack.resize(m);
    };
    Dock(int _n, int _m ) :n(_n), m(_m)  {
        vectorStack.resize(m);
    };
    
    bool addContainer(Container cont);
    
};


#include <stdio.h>

#endif /* defined(__ejercicio01__Dock__) */
