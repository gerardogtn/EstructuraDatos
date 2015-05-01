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
    for (auto r : relaciones){
        if (r.getFriend() == other && r.isActive()){
            r.endRelationship(time);
            return;
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
        std::cout << e.getFriend().getName()  << std:: endl;
        std::cout << "          por " << e.getRelationshipTime() << " dias." << std::endl;
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



int Estudiante::getTotalRelationshipTime() const{
    int output = 0;
    for (auto r : relaciones){
        output = output + r.getRelationshipTime();
    }
    return output;
}


double Estudiante::percentLonely(date init, date end){
    double output;
    
    int numerator = relaciones.front().getRelationshipTime();
    
    for (auto r: relaciones){
        int max = r.getRelationshipTime();
        if (max > numerator){
            numerator = max;
        }
    }
    
    output = numerator / (end - init).days();
    output = output*100;
    return output;
}

void Estudiante::printLonely(date init, date end){
    std::cout << percentLonely(init, end) << "%" << std::endl;
}


double Estudiante::percentCompany(date init, date end){
    return 100 - percentLonely(init, end);
}

void Estudiante::printCompany(date init, date end){
    std::cout << percentCompany(init, end) << "%" << std::endl;
}


