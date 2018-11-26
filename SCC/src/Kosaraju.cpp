//
//  Kosaraju.cpp
//  SCC
//
//  Created by Amandine Benza on 28/05/2018.
//  Copyright © 2018 Amandine Benza. All rights reserved.
//

#include "Kosaraju.hpp"

namespace Kosaraju {
    
    // --------
    
    std::stack<Sommet*>* P = new std::stack<Sommet*>();
    std::list<std::list<Sommet*>*>* partition = new std::list<std::list<Sommet*>*>();
    std::list<Sommet*>*G = new std::list<Sommet*>();
    long double tempsExec = 0;
    
    // --------


    
    void postDFS(Sommet *v){
        v->setDansP(true);
        Sommet *w = v->getFirst();

        while(w != nullptr) {
            if(!w->getDansP()) {
                postDFS(w);
            }
            w = v->getNext();
        }
        
       P->push(v);
    }
    
    void DFS(Sommet *v, std::list<Sommet*>* G) {
        v->setDansP(true);
        G->push_back(v);
        
        Sommet *w = v->getFirst();
        
        while(w != nullptr) {
            if(!w->getDansP()) {
                DFS(w,G);
            }
            w = v->getNext();
        }
    }
    
    // id dans graphe doit commencer a 0
    std::list<Sommet*>* transposeGraph() {
        
        //Idee generale :
        // Construire graphe transposés d'indices sans se préoccuper des objets sommets
        // Recupere modele pour construire sommets => Recrée objets à partir des indices
        
        std::list<Sommet*>* transG = new std::list<Sommet*>();
        std::list<std::list<int>*>* itransG = new std::list<std::list<int>*>();
        std::list<Sommet*>::iterator it = G->begin();
        int taille = (int) G->size();
        
        for(int i = 0; i < taille; i++){
            itransG->push_back(new std::list<int>());
        }
        
        std::list<std::list<int>*>::iterator iit = itransG->begin();
        
        // construction du graphe des indices des sommets
        while(it != G->end()){
            Sommet* v = *it;
            Sommet* w = v->getFirst();
            
            while(w != nullptr){
                std::advance(iit, w->getId());
                std::list<int>* wAdjs= *iit;
                
                // ajout
                if(wAdjs != nullptr && wAdjs != NULL){
                    wAdjs->push_back(v->getId());
                }
                
                std::advance(iit, - w->getId());
                w = v->getNext();
            }
            it++;
        }
        
        // ici on connait les adjacences mais en ayant que les ids
        // on cree les objets
        for(int i = 0; i < taille; i++){
            transG->push_back(new Sommet(i));
        }
        
        // reset l'iterateur sur le graphe des entiers genere au dessus
        iit = itransG->begin();
        // reset l'iterateur sur le graphe des sommets
        it = transG->begin();
        // recupere un nouvel iterateur sur le graphe des sommets
        std::list<Sommet*>::iterator it2 = transG->begin();
        
        // tant qu'on a pas atteint la fin du graphe des entiers
        while(it != transG->end()){
            // get l'objet sommet actuel
            Sommet* v = *it;
            
            // get sa liste d'adjacence
            std::list<int>* iadjacents = *iit;
            // get un iterateur sur cette liste
            std::list<int>::iterator iadjacentsIt = iadjacents->begin();
            
            // tant qu'il reste des sommets adjacents a traiter
            while (iadjacentsIt != iadjacents->end()) {
                // recupere l'indice du sommet adjacent
                int transGIndex = *iadjacentsIt;
                
                // accede au sommet objet qui a pour indice transGIndex
                std::advance(it2, transGIndex);
                Sommet* w = *it2;
                
                // cree le successeur de w
                v->AddSuccesseur(w);
                // reset l'iterateur pour que la boucle fonctionne pour les iterations suivantes
                std::advance(it2, -transGIndex);
                // met a jour l'iterateur sur les indices des sommets
                iadjacentsIt++;
            }
            // passe au sommet v suivant
            it++;
            iit++;
        }
        
        return transG;
    }
    
    void parcours(){
        
        std::list<Sommet*>::iterator it = G->begin();
        
        
        while(it != G->end()){ // Pas forcement nécessaire ?
            Sommet* v = *it;
            v->setDansP(false);
            it++;
        }
        
        it = G->begin();
        
        while(it != G->end()){
            Sommet* v = (*it);
            if(!(v)->getDansP())
                postDFS(v);
            
            it++;
        }
        
        
        std::list<Sommet*>* transG = transposeGraph();
        it = transG->begin();
        
        while(it != transG->end()){
            Sommet* v = *it;
            v->setDansP(false);
            it++;
        }
        
        std::list<Sommet *>* C = new std::list<Sommet*>();
        partition->push_back(C);
        
        std::stack<Sommet*>* transP = new std::stack<Sommet*>();
        
        int tailleP = (int) P->size();
        Sommet* tempTab[tailleP];
        
        
        for (int i = 0; i < tailleP; i++) {
            tempTab[tailleP - i - 1] = P->top();
            P->pop();
        }
        
        std::list<Sommet*>::iterator iit = transG->begin();
        for (int i = 0; i < tailleP ; i++) {
            int id = tempTab[i]->getId();
            std::advance(iit, id);
            transP->push(*iit);
            std::advance(iit, -id);
        }
        
        // transP
        while(!transP->empty()) {
            Sommet* v = transP->top();
            transP->pop();
            
            if(!v->getDansP()) {
                DFS(v,*(--partition->end()));
                std::list<Sommet *>* C2 = new std::list<Sommet*>();
                partition->push_back(C2);
                // C = C2;
            }
        }
        
        partition->pop_back();
        
    }
    
    void kosarajuA() {
        
        clock_t t1, t2;
        t1 = clock();
        
        parcours();
        
        t2 = clock();
        tempsExec = (long double)(t2 - t1) / (CLOCKS_PER_SEC / (long double) 1000.0);
        std::cout << "Temps d'execution de Kosaraju : " << tempsExec << "ms" << "\n\n";


    }
    
}
