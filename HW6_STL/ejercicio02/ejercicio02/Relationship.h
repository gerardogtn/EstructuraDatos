//
//  Relationship.h
//  ejercicio02
//
//  Created by Gerardo Teruel on 4/25/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#ifndef __ejercicio02__Relationship__
#define __ejercicio02__Relationship__

#include <stdio.h>
#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"

using namespace std;
using namespace boost::gregorian;


// FORWARD CLASS DECLARATION.
class Estudiante;

class Relationship{
    friend ostream & operator<<(ostream & os, const Relationship &relationship);
    
    
private:
    Estudiante &aFriend;
    date startDate;
    date endDate;
    bool active = true;
    
public:
    Relationship();
    Relationship(date _startDate, Estudiante & _aFriend) : startDate(_startDate), aFriend(_aFriend) {}
    ~Relationship(); 
    
    Estudiante & getFriend(){
        return aFriend;
    }
    
    date getStartDate(){
        return startDate;
    }
    
    date getEndDate(){
        return endDate;
    }
    
    bool isActive(){
        return active; 
    }
    
    void endRelationship();
    void endRelationship(date);
    
    
    days getRelationshipTime();
    days getRelationshipTime(date dateLimit);
    
    Relationship copy(); 
    
};




#endif /* defined(__ejercicio02__Relationship__) */
