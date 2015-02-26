//
//  main.cpp
//  Ejercicio02
//
//  Created by Gerardo Teruel on 2/19/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "Usuario.cpp"
#include "Vehiculo.cpp"
#include "Registro.cpp"

using namespace std;
void compraVenta(Usuario comprador, Vehiculo vehiculo, int Costo, Registro registros[]);
void listadoOrdenado();
void busquedaPorPersona();



int main(int argc, const char * argv[]) {
    // El sistema almacena un maximo de 10 entradas
    const int N = 10;
    std::cout << "Hello, World!\n";
    bool algoMas = false;
    Registro registros[N];
    while(algoMas == false){
        cout << "Que funcionalidad desea implementar?: " << endl;
        cout << "Inserte 1 para adicionar una compra-venta" << endl;
        cout << "Inserte 2 para imprimir el listado de ventas realizadas" << endl;
        cout << "Inserte 3 para listar todos los vehiculos comprados por una persona" << endl;
        
        int n;
        cin >> n;
        
        switch (n) {
            case 1:
                Usuario comprador = Usuario(nombre, apellidos, credencial);
                
                cout << "Que clase de vehiculo se trata?" << endl;
                int n;
                cin >> n;
                
                Vehiculo vehiculo;
                if (n == 1){
                vehiculo = Camioneta(<#int codigo#>, <#int marca#>, <#int anho#>, <#int kilometraje#>, <#string traccion#>)
                } else if (n == 2){
                    vehiculo = Motocicleta(<#int codigo#>, <#int marca#>, <#int anho#>, <#int kilometraje#>, <#int cilindraje#>)
                }
                else(n == 3){
                    vehiculo = Automobil(<#int codigo#>, <#int marca#>, <#int anho#>, <#int kilometraje#>)
                }
                
                
                cout << "Cual es el costo del vehiculo?" << endl;
                int costo;
                cin >> costo;
                
                
                compraVenta(comprador, vehiculo, costo,  registros);
                break;
                
            case 2:
                listadoOrdenado();
                break;
                
            case 3:
                busquedaPorPersona();
                break;
                
            default:
                cout << "No hay comportamiento especificado para el numero insertado." << endl;
                break;
    }
        cout << "Inserte 2 para salir" << endl;
        int blagh;
        cin >> blagh;
        if (blagh == 2){
            algoMas = true;
        }
    }
    
    return 0;
}


