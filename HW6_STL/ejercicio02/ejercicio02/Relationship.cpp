//
//  Relationship.cpp
//  ejercicio02
//
//  Created by Gerardo Teruel on 4/25/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Relationship.h"


// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Returns the time between the start of a relationship and now.
days Relationship::getRelationshipTime(){
    return getRelationshipTime(day_clock::local_day());
}


// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Returns the time between the start of a relationship and dateLimit.
days Relationship::getRelationshipTime(date dateLimit){
    days output = dateLimit - startDate;
    return output;
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
    Relationship output(this->getStartDate(), this->getFriend());
    
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
    this->active  = false;
    this->endDate = _endDate;
}



