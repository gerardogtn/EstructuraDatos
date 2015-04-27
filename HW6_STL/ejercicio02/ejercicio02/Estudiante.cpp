//
//  Estudiante.cpp
//  ejercicio02
//
//  Created by Gerardo Teruel on 4/25/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Estudiante.h"

ostream & operator<<(ostream & os, const Estudiante & student){
    os << student.getName();
    return os;
}



void Estudiante::addRelationship(Estudiante other){
    
}

void Estudiante::addRelationship(Estudiante other, Date time){
    
}

void Estudiante::removeRelationship(Estudiante other){
    
}

void Estudiante::removeRelationship(Estudiante other, Date time){
    
}


bool Estudiante::hasHadRelationship() const{

    return false; //stub
}

void Estudiante::printRelationships() const{
    
}

int Estudiante::getNumOfFriends() const{
    return -1; //stub
}