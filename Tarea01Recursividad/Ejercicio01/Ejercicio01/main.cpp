//
//  main.cpp
//  Ejercicio01
//
//  Created by Gerardo Teruel on 1/28/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include <cmath>

#define N 5

using namespace std;

void printMatrix(int matrix[N][N]);
void powersOfTWoMatrix(int matrix[N][N], int curentRow, int curentColumn, int n, int result);


int main(int argc, const char * argv[]) {
    int matrix[N][N] = {0};
    
    powersOfTWoMatrix(matrix, 0, 0, N, 1);
    printMatrix(matrix);
    return 0;
}

// REQUIRES: A square matrix.
// MODIFIES: None.
// EFFECTS:  Prints to console the matrix.
void printMatrix(int m[N][N])
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}


void powersOfTWoMatrix(int matrix[N][N], int currentRow, int currentColumn, int n, int result){
    
    if (currentRow == n - 1 && currentColumn == n - 1 ) {
        matrix[currentRow][currentColumn] = result;
    }
    else if (currentRow == n - 1){
        matrix[currentRow][currentColumn] = result;
        powersOfTWoMatrix(matrix, currentRow, currentColumn + 1, n, result);
    }
    else if (currentColumn == n - 1){
        matrix[currentRow][currentColumn] = result;
        powersOfTWoMatrix(matrix, currentRow + 1, currentColumn, n, result);
    }
    else{
        matrix[currentRow][currentColumn] = result;
        powersOfTWoMatrix(matrix, currentRow + 1 , currentColumn, N, result);
        powersOfTWoMatrix(matrix, currentRow, currentColumn + 1, N, result);
        powersOfTWoMatrix(matrix, currentRow + 1, currentColumn + 1, N, result * 2);
    }
    
}
