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
    Comunidad(const string _nombre) : nombre(_nombre){}
    Comunidad(const list<Estudiante> memberList) : miembros(memberList){}
    Comunidad(const string _nombre, const list<Estudiante> memberList) : nombre(_nombre), miembros(memberList) {}
    
    void printNoRelationsips() const;
    void printMostRelationships() const;
    void printMostStable() const;
    
    void addStudent(const Estudiante student);
    void removeStudent(const Estudiante student);
    
};
#endif /* defined(__ejercicio02__Comunidad__) */
