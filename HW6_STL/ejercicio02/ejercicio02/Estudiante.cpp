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

bool operator==(const Estudiante & a, const Estudiante & b){
    bool output = a.getName() == b.getName();
    
    if (a.getNumOfFriends() != b.getNumOfFriends()){
        return false;
    }
    
    return output;
}


void Estudiante::addRelationship(Estudiante & other){
    addRelationship(other, day_clock::local_day());
}

void Estudiante::addRelationship(Estudiante & other, date time){
    relaciones.insert(relaciones.end(), Relationship(other, time));
}

void Estudiante::addRelationship( Relationship & relation){
    relaciones.insert(relaciones.end(), relation);
}


void Estudiante::endRelationship(const Estudiante & other){
    endRelationship(other, day_clock::local_day());
}

void Estudiante::endRelationship(const Estudiante & other, const date time){
    for (auto e : relaciones){
        if (e.getFriend() == other && e.isActive()){
            e.endRelationship(time);
        }
    }
}


bool Estudiante::hasHadRelationship() const{
    return !relaciones.empty();
}

void Estudiante::printRelationships() const{
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout <<  getName() << " ha tenido relaciones con : " << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    
    for (auto e: relaciones){
        std::cout << e << std:: endl;
    }
    std::cout << std::endl;
}

int Estudiante::getNumOfFriends() const{
    return (int) relaciones.size();
}


Estudiante copy(const Estudiante & other){
    Estudiante output(other.getName());
    for (auto e : other.getRelationships()){
        output.addRelationship(e);
    }
    
    return output;
}



date_duration Estudiante::getTotalRelationshipTime() const{
    date_duration output;
    for (auto r : relaciones){
        output = output + r.getRelationshipTime();
    }
    return output;
}



