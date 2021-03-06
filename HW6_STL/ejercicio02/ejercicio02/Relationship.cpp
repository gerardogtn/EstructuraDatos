//
//  Relationship.cpp
//  ejercicio02
//
//  Created by Gerardo Teruel on 4/25/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Relationship.h"

ostream & operator<<(ostream & os, const Relationship &relationship){
    os << "Relacion con: " << relationship.getFriend(); 
    return os;
}


// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Returns the time between the start of a relationship and now.
int Relationship::getRelationshipTime(){
    if (isActive()){
        return getRelationshipTime(day_clock::local_day());
        
    } else{
        return getRelationshipTime(endDate);
    }
    
    
}


// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Returns the time between the start of a relationship and dateLimit.
int Relationship::getRelationshipTime(date dateLimit){
    date_duration output;
    if (isActive()){
        output = dateLimit - startDate;
        
    } else{
        output = endDate - startDate; 
    }
    return (int) output.days();
}


// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Overloads string output operator.
ostream & operator<<(ostream &os, Relationship &relationship){
    
    os << "La relacion con: ";
    //os << relationship.getFriend();
    os << " : ";
    if (relationship.isActive()) {
        os << "Es activa." << endl;
        os << "Lleva una duracion de: " << relationship.getRelationshipTime() << endl;
    }else {
        os << "Ya termino" << endl;
        os << "Tuvo una duracion de: " << relationship.getRelationshipTime(relationship.getEndDate()) << endl;
    }
    
    return os;
}


// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Returns a copy of this.
Relationship Relationship::copy(){
    Relationship output(this->getFriend(), this->getStartDate());
    
    if (!isActive()) {
        output.endRelationship(this->getEndDate());
    }
    
    return output;
}
 
// REQUIRES: None.
// MODIFIES: this.
// EFFECTS:  Sets this end date to now and sets active to false.
// Ends the relationship.
void Relationship::endRelationship(){
    endRelationship(day_clock::local_day());
}

// REQUIRES: None.
// MODIFIES: this.
// EFFECTS:  Sets this end date to _endDate and sets active to false.
// Ends the relationship at a particular date.
void Relationship::endRelationship(date _endDate){
    makeInactive();
    setEndDate(_endDate);
}


Relationship & Relationship::operator=(const Relationship & ref){
    Relationship output(this->getFriend(), this->getStartDate());
    if(!isActive()){
        output.endRelationship(this->getEndDate());
    }
    return output;
}


