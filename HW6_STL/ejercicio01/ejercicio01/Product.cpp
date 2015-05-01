//
//  Product.cpp
//  ejercicio01
//
//  Created by Gerardo Teruel on 4/30/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Product.h"
#include <iostream>
#include <iomanip>

// REQUIRES: None.
// MODIFIES: os.
// EFFECTS : Overloads stream output operator.
ostream & operator<<(ostream & os, const Product & prod){
    os << setw(10) << prod.description << setw(10) << prod.quantity << setw(10) << prod.unitPrice;
    return os;
}

// REQUIRES: None.
// MODIFIES: None.
// EFFECTS:  Calculates the cost of all the products of this type.
double Product::getPrice() const {
    double output = 0;
    output = unitPrice * quantity;
    return output;
}


