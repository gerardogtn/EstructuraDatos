//
//  main.cpp
//  Ejercicio01
//
//  Created by Gerardo Teruel on 2/19/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>

using namespace std;
string intToHexadecimal(int n, string result);

int main(int argc, const char * argv[]) {
    cout << "Inserte el numero entero que desea convertir a hexadecimal: ";
    
    int n;
    cin >> n;
    
    if (n < 0 ) {
        cout << "El numero no es valido";
    }
    else{
        cout << "El valor de n en hexadecimal es: " << intToHexadecimal(n, "")<< endl;
    }
    
    return 0;
}

// Transforms an integer to hexadecimal base.
// Requires: n is an integer.
// MODIFIES: NONE.
// EFFECTS:  Recursively transforms a decimal integer to hexadecimal base.
string intToHexadecimal(int n, string result){
    int quotient = n % 16;
    string quotientS;
    
    switch (quotient) {
        case 10:
            quotientS = "A";
            break;
        case 11:
            quotientS = "B";
            break;
        case 12:
            quotientS = "C";
            break;
        case 13:
            quotientS = "D";
            break;
        case 14:
            quotientS = "E";
            break;
        case 15:
            quotientS = "F";
            break;
        default:
            quotientS = to_string(quotient);
            break;
    }
    
    if (n < 16){
        result = result.append(quotientS);
        return result;
    }
    else{
        result = result.append(intToHexadecimal(n / 16, result));
        //intToHexadecimal(n / 16, result.append(quotientS));
    }
    
    return result;
}

