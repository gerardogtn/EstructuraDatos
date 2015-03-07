//
//  main.cpp
//  Ejercicio01
//
//  Created by Gerardo Teruel on 2/28/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using namespace vcn;

/* INSTRUCCIONES DEL EJERCICIO.
 *
 * Haga un programa que genere y almacene en una lista enlazada n números primos
 * que se encuentren en el rango [p..q] y después los muestre en forma inversa.
 * Los valores de n, p y q deben ser definidos por el usuario.
 */

LinkedList<int> * generatePrimeNumbers(int n, int lowerBound, int upperBound);

int main(int argc, const char * argv[]) {
    int n;
    int p;
    int q;
    std::cout << "Inserte el numero de numeros primos a buscar (n): " << std::endl;
    std::cin >> n;
    std::cout << "Inserte el limite inferior (p): " << std::endl;
    std::cin >> p;
    std::cout << "Inserte el limite superior (q): " << std::endl;
    std::cin >> q;
    
    LinkedList<int> *primeList = generatePrimeNumbers(n, p, q);
    std::cout << *primeList << std::endl;
    
    return 0;
}

LinkedList<int> * generatePrimeNumbers(int n, int lowerBound, int upperBound){
    LinkedList<int> * primeList = new LinkedList<int>();
    
    if(lowerBound == 1) lowerBound++;
    
    if(lowerBound == 2 && primeList->size() < n) {
        primeList->insertFront(2);
        lowerBound++;
    }
    if (lowerBound == 3 && primeList->size() < n){
        primeList->insertFront(3);
        lowerBound++;
    }
    
    while (lowerBound <= upperBound && primeList->size() < n) {
        if(lowerBound % 2 != 0 && lowerBound % 3 != 0){
            for (int c = 3; c <lowerBound; c++) {
                if ( lowerBound % c == 0){
                    break;
                }
                
                if(c == lowerBound -1){
                    primeList->insertFront(lowerBound);
                }
            }
            
        }
        lowerBound++;
    }
    
    return primeList;
}
