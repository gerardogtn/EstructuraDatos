//
//  main.cpp
//  Ejercicio02
//
//  Created by Gerardo Teruel on 1/29/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#define N 4

using namespace std;

bool solveMaze(int x, int y, int matrix[N][N]);

int main(int argc, const char * argv[]) {
    
    int MAZE1[N][N] = { { 0, 0, -1, -1},
                        {-1, 0, -1, -1},
                        {-1, 0, -1, -1},
                        {-1, 0,  0,  0}};

    int MAZE2[N][N] = { { 0,  0, -1, -1},
                        {-1,  0, -1, -1},
                        {-1, -1, -1, -1},
                        {-1,  0,  0,  0}};
    
    int MAZE3[N][N] = { { 0,  0,  0,  0},
                        {-1,  0, -1, -1},
                        {-1,  0, -1, -1},
                        {-1,  0,  0,  0}};
    
    int MAZE4[N][N] = { { 0,  0,  0,  0},
                        {-1,  0, -1,  0},
                        {-1, -1, -1,  0},
                        {-1,  0,  0,  0}};
    
    cout << "MAZE1 SHOULD BE SOLVABLE. " << endl;
    cout << "MAZE2 SHOULD NOT BE SOLVABLE. " << endl;
    cout << "MAZE3 SHOULD BE SOLVABLE." << endl;
    cout << "MAZE4 SHOULD BE SOLVABLE. \n" << endl;
    
    cout << ((solveMaze(0, 0, MAZE1))? "MAZE1 IS SOLVABLE. " : "MAZE1 IS NOT SOLVABLE. ") << endl;
    cout << ((solveMaze(0, 0, MAZE2))? "MAZE2 IS SOLVABLE. " : "MAZE2 IS NOT SOLVABLE. ") << endl;
    cout << ((solveMaze(0, 0, MAZE3))? "MAZE3 IS SOLVABLE. " : "MAZE3 IS NOT SOLVABLE. ") << endl;
    cout << ((solveMaze(0, 0, MAZE4))? "MAZE4 IS SOLVABLE. " : "MAZE4 IS NOT SOLVABLE. ") << endl;
    
    return 0;
}


// REQUIRES: None.
// MODIFIES: None.
// EFFECTS:  Produces true if the maze can be solved.
bool solveMaze(int x, int y, int matrix[N][N]){
    bool result;
    
    
    if (x == N - 1 && y == N - 1){
        result = true;
    }
    else if (result == true){
        return true;
    }
    else{
        if (matrix[x+ 1][y] != -1 && x + 1 != N){
            if (solveMaze(x + 1, y, matrix)){
                result = true;
            }
            
        }
        else if (matrix[x][y + 1] != -1 && y + 1 != N){
            if (solveMaze(x, y + 1, matrix)){
                result = true;
            }
        }
    }
    
    return result;
    
}
