//
//  Product.h
//  ejercicio01
//
//  Created by Gerardo Teruel on 4/30/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef __ejercicio01__Product__
#define __ejercicio01__Product__
#include <string>

using namespace std;

class Product{
    friend ostream & operator<<(ostream & os, const Product & prod);
    
private:
    string description;
    int quantity;
    double unitPrice; 
    
public:
    
    Product() {};
    Product(string desc, int quant, double unitCost) : description(desc), quantity(quant), unitPrice(unitCost){};
    
    double getPrice() const;
    
};

#include <stdio.h>

#endif /* defined(__ejercicio01__Product__) */
