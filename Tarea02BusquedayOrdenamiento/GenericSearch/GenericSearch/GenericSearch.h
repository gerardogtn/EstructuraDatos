//
//  GenericSearch.h
//  GenericSearch
//
//  Created by Gerardo Teruel on 2/25/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef GenericSearch_GenericSearch_h
#define GenericSearch_GenericSearch_h

template <typename T>
class GenericSearch_GenericSearch_h{
    // Proof of existence functions
    static bool linearSearch(const T searchingArray[], T keyToSearch, int sizeOfArray);
    static bool binarySearch(const T searchingArray[], T keyToSearch, int lowerBoundary, int upperBoundary);
    // Proof of position functions
    static int linearSearchPosition(const T searchingArray[], T keyToSearch, int sizeOfArray);
    static int binarySearchPosition(const T searchingArray[], T keyToSearch, int lowerBoundary,
                                    int upperBoundary);
};

// Sequentially searchs for a key in an array.
// REQUIRES: None.
// MODIFIES: None.
// EFFECTS:  If keyToSearch is equal to current value of the array, returns true. If not, transverses the
// array until the key is found, OR until thelast position is reached. If the former occurs, return false.
static bool GenericSearch_GenericSearch_h::linearSearch(const T searchingArray[], T keyToSearch,
                                                        int sizeOfArray){
    i = 0;
    found = false;
    
    while (i < sizeOfArray && !found) {
        if (sizeOfArray[i] == keyToSearch) {
            found = true;
        }
        i++;
    }
    return found; 
}




// Sequentially searchs for a key in an array.
// REQUIRES:
// MODIFIES:
// EFFECTS:




// Sequentially searchs for a key in an array.
// REQUIRES:
// MODIFIES:
// EFFECTS:




// Sequentially searchs for a key in an array.
// REQUIRES:
// MODIFIES:
// EFFECTS:
#endif
