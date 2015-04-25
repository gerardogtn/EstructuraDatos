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
#include <ctime>
#include <chrono>

class Estudiante;

class Relationship{
    
private:
    std::chrono::time_point<std::chrono::system_clock> startDate;
    std::chrono::time_point<std::chrono::system_clock>   endDate;
    Estudiante aFriend;
    
public:
    
    
    
};
#endif /* defined(__ejercicio02__Relationship__) */
