//
//  Comunidad.h
//  ejercicio02
//
//  Created by Gerardo Teruel on 4/25/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef __ejercicio02__Comunidad__
#define __ejercicio02__Comunidad__

#include <stdio.h>
#include "Estudiante.h"
#include <string>
#include <list>

using namespace std;


class Comunidad{
    
private:
    list<Estudiante> miembros;
    string nombre = "Anonimo";
    
public:
    Comunidad(){}
    Comunidad(string _nombre) : nombre(_nombre){}
    Comunidad(list<Estudiante> memberList) : miembros(memberList){}
    Comunidad(string _nombre, list<Estudiante> memberList) : nombre(_nombre), miembros(memberList) {}
    
    void printNoRelationsips();
    void printMostRelationships();
    void printMostStable();
    
    void addStudent(Estudiante student);
    void removeStudent(Estudiante student); 
    
};
#endif /* defined(__ejercicio02__Comunidad__) */
