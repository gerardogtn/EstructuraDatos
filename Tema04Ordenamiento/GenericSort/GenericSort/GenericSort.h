//
//  GenericSort.h
//  GenericSort
//
//  Created by Gerardo Teruel on 2/28/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef GenericSort_GenericSort_h
#define GenericSort_GenericSort_h


template<class T>
class GenericSort{
    static void bubbleSort();
    static void insertionSort();
    static void selectionSort();
    
    static void quicksort(T [], int, int, bool(*) (T, T));
    static void mergesort(T [], int, int, bool(*) (T, T), int);
    static void merge(T [], int, int, int, bool(*) (T, T), int);
    
    static bool asc(T, T);
    static bool desc(T, T);
};


template<typename T>
GenericSort<T>::asc(T a, T b){
    return a > b;
}

template<typename T>
GenericSort<T>::desc(T a, T b){
    return a < b;
}

template<typename T>
GenericSort<T>::quicksort(T arrayToSort[], int first, int last, bool compare(T a, T b)){
    
}

#endif
