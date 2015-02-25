//
//  main.cpp
//  EuclideanAlgorithm
//
//  Created by Gerardo Teruel on 1/19/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int euclideanAlgorithm(int m, int n);

// Initializes the Euclidean algorithm for finding the Greatest Common Divisor of two numbers.
// a) Prompts the user to type two numbers.
// b) Verifies that the second number is greater than the first number and that no number is equal to zero.
//      If the number is not valid, the user is notified and the program stops running.
// c) Prints the Greatest Common Divisor of the two numbers.

int main(int argc, const char * argv[]) {
    int m;
    int n;
    
    cout << "Type one number (m): ";
    cin >> m;
    
    cout << "Type another number (n): ";
    cin >> n;
    
    
    if (m <= n || m == 0 || n == 0) {
        cout << "The input is not valid " << endl;
    }
    else {
        cout << "The Greatest Common Divisor of: " << m << " and: " << n << " is: "
        << euclideanAlgorithm(m, n) << endl;
    }
    
}


// Finds the Greatest Common Divisor of two numbers through the Euclidean Algorithm.
// REQUIRES: Two integers (m, n) greater than zero AND m > n
// MODIFIES: None.
// EFFECTS:  If:   the remainder of m / n is zero: n is the GCD.
//           Else: repeat algorithm with n and the remainder.
int euclideanAlgorithm(int m, int n){
    int ratio = m % n;
    
    if (ratio == 0){
        return n;
    }
    else
        return euclideanAlgorithm (m, ratio);
    
}