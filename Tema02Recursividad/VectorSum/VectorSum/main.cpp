//
//  main.cpp
//  VectorSum
//
//  Created by Gerardo Teruel on 1/19/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

//For inputing the vector only.
//#include <algorithm>
//#include <iterator>

using namespace std;

int vectorSum(vector<int> inputVector);


// Initializes the VectorSum program.
// a) Prompts the user to type the elements in a vector.
// b) If there are no elements in the vector, notify the user and terminate the program.
// c) Print the sum of the elements in the vector.
int main(int argc, const char * argv[]) {
    vector<int> inputVector;
    int input;
    
    // User inputs vector int values.
    cout << "Type the numbers to be inserted in the vector, type 987 to stop inserting. \n";
    while (cin >> input && input != 987) {
        inputVector.push_back(input);
    }
    
    // Checks that the vector is not empty. Otherwise
    if (inputVector.size() == 0) {
        cout << "The input is not valid " << endl;
    }
    else {
        cout << "The values that were given for the vector are: ";
        for(int i = 0; i < inputVector.size(); i++) cout << inputVector[ i ] << " ";
        
        cout << "The sum of the values in the vector is: " << vectorSum(inputVector) << endl;

    }
    
}


// Computes the sum of elements in a vector.
// REQUIRES: v is not empty.
// MODIFIES: None.
// Effects: If there is only one element, returns the value of the element.
//          Otherwise, stores the value of the element and calls the function with the other elements
//          in the vector.
int vectorSum(vector<int> v){
    int result = 0;
    
    if (v.size() == 1) {
        result = result + v[0];
    }
    else{
        int zerothElement = v[0];
        v.erase(v.begin());
        result = zerothElement + vectorSum(v);
    }
    
    return result;
}