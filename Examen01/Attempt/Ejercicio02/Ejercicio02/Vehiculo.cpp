//
//  Vehiculo.cpp
//  Ejercicio02
//
//  Created by Gerardo Teruel on 2/19/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Vehiculo.h"
#include <iostream>

using namespace std;

class Vehiculo{
protected:
    int code;
    int brand;
    int year;
    int mileage; // in kilometers.
public:
    
};

class Camioneta: public Vehiculo{
private:
    string traccion;
public:
    Camioneta(int codigo, int marca, int anho, int kilometraje, string traccion){
        code = codigo;
        brand = marca;
        year = anho;
        mileage = kilometraje;
        this->traccion = traccion;
     }
};

class Automobil: public Vehiculo{
public:
    Automobil(int codigo, int marca, int anho, int kilometraje){
        code = codigo;
        brand = marca;
        year = anho;
        mileage = kilometraje;
    }
};

class Motocicleta: public Vehiculo{
private:
    int cilindraje;
public:
    Motocicleta(int codigo, int marca, int anho, int kilometraje, int cilindraje){
        code = codigo;
        brand = marca;
        year = anho;
        mileage = kilometraje;
        this->cilindraje = cilindraje;
    }
    
};
