//
//  main.cpp
//  ejercicio02
//
//  Created by Gerardo Teruel on 4/25/15.
//  Copyright (c) 2015 Gerardo Teruel. All rights reserved.
//

#include <iostream>
#include "Comunidad.h"


int main(int argc, const char * argv[]) {
    
    Estudiante uno("Jesus");
    Estudiante dos("Pedro");
    Estudiante tres("Karla");
    Estudiante cuatro("Ximena");
    Estudiante cinco("Andres");
    
    Comunidad  community("ITCs");
    
    date A(2015, 01, 01);
    date B(2015, 02, 18);
    date C(2015, 03, 24);
    date D(2015, 04, 21);
    
    uno.addRelationship(dos, A);
    uno.addRelationship(cinco, B);
    dos.addRelationship(tres, A);
    tres.addRelationship(cuatro, B);
    cuatro.addRelationship(cinco, D);
    
    for (auto r : uno.getRelationships()){
        std::cout << r.getEndDate() << ": ";
        std::cout << (r.isActive()? "Activa": "NO activa") << std::endl;
    }
    uno.endRelationship(dos, B);
    uno.endRelationship(cinco, C);
    
    for (auto r : uno.getRelationships()){
        std::cout << r.getEndDate() << ": ";
        std::cout << (r.isActive()? "Activa": "NO activa") << std::endl;
    }
    
    dos.endRelationship(tres, B);
    tres.endRelationship(cuatro, C);
    
    community.addStudent(uno);
    community.addStudent(dos);
    community.addStudent(tres);
    community.addStudent(cuatro);
    community.addStudent(cinco);
    
    //community.printMostRelationships();
    //community.printNoRelationsips();
    //community.printMostStable();
    
    return 0;
}
