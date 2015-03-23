//
//  main.cpp
//  Ejercicio02
//
//  Created by Gerardo Teruel on 3/23/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Stack.h"

using namespace vcn;
using namespace std;
int main(int argc, const char * argv[]) {
    string sentence;
    string word;
    Stack<string> * stackToPrint = new Stack<string>;
    
    getline(cin, sentence);
    cout << sentence << endl;
    
    istringstream iss(sentence);
    while(iss >> word) {
        stackToPrint->push(word);
    }
    
    cout << *stackToPrint << endl;
    delete stackToPrint;
    
    return 0;
}
