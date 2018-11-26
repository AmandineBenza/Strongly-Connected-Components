//
//  LectureGraphe.cpp
//  SCC
//
//  Created by Amandine Benza on 30/05/2018.
//  Copyright © 2018 Amandine Benza. All rights reserved.
//

#include "LectureGraphe.hpp"

namespace LectureGraphe {
    char ligne[100]; // Pourquoi 100 ? Pourquoi pas 100.
    
    std::list<Sommet*>* LireGraphe(const char *nom) {
        std::ifstream fichier;
        int i, j;
        char c, k;
        std::list<Sommet*> *g = new std::list<Sommet *>;
        
        fichier.open(nom);
        
        for (int cpt = 0; cpt < 3; cpt++) {
            fichier.getline(ligne, 100);
        }
        
        do {
            fichier >> i; // Premier sommet de la ligne
            fichier >> c; // -
            if (c == '-') { // Si on est bien dans la liste sommets
                fichier >> k; // >
                fichier >> j; // Deuxieme sommet
                fichier.getline(ligne, 100); // \n
                Sommet *a = Utils::ajouterSiAbsent(g, i);
                Sommet *b = Utils::ajouterSiAbsent(g, j);
                a->AddSuccesseur(b);
            }
            else if(c == '/') { // Si pas de sucesseur
                Utils::ajouterSiAbsent(g, i);
                fichier.getline(ligne, 100); // \n

            }
        //    std::cout << i << ", " << j << "\n";
        } while (c == '-' || c == '/'); // Tant qu'on est dans la liste des sommets

        return g;
    }
    
    
}
