//
//  Utils.cpp
//  SCC
//
//  Created by Amandine Benza on 28/05/2018.
//  Copyright © 2018 Amandine Benza. All rights reserved.
//

#include "Utils.hpp"

namespace Utils {
    
    int min(int a, int b) {
        if (a < b)
            return a;
        else
            return b;
    }
    
    void imprimerGraphe(std::list<Sommet *> *G) {
        std::list<Sommet *>::iterator i;
        for (i = G->begin(); i != G->end(); ++i) {
            (*i)->printSommet(""); //Appelle fonction print de chaque sommet du graphe
            std::cout << "|";
        }
        std::cout << "\n\n";
    }
    
    void imprimerGrapheSucess(std::list<Sommet *> *G) {
        std::list<Sommet *>::iterator i;
        for (i = G->begin(); i != G->end(); ++i) {
            (*i)->printSommetSucess(""); //Appelle fonction print de chaque sommet du graphe
            std::cout << "|";
        }
        std::cout << "\n\n";
    }
    
    void imprimerGraphes(std::list<std::list<Sommet *>*>* partition) {
        std::list<std::list<Sommet *>*>::iterator it;
        int i = 1;
        for (it = partition->begin(); it != partition->end(); ++it) {
            std::cout << "Graphe " << i++ << std::endl;
            imprimerGraphe(*it);
            // imprimerGrapheSucess(*it);
        }
    }
    
     void imprimerPile(std::stack<Sommet *>* P) {
         int size = (int) P->size();
         Sommet* tmpArray[P->size()];
         
         int i = 0;
         
         while(!P->empty()){
             tmpArray[i++] = P->top();
             P->top()->printSommet("");
             std::cout << "|\n" << std::endl;
             P->pop();
         }
         
         for(i = size - 1; i >= 0; --i){
             P->push(tmpArray[i]);
         }
         
         // (*i)->printSommet("");
         // std::cout << "|";
         // std::cout << "\n\n";         
        
    }
    
    void resetListeSommets(std::list<Sommet *> *Sommets) {
        std::list<Sommet*>::iterator it = Sommets->begin();
        
        while(it != Sommets->end()){
            Sommet* v = *it;
            v->resetSommet();
            it++;
        }
    }
    
    void pushGraph(std::list<Sommet *> *GrapheGen, std::list<Sommet *> *GraphAlgo) {
        std::list<Sommet*>::iterator it = GrapheGen->begin();
        
        while(it != GrapheGen->end()){
            GraphAlgo->push_back((*it));
            it++;
        }
    }
    
    
    Sommet *ajouterSiAbsent(std::list<Sommet *>* Sommets, int s) { // Ajoute un sommet dans un graph si le sommet est absent du graph
        std::list<Sommet*>::iterator it = Sommets->begin();
        Sommet *r;
        
        while(it != Sommets->end() && (*it)->getId() != s){ // Tant qu'on est pas à la fin du graph et qu'on ne trouve pas le sommet
            it++;
        }
        if (it == Sommets->end()) { // Si à la fin du parcours on ne trouve pas le sommet à ajouter
            Sommets->push_back(r = new Sommet(s)); // On l'ajoute au graphe
        } else {
            r = *it; // Sinon il existait déjà et = *it
        }
        
        return r;
    }


}

