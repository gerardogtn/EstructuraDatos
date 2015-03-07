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

using std::cin;
using std::cout;
using std::endl;
using namespace vcn;

/* INSTRUCCIONES DEL EJERCICIO.
 *
 * Programe una aplicación que permita ingresar n números reales a una lista 
 * enlazada y m números reales a otra lista, siendo m y n elegibles por el usuario
 * (entrados por consola). A las listas anteriores les llamaremos N y M respectivamente.
 *
 * Después de tener ambas listas, la aplicación debe ser capaz de realizar las siguientes operaciones:
 * N ⋃ M (Los elementos duplicados deben aparecer una sola vez) 
 * N-M
 * M-N
 * N*M
 * N⋂M
 *
 * Los resultados de la operación seleccionada por el usuario deben almacenarse en otra lista enlazada
 * P y mostrarse por pantalla junto con la información de las listas N y M.
 */

LinkedList<int> * union2(LinkedList<int> * , LinkedList<int> *);
LinkedList<int> * substractionA(LinkedList<int> * , LinkedList<int> *);
LinkedList<int> * substractionB(LinkedList<int> * , LinkedList<int> *);
LinkedList<int> * product(LinkedList<int> * , LinkedList<int> *);
LinkedList<int> * intersection(LinkedList<int> * , LinkedList<int> *);
bool linearLinkedListSearch(LinkedList<int> *searchingArray, int keyToSearch, int sizeOfList);

int main(int argc, const char * argv[]) {
    int n;
    int m;
    int s;
    
    LinkedList<int> *N = new LinkedList<int>();
    LinkedList<int> *Na = new LinkedList<int>();
    Na = N;
    LinkedList<int> *M = new LinkedList<int>();
    LinkedList<int> *Ma = new LinkedList<int>();
    Ma = M;
    LinkedList<int> *result = new LinkedList<int>();
    
    cout << "Inserte la cantidad de numeros en la lista enlazada N :";
    cin >> n;
    
    cout << "\nInserte los numeros en la lista N:" << endl;
    while (n > 0) {
        int temp;
        cin >> temp;
        N->insertBack(temp);
        n--;
    }
    
    cout << "\nInserte la cantidad de numeros en la lista enlazada M :";
    cin >> m;
    
    cout << "\nInserte los numeros en la lista M:" << endl;
    while (m > 0) {
        int temp;
        cin >> temp;
        M->insertBack(temp);
        m--;
    }
    
    cout << "\nQue operacion desea realizar?" << endl;
    cout << "Inserte 1 para: N union M" << endl;
    cout << "Inserte 2 para: N - M" << endl;
    cout << "Inserte 3 para: M - N" << endl;
    cout << "Inserte 4 para: N por M" << endl;
    cout << "Inserte 5 para: N interseccion M" << endl;
    cin >> s;
    
    switch (s) {
        case 1:
            result = union2(N, M);
            break;
        case 2:
            result = substractionA(N, M);
            break;
        case 3:
            result = substractionB(N, M);
            break;
        case 4:
            result = product(N, M);
            break;
        case 5:
            result = intersection(N, M);
        default:
            break;
    }
    
    cout << "\nLa lista N es: " << endl;
    cout << *Na << endl;
    
    cout << "La lista M es: " << endl;
    cout << *Ma << endl;
    
    cout << "El resultado de la operacion seleccionada es: " << endl;
    std::cout << *result << std::endl;
    return 0;
}

LinkedList<int> * union2(LinkedList<int> *N , LinkedList<int> *M){
    LinkedList<int> *result = N;
    
    int listSize = M -> size();
    
    for(int i = 0; i < listSize; i++){
        
        int current = M->at(i)->getInfo();
        if (!linearLinkedListSearch(N, current, N->size())) {
            result->insertBack(current);
        }
    }
    
    return result;
}

bool linearLinkedListSearch(LinkedList<int> *searchingArray, int keyToSearch, int sizeOfList){
    int  i = 0;
    bool found = false;
    
    while (i < sizeOfList && !found) {
        int current = searchingArray->at(i)->getInfo();
        if (current == keyToSearch) {
            found = true;
        }
        i++;
    }
    return found;
}

LinkedList<int> * substractionA(LinkedList<int> *N , LinkedList<int> *M){
    LinkedList<int> *result = N;
    
    int listSize = M -> size();
    for(int i = 0; i < listSize; i++){
        
        int current = M->at(i)->getInfo();
        if (linearLinkedListSearch(N, current, N->size())) {
            result->remove(i);
        }
    }
    
    return result;
}

LinkedList<int> * substractionB(LinkedList<int> *N , LinkedList<int> *M){
    return substractionA(M, N);
}

LinkedList<int> * product(LinkedList<int> *N , LinkedList<int> *M){
    LinkedList<int> *result = new LinkedList<int>();
    
    for (int i = 0; i < N->size(); i++) {
        int Ncurrent = N->at(i)->getInfo();
        for (int j = 0; j < M->size(); j++) {
            int Mcurrent = M->at(j)->getInfo();
            int prod = Mcurrent * Ncurrent;
            
            result->insertBack(prod);
        }
    }
    
    
    return result;
}

LinkedList<int> * intersection(LinkedList<int> *N , LinkedList<int> *M){
    LinkedList<int> *result = new LinkedList<int>();
    
    int listSize = M -> size();
    for(int i = 0; i < listSize; i++){
        
        int current = M->at(i)->getInfo();
        if (linearLinkedListSearch(N, current, N->size())) {
            result->insertBack(current);
        }
    }
    
    return result;
}