//
//  Usuario.cpp
//  Ejercicio02
//
//  Created by Gerardo Teruel on 2/19/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "Usuario.h"

using namespace std;

class Usuario{

private:
    string lastName;
    string firstName;
    int    ife;
    
public:
    Usuario(string nombre, string apellidos, int credencial){
        firstName = nombre;
        lastName = apellidos;
        ife = credencial;
    }
};