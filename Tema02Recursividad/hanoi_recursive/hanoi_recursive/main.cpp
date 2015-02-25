//
//  main.cpp
//  hanoi_recursive
//
//  Created by Gerardo Teruel on 1/15/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
using namespace std;

void hanoi(int, int, int, int);
int verifyNumDisks(int);

/*
 * Initializes the hanoi-solving algorithm. 
 * a) Prompts the user for the number of disks on the game
 * b) Verifies that the number of disks is an integer greater than one. 
 * c) Assumes that there are only three hanoi sticks.
 */
int main(int argc, const char * argv[]) {
    
    int numDisks;
    
    cout << "Input the number of disks: ";
    cin >> numDisks;
    
    numDisks = verifyNumDisks(numDisks);
    // Precondition is enforced when main executes hanoi.
    hanoi(numDisks, 1, 3, 2);
    
    return 0;
}

/* 
 * REQUIRES: origin, destination, and aux are three consecutive integers that CANNOT be the same
 * MODIFIES: None
 * EFFECTS: Notifies the user of the necessary movements to solve the hanoi game.
 */
void hanoi(int numDisks, int origin, int destination, int aux){
    
    if (numDisks == 1){
        cout << " Move the disk " << numDisks << " from " << origin << " to " << destination << endl;
    }
    else{
        hanoi(numDisks - 1, origin, aux, destination);
        cout << " Move the disk " << numDisks << " from " << origin << " to " << destination << endl;
        hanoi(numDisks -1, aux, destination, origin);
    }
}
/*
 * REQUIRES: None
 * MODIFIES: None
 * EFFECTS:  If the parameter is less than one, prompts the user to enter another integer. 
 *           Otherwise, it returns the value of the parameter. 
 */
int verifyNumDisks(int numDisks){
    if (numDisks < 1){
        cout << "The number of disks must be greater than zero. \n" << "Input the number of disks: ";
        cin >> numDisks;
        numDisks = verifyNumDisks(numDisks);
    }
    
    return numDisks;
}
