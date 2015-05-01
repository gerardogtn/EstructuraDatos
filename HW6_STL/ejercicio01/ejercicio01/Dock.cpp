//
//  Dock.cpp
//  ejercicio01
//
//  Created by Gerardo Teruel on 4/30/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Dock.h"

// REQUIRES: None. 
// MODIFIES: containers.
// EFFECTS : Adds a container to the first possible stack.
// If action can be completed returns true. Otherwise false.
bool Dock::addContainer(Container cont){
    for (auto s: vectorStack) {
        if (vectorStack.size() < n && s.size() < m) {
            s.push(cont);
            return true;
        }
    }
    
    return false;
}
