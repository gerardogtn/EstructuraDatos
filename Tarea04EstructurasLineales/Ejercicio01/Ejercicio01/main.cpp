//
//  main.cpp
//  Ejercicio01
//
//  Created by Gerardo Teruel on 3/21/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "Stack.h"
#include <string>

using namespace std;
using namespace vcn;

void checkEquation(Stack<int> * bracketStack, string equationToCheck, int lengthOfString);
void verifyForwards(Stack<int> * bracketStack, string equationToCheck, int lengthOfString);
void verifyBackwards(Stack<int> * bracketStack, string equationToCheck, int lengthOfString);
void verifyAbstract(Stack<int> *bracketStack, string equationToCheck, int firstComp, int secondComp,
                    int updateVar(int), string firstStringComparison, string SecondStringComparison);


int main(int argc, const char * argv[]) {
    string equationToCheck;
    string currentChar;
    Stack<int> * bracketStack = new Stack<int>;
    
    cout << "Inserte la expresion matematica a balancear: " << endl;
    getline(cin, equationToCheck);
    
    int lengthOfString = (int) equationToCheck.length();
    
    checkEquation(bracketStack, equationToCheck, lengthOfString);
    
    
    if(bracketStack->empty()){
        cout << "La ecuacion esta balanceada " << endl;
    }else{
        cout << "La ecuacion NO esta balanceada " << endl;
    }
    
    
    delete bracketStack;
    return 0;
}

// REQUIRES: lengthOfString is length of equationToCheck.
// MODIFIES: bracketStack
// EFFECTS:  Transverses the string front to back checking that for every open bracket there is a close
//           bracket.
//
void checkEquation(Stack<int> * bracketStack, string equationToCheck, int lengthOfString){
    verifyForwards(bracketStack, equationToCheck, lengthOfString);
    verifyBackwards(bracketStack, equationToCheck, lengthOfString);
}


// REQUIRES: lengthOfString is length of equationToCheck.
// MODIFIES: bracketStack
// EFFECTS:  (a)Transverses the string front to back checking that for every open bracket there is a close
//              bracket.
void verifyForwards(Stack<int> * bracketStack, string equationToCheck, int lengthOfString){
    verifyAbstract(bracketStack, equationToCheck, 0, lengthOfString, [](int a){ return ++a;}, "(", ")");
}

// REQUIRES: lengthOfString is length of equationToCheck.
// MODIFIES: bracketStack
// EFFECTS:  Transverses the string back to front checking that for every open bracket there is a close
//           bracket.
void verifyBackwards(Stack<int> * bracketStack, string equationToCheck, int lengthOfString){
    verifyAbstract(bracketStack, equationToCheck, lengthOfString, 0, [](int a){ return --a;}, ")", "(");
}


// REQUIRES: None
// MODIFIES: bracketStack
// EFFECTS:  Adds element to stack for every firstStringComparison and removes element every
//           SecondStringComparison.
//           The string is compared on the interval [firstComp, secondComp], from back to front or front
//           to back depending to updateVar function.
void verifyAbstract(Stack<int> *bracketStack, string equationToCheck, int firstComp, int secondComp,
                    int updateVar(int), string firstStringComparison, string SecondStringComparison){
    string currentChar;
    for(int i = firstComp; i >= secondComp; i = updateVar(i)){
        currentChar = equationToCheck[i];
        
        if(currentChar.compare(firstStringComparison) == 0){
            bracketStack->push(1);
        }else if (currentChar.compare(SecondStringComparison) == 0){
            bracketStack->pop();
        }
    }
}
