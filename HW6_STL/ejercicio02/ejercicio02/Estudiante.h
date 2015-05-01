//
//  Estudiante.h
//  ejercicio02
//
//  Created by Gerardo Teruel on 4/25/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef __ejercicio02__Estudiante__
#define __ejercicio02__Estudiante__

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include "Relationship.h"
#include "boost/date_time/gregorian/gregorian.hpp"

using namespace std;
using namespace boost::gregorian;

class Estudiante{
    friend ostream & operator<<(ostream & os, const Estudiante & student);
    friend bool      operator==(const Estudiante & a, const Estudiante & b); 
    
private:
    string nombre;
    list<Relationship> relaciones; 
    
public:
    Estudiante() {};
    Estudiante(string name) : nombre(name){};
    
    void addRelationship(Estudiante & other);
    void addRelationship(Estudiante & other, date time);
    void addRelationship(Relationship & relation);
    
    void endRelationship(const Estudiante & other);
    void endRelationship(const Estudiante & other, date time);
    void endRelationship(const Relationship & relation);
    
    bool hasHadRelationship() const;
    void printRelationships() const;
    
    int getNumOfFriends() const;
    int getTotalRelationshipTime() const;
    
    string getName() const{
        return nombre; 
    };
    list<Relationship> getRelationships() const{
        return relaciones;
    }
    
    Estudiante copy(const Estudiante & other);
    
    double percentLonely(date init, date end);
    void printLonely(date init, date end);
    
    double percentCompany(date init, date end);
    void printCompany(date init, date end);
};


#endif /* defined(__ejercicio02__Estudiante__) */
