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
#include <ctime>
#include <chrono>
#include "Relationship.h"

using namespace std;

class Estudiante{
    friend ostream & operator<<(ostream & os, Estudiante student);
    
private:
    int maxNumOfFriends;
    int matricula;
    string nombre;
    Relationship a; 
    bool hadRelationship;
    
public:
    Estudiante();
    
    void addRelationship(Estudiante other);
    void addRelationship(Estudiante other, time date);
    void removeRelationship(Estudiante other);
    void removeRelationship(Estudiante other, time date);
    
    bool hasRelationship();
    bool hasHadRelationship();
};


#endif /* defined(__ejercicio02__Estudiante__) */
