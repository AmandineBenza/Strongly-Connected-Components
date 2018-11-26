//
//  main.cpp
//  SCC
//
//  Created by Amandine Benza on 27/05/2018.
//  Copyright © 2018 Amandine Benza. All rights reserved.
//

#include "Tarjan.hpp"
#include "Kosaraju.hpp"
#include "Gabow.hpp"
#include "LectureGraphe.hpp"


int main(int argc, const char** argv) {
    
    
    // --------- GRAPHE DU COURS SANS UTILISER LA GENERATION PAR FICHIERS .DOT ------ //

    
    // ***********************
    
    std::list<Sommet *>* Sommets = new std::list<Sommet*>();

    Sommet a(0), b(1), c(2), d(3), e(4), f(5), g(6), h(7);

    a.AddSuccesseur(&b);
    b.AddSuccesseur(&c);
    b.AddSuccesseur(&e);
    b.AddSuccesseur(&f);
    c.AddSuccesseur(&d);
    c.AddSuccesseur(&g);
    d.AddSuccesseur(&c);
    d.AddSuccesseur(&h);
    e.AddSuccesseur(&a);
    e.AddSuccesseur(&f);
    f.AddSuccesseur(&g);
    g.AddSuccesseur(&f);
    h.AddSuccesseur(&d);
    h.AddSuccesseur(&g);

    Sommets->push_back(&a);
    Sommets->push_back(&b);
    Sommets->push_back(&c);
    Sommets->push_back(&d);
    Sommets->push_back(&e);
    Sommets->push_back(&f);
    Sommets->push_back(&g);
    Sommets->push_back(&h);
    
    // ***********************
    
    
    // --------- GRAPHES EN UTILISANT LA GENERATION PAR FICHIERS .DOT ------ //
    
    
    // Pour lancer cette génération :
    // 1° : Commentez la partie entre "*" ci-dessus
    // 2° : Decommentez la partie entre "#" ci-dessous
    // 3° : Inserez le chemin absoulu vers le graphe que vous voulez afficher (ligne 67)


    // #########################
    
//     std::list<Sommet *>* Sommets;
//     Sommets = LectureGraphe::LireGraphe("/Users/amandinebenza/Desktop/SCC/SCC/res/dot/grapheCours.dot");
    
    // ########################
    
    
    // ----------------------------

    
    Utils::pushGraph(Sommets, Tarjan::G);
    Utils::pushGraph(Sommets, Kosaraju::G);
    Utils::pushGraph(Sommets, Gabow::G);
    
    std::cout << "\nTARJAN\n\n";
    Tarjan::tarjanA();
    Utils::imprimerGraphes(Tarjan::partition);
    Utils::resetListeSommets(Sommets);

    std::cout << "\nKOSARAJU\n\n";
    Kosaraju::kosarajuA();
    Utils::imprimerGraphes(Kosaraju::partition);
    Utils::resetListeSommets(Sommets);

    std::cout << "\nGABOW\n\n";
    Gabow::gabowA();
    Utils::imprimerGraphes(Gabow::partition);
    Utils::resetListeSommets(Sommets);

   // visual studio
    std::cin.get();
    
    return 0;
}

