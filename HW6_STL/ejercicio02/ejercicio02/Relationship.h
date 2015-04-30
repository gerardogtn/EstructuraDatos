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
    Estudiante & aFriend;
    date startDate;
    date endDate;
    bool active = true;
    
public:
    Relationship();
    Relationship(Estudiante & _aFriend): aFriend(_aFriend){};
    Relationship(Estudiante & _aFriend, date _startDate) : aFriend(_aFriend), startDate(_startDate){};
    
    Relationship(Estudiante & _aFriend, date _startDate, date _endDate) : aFriend(_aFriend), startDate(_startDate), endDate(_endDate){};
    
    
    
    Estudiante & getFriend() const{
        return aFriend;
    }
    
    date getStartDate() const{
        return startDate;
    }
    
    date getEndDate() const{
        return endDate;
    }
    
    bool isActive() const {
        return active; 
    }
    
    void endRelationship();
    void endRelationship(date);
    
    date_duration getRelationshipTime();
    date_duration getRelationshipTime(date dateLimit);
    
    Relationship copy();
    Relationship & operator=(const Relationship & ref);
};




#endif /* defined(__ejercicio02__Relationship__) */
