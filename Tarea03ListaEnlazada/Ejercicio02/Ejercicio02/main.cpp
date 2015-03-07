//
//  main.cpp
//  Ejercicio02
//
//  Created by Gerardo Teruel on 3/6/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>

#include <iostream>
#include "LinkedList.h"

using namespace vcn;

/* INSTRUCCIONES DEL EJERCICIO.
 *
 * Programe una aplicación que permita ingresar n números reales a una lista 
 * enlazada y m números reales a otra lista, siendo m y n elegibles por el usuario
 * (entrados por consola). A las listas anteriores les llamaremos N y M respectivamente.
 *
 * Después de tener ambas listas, la aplicación debe ser capaz de realizar las siguientes operaciones:
 * N ⋃ M (Los elementos duplicados deben aparecer una sola vez) •N-M
 * M-N
 * N*M
 * N⋂M
 * Los resultados de la operación seleccionada por el usuario deben almacenarse en otra lista enlazada
 * P y mostrarse por pantalla junto con la información de las listas N y M.
 */

int main(int argc, const char * argv[]) {
    LinkedList<int> *N = new LinkedList<int>();
    LinkedList<int> *M = new LinkedList<int>();
    
    N ->insertBack(1);
    N ->insertBack(2);
    N ->insertBack(3);
    N ->insertBack(4);
    
    M ->insertBack(5);
    M ->insertBack(6);
    M ->insertBack(7);
    M ->insertBack(4);
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

