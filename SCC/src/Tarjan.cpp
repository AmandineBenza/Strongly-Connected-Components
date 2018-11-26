//
//  Tarjan.cpp
//  SCC
//
//  Created by Amandine Benza on 28/05/2018.
//  Copyright © 2018 Amandine Benza. All rights reserved.
//

#include "Tarjan.hpp"

namespace Tarjan {
    
    // --------

    
    int num = 0;
    long double tempsExec = 0;
    std::stack<Sommet*>* P = new std::stack<Sommet*>();
    std::list<std::list<Sommet*>*>* partition = new std::list<std::list<Sommet*>*>();
    std::list<Sommet*>*G = new std::list<Sommet*>();
    
    // --------

    
    void parcours(Sommet *v) {
        num++;
        v->setNum(num);
        v->setNumAccessible(num);
        P->push(v);
        v->setDansP(true);
        Sommet *w = v->getFirst(); //Premier sommet adjacent
        
        while (w != nullptr) {
            if (w->getNum() == -1) {
                parcours(w);
                v->setNumAccessible(Utils::min(v->getNumAccessible(), w->getNumAccessible()));
            }
            else if (w->getDansP()) {
                v->setNumAccessible(Utils::min(v->getNumAccessible(),w->getNum()));
            }
            w = v->getNext();
        }
        
        if (v->getNumAccessible() == v->getNum()) {
            std::list<Sommet *>* C = new std::list<Sommet*>();
        
            do {
                w = P->top();
                P->pop();
                w->setDansP(false);
                C->push_back(w);
            } while (v->getId() != w->getId());
            partition->push_back(C);
        }
    }
    
    void tarjanA(){
        
        clock_t t1, t2;
        t1 = clock();
        
        for (std::list<Sommet *>::iterator v = G->begin(); v != G->end(); ++v) {
            if ((*v)->getNum() == -1)
                parcours(*v);
        }
        
        t2 = clock();
        tempsExec = (long double)(t2 - t1) / (CLOCKS_PER_SEC / (long double) 1000.0);
        std::cout << "Temps d'execution de Tarjan : " << tempsExec << "ms" << "\n\n";

    }
    
}

