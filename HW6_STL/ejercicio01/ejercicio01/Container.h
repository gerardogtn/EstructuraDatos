//
//  Container.h
//  ejercicio01
//
//  Created by Gerardo Teruel on 4/30/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef __ejercicio01__Container__
#define __ejercicio01__Container__
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

class Container{
    
    
private:
    int id_container;
    string containerName;
    string nameOfOwner;
    static int containerCount;
    list<Product> products;
    
    
public:
    Container(){
        id_container  = containerCount;
        containerName = "Unknown name.";
        nameOfOwner   = "No Known Owner.";
        containerCount++;
    };
    
    Container(string contName, string nameOwn){
        id_container  = containerCount;
        nameOfOwner   = nameOwn;
        containerName = contName;
        containerCount++;
    }
    
    void addProduct(Product & toAdd); 
    double costOfContainer();
    void printContainer();
    
    
};


#include <stdio.h>

#endif /* defined(__ejercicio01__Container__) */
