//
//  Gabow.hpp
//  SCC
//
//  Created by Amandine Benza on 29/05/2018.
//  Copyright © 2018 Amandine Benza. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <iostream>
#include <stack>
#include "Utils.hpp"
#include <time.h>


namespace Gabow {
    
    extern long double tempsExec;
    extern int num; // C
    extern std::stack<Sommet *>* S;
    extern std::stack<Sommet *>* P;

    extern std::list<std::list<Sommet *>*>* partition;
    extern std::list<Sommet *>* G;
    
    extern void parcours(Sommet *v);
    extern void gabowA();
}


