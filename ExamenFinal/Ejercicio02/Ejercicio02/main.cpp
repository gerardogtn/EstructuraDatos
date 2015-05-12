//
//  main.cpp
//  Ejercicio02
//
//  Created by Gerardo Teruel on 5/12/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

#define N 9

void printMatrix(int matrix[N][N]);
void sierpinski(int matrix[N][N]);
void sierpinski(int matrix[N][N], int current);



int main(int argc, const char * argv[]) {
    int matriz[N][N] = {0};
    
    printMatrix(matriz);
    
    sierpinski(matriz);
    
    std::cout << std::endl << std::endl;
    
    printMatrix(matriz);
    
    
}


// REQUIRES: A square matrix.
// MODIFIES: None.
// EFFECTS:  Prints to console the matrix.
void printMatrix(int m[N][N]){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

// REQUIRES: A square matrix.
// MODIFIES: matrix.
// EFFECTS : Simulates Sierpinski carpet on matrix.
void sierpinski(int matrix[N][N]){
    sierpinski(matrix, N);
}

// REQUIRES: A square matrix.
// MODIFIES: matrix.
// EFFECTS : Simulates Sierpinski carpet on matrix.
void sierpinski(int matrix[N][N], int size){
    if (size <= 1) {
        return;
    } else {

        int i0 = size / 3;
        int i  = size / 3;
        int j  = i;
        int a  = i * i;
        
        for (int p = 0; p <= a; p++) {
            matrix[j - 1][i - 1] = 1;
            if (p % i0  == 0) {
                j++;
                i = i0;
            }
            i++;
        }
        
        sierpinski(matrix, size/3);
    }
}