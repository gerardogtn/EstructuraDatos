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
    int  i = 0;
    bool found = false;
    
    while (i < sizeOfArray && !found) {
        if (sizeOfArray[i] == keyToSearch) {
            found = true;
        }
        i++;
    }
    return found; 
}


// Performs a binary search on an array until the key is found.
// REQUIRES: The array is sorted.
// MODIFIES: None.
// EFFECTS:  Compares the keyToSearch in to the midvalue of the array. If they are equal, return true. If
// the key is smaller, adjusts the search boundaries (move upperBoundary to middle point). Else, adjust
// the boundary to fit the case (move lowerBoundary to midPoint + 1)
static bool GenericSearch_GenericSearch_h::binarySearch(const T searchingArray[], T keyToSearch,
                                                        int lowerBoundary, int upperBoundary){
    int midPoint = (lowerBoundary + upperBoundary) / 2;
    bool found   = false;
    
    while (lowerBoundary < upperBoundary && !found){
        if (searchingArray[midPoint] == keyToSearch) {
            found = true;
        }
        else if (keyToSearch < searchingArray[midPoint]){
            upperBoundary = midPoint;
        }
        else{
            lowerBoundary = midPoint + 1;
        }
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
#endif
