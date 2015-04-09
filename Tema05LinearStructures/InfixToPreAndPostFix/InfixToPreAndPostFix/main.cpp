//
//  main.cpp
//  InfixToPreAndPostFix
//
//  Created by Gerardo Teruel on 4/9/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

/*
 Ejercicio 05 de estructuras lineales por el prof. Vicente Cubells
 
 Realice un programa que lea del teclado una expresion aritmetica con notacion
 infija e imprima la misma expresion luego de convertirla a notacion postfija
 y prefija.
 
*/

#include <iostream>
#include "Stack.h"
#include "Queue.h"

//PROTOTIPES
std::string removeSpaces(std::string input);

//NAMESPACES

using namespace vcn;


// ASSUMES: EXPRESSION IS PROPERLY BALANCED.
// NUMBERS ARE BETWEEN 1-9

//WORKS ONLY FOR ONE OPERATION: USE OF BRACKETS TO DO MULTIPLE OPERATIONS IS
//NOT SUPPORTED YET.
//THE OPERATION MIGHT BE SEAPARATED BY SPACES. 
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Inserte la expresion infija:\n";
    
    std::string input;
    std::getline(std::cin, input);
    
    std::cout << "\n String insertado:\n" << input  << std::endl;
    input = removeSpaces(input);
    std::cout << "\n String modificado:\n" << input << std::endl;
    
    Queue<char> * firstDigits   = new Queue<char>();
    Stack<char> * operatorDigit = new Stack<char>();
    Stack<char> * lastDigits    = new Stack<char>();
    
    int halfLength = input.size()/2;
    operatorDigit->push(input[halfLength]);
    
    for(int i = 0; i < halfLength; i++){
        firstDigits->enqueue(input[i]);
    }
    
    for(int i = input.size() - 1; i > halfLength; i--){
        lastDigits->push(input[i]);
    }
    
    std::cout << "=========== NOTACION EN PREFIJO =====" << std::endl;
    
    std::cout << *operatorDigit << " ";
    std::cout << *firstDigits  << " ";
    std::cout << *lastDigits  << std::endl;
    std::cout << std::endl;
    
    std::cout << "=========== NOTACION EN POSTFIJO =====" << std::endl;
    
    std::cout << *firstDigits  << " ";
    std::cout << *lastDigits  << " ";
    std::cout << *operatorDigit << std::endl;
    std::cout << std::endl;
    
    delete firstDigits;
    delete operatorDigit;
    delete lastDigits;
    
    return 0;
}


std::string removeSpaces(std::string input)
{
    input.erase(std::remove(input.begin(),input.end(),' '),input.end());
    return input;
}