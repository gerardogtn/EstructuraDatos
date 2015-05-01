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


// REQUIRES: None.
// MODIFIES: os.
// EFFECTS : Overloads stream output operator. 
ostream & operator<<(ostream & os, const Dock & duck){
    int count = 1;
    for(auto s : duck.vectorStack){
        std::cout << "Pila " << setw(3) << count << std::endl;
        
        vector<Container> buffer;
        int countB = 1;
        
        while (!s.empty()) {
            Container &a = s.top();
            buffer.insert(buffer.begin(), a);
            s.pop();
        }
        
        for (c : buffer) {
            s.push(c);
            std::cout << "Contenedor " << setw(3) << countB;
            std::cout << setw(3) << &c << std::endl;
            countB++;
        }

        count++;
        std::cout << std::endl;
    }
    return os;
}