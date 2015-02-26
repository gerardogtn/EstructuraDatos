//
//  main.cpp
//  GenericSearch
//
//  Created by Gerardo Teruel on 2/25/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "GenericSearch.h"

using namespace std;

template <typename T>
void printArray(const T [], const int);

void sequentiallyFillArray(int [], const int);

int main(int argc, const char * argv[]) {
    
    const int ARRAYSIZE = 10;
    
    srand((unsigned int) time(nullptr));
    int integerArray[ARRAYSIZE];
    
    sequentiallyFillArray(integerArray, ARRAYSIZE);
    printArray(integerArray, ARRAYSIZE);
    
    
    cout << "Entre el elemento a buscar: ";
    int valueToSearch;
    cin >> valueToSearch;
    
    //if (GenericSearch<int>::linearSearch(integerArray, valueToSearch, ARRAYSIZE)) {
    if (GenericSearch<int>::binarySearch(integerArray, valueToSearch, 0, ARRAYSIZE)) {
        cout << "El valor SI existe en el arreglo." << endl;
    }
    else{
        cout << "El valor NO existe en el arreglo." << endl;
    }
    
    cout << "La posicion del valor a buscar en el arreglo es: ";
    //cout << GenericSearch<int>::binarySearchPosition(integerArray, valueToSearch, 0, ARRAYSIZE) << endl;
    cout << GenericSearch<int>::linearSearchPosition(integerArray, valueToSearch, ARRAYSIZE) << endl; 
    
    return 0;
}


void sequentiallyFillArray(int arrayToFill[], const int sizeOfArray){
    for(int i = 0; i < sizeOfArray; i++ ){
        arrayToFill[i] = i;
    }
}

template <typename T>
void printArray(const T array[], const int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; ++i) {
        std::cout << array[i] << " ";
    }
    
    std::cout << std::endl;
}