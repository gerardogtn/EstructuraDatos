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
class GenericSearch{
public:
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
template <typename T>
bool GenericSearch<T>::linearSearch(const T searchingArray[], T keyToSearch,
                                                        int sizeOfArray){
    int  i = 0;
    bool found = false;
    
    while (i < sizeOfArray && !found) {
        if (searchingArray[i] == keyToSearch) {
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
template <typename T>
bool GenericSearch<T>::binarySearch(const T searchingArray[], T keyToSearch,
                                                        int lowerBoundary, int upperBoundary){
    int lowBound = lowerBoundary;
    int upBound  = upperBoundary;
    int midPoint;
    bool found   = false;
    
    while (lowBound < upBound && !found){
        
        midPoint = (lowBound + upBound) / 2;
        
        if (searchingArray[midPoint] == keyToSearch) {
            found = true;
        }
        else if (keyToSearch < searchingArray[midPoint]){
            upBound  = midPoint;
        }
        else{
            lowBound = midPoint + 1;
        }
    }
    
    return found;
}



// Sequentially searchs for a key in an array.
// REQUIRES: None.
// MODIFIES: None.
// EFFECTS:  If keyToSearch is equal to current value of the array, returns the index. If not, transverses
// the array until the key is found, OR until thelast position is reached. If the former occurs, return
// -1.
template <typename T>
int GenericSearch<T>::linearSearchPosition(const T searchingArray[], T keyToSearch,
                                                        int sizeOfArray){
    int  i = 0;
    bool found = false;
    
    while (i < sizeOfArray && !found) {
        if (searchingArray[i] == keyToSearch) {
            found = true;
        }
        i++;
    }
    
    
    if (found) {
        return --i;
    }else{
        return -1;
    }
}



// Performs a binary search on an array until the key is found.
// REQUIRES: The array is sorted.
// MODIFIES: None.
// EFFECTS:  Compares the keyToSearch in to the midvalue of the array. If they are equal, return the
// position of the midvalue. If the key is smaller, adjusts the search boundaries (move upperBoundary to
// middle point). Else, adjust the boundary to fit the case (move lowerBoundary to midPoint + 1). If no
// value is found, returns -1.
template <typename T>
int GenericSearch<T>::binarySearchPosition(const T searchingArray[], T keyToSearch,
                                                        int lowerBoundary, int upperBoundary){
    int lowBound = lowerBoundary;
    int upBound  = upperBoundary;
    int midPoint = 0; //STUB
    bool found   = false;
    
    while (lowBound < upBound && !found){
        
        midPoint = (lowBound + upBound) / 2;
        
        if (searchingArray[midPoint] == keyToSearch) {
            found = true;
        }
        else if (keyToSearch < searchingArray[midPoint]){
            upBound  = midPoint;
        }
        else{
            lowBound = midPoint + 1;
        }
    }
    
    if (found) {
        return midPoint;
    }else{
        return -1;
    }
}

#endif /* defined(GenericSearch_GenericSearch_h) */