//
//  main.cpp
//  Ejercicio03
//
//  Created by Gerardo Teruel on 1/26/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>

using namespace std;

int numPaths(int x, int y);
bool isNValid(int n);
bool isMValid(int m);

int main(int argc, const char * argv[]) {
    
    int n;
    int m;
    
    cout << "Inserte el valor de n (numero de columnas)" << endl;
    cin >> n;
    
    cout << "Inserte el valor de m (numero de filas)" << endl;
    cin >> m;
    
    if (isNValid(n) && isMValid(m)){
        cout << "El numero de caminos distintos es: " << numPaths(n - 1, m -1) << endl;
    }
    else if (!isNValid(n)){
        cout << "No es posible calcular el numero de caminos distintos, ya que el valor de n es invalido."
        << "Un valor valido de n es un numero positivo tal que n - 1 sea multiplo de tres." <<endl;
    }
    else{
        cout << "No es posible calcular el numero de caminos distintos, ya que el valor de m es invalido."
        << " Un valor valido de n debe de ser un numero non mayor que uno." <<endl;
    }
    

}


// Requires: x is a multiple of 3. y is a multiple of 2.
// MODIFIES: None.
// EFFECTS:  Returns the number of possible paths a robot can take.
int numPaths(int x, int y){
    
    int result = 0;
    
    if (x == 0 && y == 0) {
        result+= 0;
    }
    else if (x == 0 || y ==0){
       result+= 1;
    }
    else {
        result+= numPaths(x - 3, y);
        result+= numPaths(x, y - 2);
    }
  
    return result;
}


// Requires: None.
// Modifies: None.
// Effects:  Returns true if the input is valid [if (n-1) is a positive multiple of 3]. False otherwise.
bool isNValid(int n){
    
    if (n > 0) {
        int r = (n -1) % 3;
        return r == 0;
    }
    else{
        return false;
    }
}

// Requires: None.
// Modifies: None.
// Effects:  Returns true if the input is valid [if (n-1) is a positive multiple of 2]. False otherwise.
bool isMValid(int m){
    if (m > 0) {
        int r = (m -1) % 2;
        return r == 0;
    }
    else{
        return false;
    }
}
