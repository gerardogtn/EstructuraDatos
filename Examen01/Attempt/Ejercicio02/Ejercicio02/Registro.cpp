//
//  Registro.cpp
//  Ejercicio02
//
//  Created by Gerardo Teruel on 2/19/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "Registro.h"
#include "Usuario.cpp"
#include "Vehiculo.cpp"

using namespace std;

class Registro{
private:
    int montoDeVenta;
    Vehiculo vehiculoVendido;
    //Usuario comprador;
public:
    Registro(){
        
    }
    Registro(int costo, Vehiculo vehiculoComprado){
        montoDeVenta = costo;
        this->vehiculoVendido = vehiculoComprado;
        //this->comprador = comprador;
    }
};