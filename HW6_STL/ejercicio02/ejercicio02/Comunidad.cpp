//
//  Comunidad.cpp
//  ejercicio02
//
//  Created by Gerardo Teruel on 4/25/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include "Comunidad.h"

// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Prints the people in the community that hasn't had relationships.
//           If everyone has had relationships, notifies the client, same if the community is empty.
void Comunidad::printNoRelationsips() const{
    bool noRelations = false;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Los siguientes estudiantes NO han tenido relaciones: " << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    
    if (!miembros.empty()){
        
        for (auto s : miembros){
            if (!s.hasHadRelationship()) {
                std::cout << s << std::endl;
                noRelations = true;
            }
        }
        
        if(!noRelations){
            std::cout << "Todos los estudiantes han tenido relaciones. " << std::endl;
        }
        
    }else {
        std::cout << "No existe nadie en la comunidad. " << std::endl;
    }
    
    std::cout << std::endl;
}


// REQUIRES: None.
// MODIFIES: None.
//  EFFECTS: Prints the people in the community that has the most relationships (first found).
//           If the community is empty, notify the client.
void Comunidad::printMostRelationships() const{
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "El estudiante con mayor numero de relaciones es:   " << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    
    if (!miembros.empty()){
        
        Estudiante output = miembros.front();
        int max = output.getNumOfFriends();
        int switches = 0;
        
        for (auto e : miembros) {
            int current = e.getNumOfFriends();
            if (current > max){
                max = current;
                output = e ;
                switches++;
            }
        }
    
        if(switches > 0 && output.getRelationships().empty()){
            std::cout << output << std::endl;
        } else {
            std::cout << "No existe nadie con una relacion" << std::endl;
        }
        
        
    }else {
        std::cout << "No existe nadie en la comunidad. " << std::endl;
    }
    
    std::cout << std::endl;
}

void Comunidad::printMostStable() const{
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "El estudiante con relaciones mas estables es:      " << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    
    if (!miembros.empty()){
        
        Estudiante output;
        date_duration max;
        bool exit = false;
        
        for (auto e: miembros) {
            exit = exit || e.hasHadRelationship();
        }
        
        if (exit) {
            std::cout << "No existe nadie con una relacion" << std::endl;
            return; 
        }
        
        for (auto e : miembros) {
            if (e.hasHadRelationship()){
                
                date_duration current = output.getTotalRelationshipTime()/ output.getNumOfFriends();
                if (current > max){
                    max = current;
                    output = e ;
                }
                
            }
        }
        
        std::cout << output << std::endl;
        
    }else {
        std::cout << "No existe nadie en la comunidad. " << std::endl;
    }
    
    std::cout << std::endl;
}

void Comunidad::addStudent(const Estudiante student){
    miembros.insert(miembros.end(), student);
}

void Comunidad::removeStudent(const Estudiante student){
    miembros.remove(student);
}

