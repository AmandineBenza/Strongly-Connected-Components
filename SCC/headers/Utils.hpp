//
//  Utils.hpp
//  SCC
//
//  Created by Amandine Benza on 28/05/2018.
//  Copyright © 2018 Amandine Benza. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include "Sommet.hpp"

namespace Utils {
    
    extern int min(int a, int b);
    extern void imprimerGraphe(std::list<Sommet *> *G); //Print un graphe
    void imprimerGrapheSucess(std::list<Sommet *> *G); //Print un graphe + sucesseurs de chaque sommet
    extern void imprimerGraphes(std::list<std::list<Sommet *>*>* partition); //Print CFC
    extern void imprimerPile(std::stack<Sommet *>* P); //Print une pile
    extern void resetListeSommets(std::list<Sommet *> *Liste);
    extern void pushGraph(std::list<Sommet *> *GrapheGen, std::list<Sommet *> *GraphAlgo);
    extern Sommet *ajouterSiAbsent(std::list<Sommet *>* Sommets, int s);
}

