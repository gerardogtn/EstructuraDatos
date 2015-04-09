//
//  main.cpp
//  Ejercicio03
//
//  Created by Gerardo Teruel on 4/9/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"

using namespace std;
using namespace vcn;

void handleInput(std::string);
LinkedList<int> * unionSet(LinkedList<int> * a, LinkedList<int> * b);
LinkedList<int> * interSet(LinkedList<int> * a, LinkedList<int> * b);
bool checkEquation(Stack<int> * bracketStack, string equationToCheck, int lengthOfString);
void verifyForwards(Stack<int> * bracketStack, string equationToCheck, int lengthOfString);
void verifyBackwards(Stack<int> * bracketStack, string equationToCheck, int lengthOfString);
void verifyAbstract(Stack<int> *bracketStack, string equationToCheck, int firstComp, int secondComp,
                    int updateVar(int), string firstStringComparison, string SecondStringComparison);
bool  hasRepeatedElements(LinkedList<int> * input);
int stringToIntWord(string input);
bool getOperations(string input, Stack<int> * bracketStack, Queue<string> * queueSet);

int main(int argc, const char * argv[]) {
    std::string input;
    std::getline(cin, input);
    
    Queue<std::string> * queueSet = new Queue<std::string>();
    Stack<int> * bracketStack = new Stack<int>();
    
    if (getOperations(input, bracketStack, queueSet)) {
        unionSet(getSet(queueSet->dequeue()), getSet(queueSet->dequeue()));
    }
    else{
        interSet(getSet(queueSet->dequeue()), getSet(queueSet->dequeue()));
    }
    
    return 0;
}



bool getOperations(string input, Stack<int> * bracketStack, Queue<string> * queueSet){
    string word = "";
    string letter;
    
    //True for union. False for intersection
    bool whatOperation = true;
    for (int i = 0; input.size(); i++) {
        
        letter = input[i];
        if (letter.compare("(") == 0) {
            bracketStack->push(1);
        }else if(letter.compare(")") == 0){
            bracketStack->pop();
        }
        
        word = word + letter;
        
        if(bracketStack->empty()){
            queueSet->enqueue(word);
        }
        
        if(letter.compare("*")){
            whatOperation = true;
        }

    }
    return whatOperation;
}


int stringToIntWord(string input){
    return 1; //stub
}



LinkedList<int> * stringToSet(string someSetString){
    LinkedList<int> * output = new LinkedList<int>();
    string letter;
    string word = "";
    
    
    for(int i = 0; i < someSetString.length(); i++){
        letter = someSetString[i];
        if (letter.compare(",") == 0){
            output->insertBack(stringToIntWord(word));
            word = "";
        }else if(letter.compare(" ")){
            
        }else{
            word = word + letter;
        }
        
    }
    return output;
}


// REQUIRES: The two sets do not have repeated elements.
// MODIFIES: None
// EFFECTS: Returns the union of sets a and b.
LinkedList<int> * unionSet(LinkedList<int> * a, LinkedList<int> * b){
    LinkedList<int> * output = a;
    
    for (int i = 0; i < b->size(); i++) {
        if (!a->search(b->first()->getInfo())) {
            output->insertBack(b->first()->getInfo());
        }
        b->removeFront();
    }
    
    return output;
}

// REQUIRES: The two sets do not have repeated elements.
// MODIFIES: None.
// EFFECTS: Returns the intersection of sets A and B.
LinkedList<int> * interSet(LinkedList<int> * a, LinkedList<int> * b){
    LinkedList<int> * output = new LinkedList<int>();
    
    for (int i = 0; i < b->size(); i++) {
        if (!a->search(b->first()->getInfo())) {
            output->insertBack(b->first()->getInfo());
        }
        b->removeFront();
    }
    
    
    return output;
}

// REQUIRES:
// MODIFIES:
// EFFECTS:
bool checkEquation(Stack<int> * bracketStack, string equationToCheck, int lengthOfString){
    verifyForwards(bracketStack, equationToCheck, lengthOfString);
    verifyBackwards(bracketStack, equationToCheck, lengthOfString);
    
    return bracketStack->empty();
}


// REQUIRES: lengthOfString is length of equationToCheck.
// MODIFIES: bracketStack
// EFFECTS:  (a)Transverses the string front to back checking that for every open bracket there is a close
//              bracket.
void verifyForwards(Stack<int> * bracketStack, string equationToCheck, int lengthOfString){
    verifyAbstract(bracketStack, equationToCheck, 0, lengthOfString, [](int a){ return ++a;}, "(", ")");
    verifyAbstract(bracketStack, equationToCheck, 0, lengthOfString, [](int a){ return ++a;}, "{", "}");
}

// REQUIRES: lengthOfString is length of equationToCheck.
// MODIFIES: bracketStack
// EFFECTS:  Transverses the string back to front checking that for every open bracket there is a close
//           bracket.
void verifyBackwards(Stack<int> * bracketStack, string equationToCheck, int lengthOfString){
    verifyAbstract(bracketStack, equationToCheck, lengthOfString, 0, [](int a){ return --a;}, ")", "(");
    verifyAbstract(bracketStack, equationToCheck, lengthOfString, 0, [](int a){ return --a;}, "}", "{");
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

bool  hasRepeatedElements(LinkedList<int> * input){
    int dummy;
    
    for (int i = 0; i < input->size(); i++) {
        dummy = input->first()->getInfo();
        input->removeFront();
        if (input->search(dummy)) {
            return true;
        }
    }
    
    return false;
}
