//
//  main.cpp
//  ejercicio01
//
//  Created by Gerardo Teruel on 4/25/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "Dock.h"

int main(int argc, const char * argv[]) {
    Dock test(2, 2); 
    
    Product AAA("Zapatos",  5, 5.0);
    Product AAB("Pantalon", 7, 100.0);
    
    Product BBA("Blusa",   10, 80.0);
    Product BBB("Zapatos", 10, 187.0);
    Product BBC("Bufanda", 20, 5.5);
    
    Product CCA("Gorra",    5, 10.0);
    Product CCB("Cinturon", 7, 50.0);
    
    Container A("Zapatos y pantalones", "Zara");
    Container B("Blusas, zapatos y bufanda", "Zara");
    Container C("Gorras y cinturones", "Zara");
    
    
    A.addProduct(AAA);
    A.addProduct(AAB);
    
    B.addProduct(BBA);
    B.addProduct(BBB);
    B.addProduct(BBC);
    
    C.addProduct(CCA);
    C.addProduct(CCB);
    
    std::cout << (test.addContainer(A) ? "Works" : "Doesnt work") << std::endl;
    std::cout << (test.addContainer(B) ? "Works" : "Doesnt work") << std::endl;
    std::cout << (test.addContainer(C) ? "Works" : "Doesnt work") << std::endl;
    
    std::cout << test << std::endl;
    
    
}
