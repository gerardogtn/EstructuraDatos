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
void Comunidad::printNoRelationsips(){
    bool noRelations = false;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Los siguientes estudiantes NO han tenido relaciones" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    
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
void Comunidad::printMostRelationships(){
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "El estudiante con mayor numero de relaciones es:   " << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    
    if (!miembros.empty()){
        
        Estudiante output = miembros.front();
        int max = output.getNumOfFriends();
        
        for (auto e : miembros) {
            int current = e.getNumOfFriends();
            if (current > max){
                max = current;
                output = e ;
            }
        }
    
        std::cout << output << std::endl;
        
    }else {
        std::cout << "No existe nadie en la comunidad. " << std::endl;
    }
    
    std::cout << std::endl;
}

void Comunidad::printMostStable(){
    
}

void Comunidad::addStudent(Estudiante student){
    miembros.insert(miembros.end(), student);
}