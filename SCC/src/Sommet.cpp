//
//  Sommet.cpp
//  SCC
//
//  Created by Amandine Benza on 27/05/2018.
//  Copyright © 2018 Amandine Benza. All rights reserved.
//

#include "Sommet.hpp"

Sommet::Sommet(std::string n, int i) {
    nom = n;
    num = -1;
    numAccessible = -1;
    dansP = false;
    id = i;
}

Sommet::Sommet(int i) {
    nom = "";
    id = i;
    num = -1;
    numAccessible = -1;
    dansP = false;
}

//---- SET ---- //

void Sommet::setNum(int x) {
    num = x;
}
void Sommet::setNumAccessible(int x) {
    numAccessible = x;
}

void Sommet::setDansP(bool x) {
    dansP = x;
}

void Sommet::AddSuccesseur(Sommet *b) {
    successeurs.push_back(b);
}

//---- GET ---- //

Sommet * Sommet::getFirst(){ //Premier successeurs
    if(successeurs.size() == 0){
        return nullptr;
    }
    
    it = successeurs.begin();
    return *it;
}

Sommet * Sommet::getNext() { //Successeur suivant
    if(successeurs.size() == 0){
        return nullptr;
    }
    it++;
    if (it != successeurs.end())
        return *it;
    else
        return nullptr;
}

int Sommet::getNum() {
    return num;
}
int Sommet::getNumAccessible() {
    return numAccessible;
}

std::string Sommet::getNom() {
    return nom;
}

bool Sommet::getDansP() {
    return dansP;
}

int Sommet::getId() {
    return id;
}


//----------- //


void Sommet::resetSommet(){
    num = -1;
    numAccessible = -1;
    dansP = false;
}

void Sommet::printSommetSucess(std::string debut) {
    std::list<Sommet *>::iterator i;
    if(nom == "") {
        std::cout << debut << "Sommet " << id << "\n";
    }
    else {
        std::cout << debut << "Sommet " << nom << "\n";
    }
    for (i = successeurs.begin(); i != successeurs.end(); ++i) {
        if(nom == "") {
        std::cout << "\t" << (*i)->getId() << "\n";
        }
        else {
            std::cout << "\t" << (*i)->getNom() << "\n";
        }
    }
}

void Sommet::printSommet(std::string debut) {
    if(nom == "") {
        std::cout << debut << "Sommet " << id << " ";
    }
    else {
        std::cout << debut << "Sommet " << nom << " ";
    }
}

