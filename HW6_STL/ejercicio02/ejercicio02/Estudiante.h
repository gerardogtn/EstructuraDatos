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

using namespace std;

class Estudiante{
    typedef std::chrono::time_point<std::chrono::system_clock> Date;
    friend ostream & operator<<(ostream & os, const Estudiante & student);
    
private:
    string nombre;
    list<Relationship> relaciones; 
    
public:
    Estudiante();
    
    void addRelationship(const Estudiante other);
    void addRelationship(const Estudiante other, const Date time);
    void removeRelationship(const Estudiante other);
    void removeRelationship(const Estudiante other, const Date time);
    
    bool hasHadRelationship() const;
    void printRelationships() const;
    
    int getNumOfFriends() const;
    string getName() const{
        return nombre; 
    };
};


#endif /* defined(__ejercicio02__Estudiante__) */
