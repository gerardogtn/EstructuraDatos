//
//  Container.cpp
//  ejercicio01
//
//  Created by Gerardo Teruel on 4/30/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Container.h"

int Container::containerCount = 1;

// REQUIRES: None
// MODIFIES: products.
// EFFECTS : Insert a product to products.
void Container::addProduct(Product & toAdd){
    products.push_back(toAdd);
}

// REQUIRES: None.
// MODIFIES: None.
// EFFECTS : Calculates the total cost of a container.
double Container::costOfContainer() const{
    double output = 0;
    
    for(auto p : products){
        output = output + p.getPrice();
    }
    
    return output;
}

// REQUIRES:
// MODIFIES:
// EFFECTS :
ostream & operator<<(ostream & os, const Container & cont){
    os << cont.containerName << ": " << endl;
    
    for (auto p : cont.products){
        os << setw(10) << "" << p << endl;
    }
    
    os << "Costo del contenedor: $" << setw(7) << setprecision(2) << std::fixed << cont.costOfContainer() << endl;
    
    return os;
}