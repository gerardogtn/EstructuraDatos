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
void sierpinski(int matrix[N][N], int current, int step);
int power(int base, int exponent);



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
    sierpinski(matrix, N, 2);
}

// REQUIRES: A square matrix.
// MODIFIES: matrix.
// EFFECTS : Simulates Sierpinski carpet on matrix.
void sierpinski(int matrix[N][N], int size, int step){
    if (size <= 1) {
        return;
    } else {
        
        for (int j = 1; j <= step; j++) {
            int i0 = size * j / 3;
            int i  = size * j / 3;
            int k  = i * j;
            int a  = size * size / 9;
            
            for (int p = 0; p <= a; p++) {
                matrix[k - 1][i - 1] = 1;
                if (p % i0  == 0) {
                    k++;
                    i = i0;
                }
                i++;
            }
        }
        
        
        sierpinski(matrix, size/3, step * 2);
    }
}
