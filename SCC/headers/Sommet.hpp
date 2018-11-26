//
//  Sommet.hpp
//  SCC
//
//  Created by Amandine Benza on 27/05/2018.
//  Copyright © 2018 Amandine Benza. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <iterator>
#include <list>

class Sommet{
    int num;
    int numAccessible;
    int id;
    bool dansP;
    std::list<Sommet *> successeurs; // Liste de sucesseurs
    std::list<Sommet *>::iterator it; //Iterateur de la liste de sucesseurs
    std::string nom;
    
public:
    Sommet(std::string nom, int id);
    Sommet(int id);
    void setNum(int x);
    void setNumAccessible(int x);
    void setDansP(bool x);
    void AddSuccesseur(Sommet *b);
    
    Sommet *getFirst();
    Sommet *getNext();
    int getNum();
    int getNumAccessible();
    bool getDansP();
    std::string getNom();
    int getId();
    
    void resetSommet();
    
    void printSommetSucess(std::string debut);
    void printSommet(std::string debut);
};

