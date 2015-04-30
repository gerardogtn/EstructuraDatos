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
    
    community.addStudent(uno);
    community.addStudent(dos);
    community.addStudent(tres);
    community.addStudent(cuatro);
    community.addStudent(cinco);
    
    community.printMostRelationships();
    community.printNoRelationsips();
    community.printMostStable();
    
    
    return 0;
}
