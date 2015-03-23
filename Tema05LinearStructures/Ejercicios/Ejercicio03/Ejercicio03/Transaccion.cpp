//
//  Transaccion.cpp
//  Ejercicio03
//
//  Created by Gerardo Teruel on 3/23/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <functional>
#include "Transaccion.h"
//using namespace std;

class Transaccion{
    
private:
    enum tipoDeTransaccion {RETIRO, DEPOSITO, CONSULTA, ACTUALIZACION, PAGOS};
    double time;
    
public:
    Transaccion() {}
    
    void establecerTipo(std::string);
    void establecerTipo(int);
    
};

