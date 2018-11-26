//
//  Gabow.cpp
//  SCC
//
//  Created by Amandine Benza on 29/05/2018.
//  Copyright © 2018 Amandine Benza. All rights reserved.
//

#include "Gabow.hpp"

namespace Gabow {
    
    // --------

    
    int num = 0;
    std::stack<Sommet*>* P = new std::stack<Sommet*>();
    std::stack<Sommet*>* S = new std::stack<Sommet*>();
    std::list<std::list<Sommet*>*>* partition = new std::list<std::list<Sommet*>*>();
    std::list<Sommet*>*G = new std::list<Sommet*>();
    long double tempsExec = 0;
    
    // --------

    
    void parcours(Sommet *v) {
        v->setNum(num); // SetNum de v a num
        num++;
        P->push(v); // Push v dans S et dans P
        S->push(v);
        
        Sommet *w = v->getFirst(); //Pour chaque successeur de v

        while (w != nullptr) {
            if (w->getNum() == -1) { // Si num = -1 => recherche recursive de w
                parcours(w);
            }
            
            else if (!w->getDansP()) { // Si w n'a pas encore de composant fortement connexe
                while (P->top()->getNum() > w->getNum())
                    P->pop(); // Pop les sommets de P jusqu'a ce que le top ait un num inferieur ou egal au num de w
            }
            
            w = v->getNext();
        }
        
        if(v->getId() == P->top()->getId()) { //Si v est le sommet de P
            std::list<Sommet *>* C = new std::list<Sommet*>();
            partition->push_back(C);
            
            while (S->top()->getId() != v->getId()){
                S->top()->setDansP(true);
                C->push_back(S->top());
                S->pop();
            }
            
            S->top()->setDansP(true);
            C->push_back(S->top());
            S->pop();
            P->pop(); //Pop v de P
        }
    }
    
    void gabowA(){
        
        clock_t t1, t2;
        t1 = clock();
        
        for (std::list<Sommet *>::iterator v = G->begin(); v != G->end(); ++v) {
            if ((*v)->getNum() == -1)
                parcours(*v);
        }
        
        t2 = clock();
        
        tempsExec = (long double)(t2 - t1) / (CLOCKS_PER_SEC / (long double) 1000.0);
        std::cout << "Temps d'execution de Gabow : " << tempsExec << "ms" << "\n\n";
    }
}

