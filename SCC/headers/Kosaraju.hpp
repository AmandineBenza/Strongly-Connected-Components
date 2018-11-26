//
//  Kosaraju.hpp
//  SCC
//
//  Created by Amandine Benza on 28/05/2018.
//  Copyright © 2018 Amandine Benza. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <iostream>
#include <stack>
#include "Utils.hpp"
#include <time.h>


namespace Kosaraju {
    
    extern long double tempsExec;
    extern std::stack<Sommet *>* P; // Pile de sommets
    extern std::list<std::list<Sommet *>*>* partition; // Liste de graphes
    extern std::list<Sommet *>* G; // Liste de sommets
        
    extern void postDFS(Sommet *v);
    extern void DFS(Sommet *v);
    
    extern std::list<Sommet*>* transposeGraph();
    extern void parcours();

    extern void kosarajuA();

}

