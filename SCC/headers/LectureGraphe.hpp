//
//  LectureGraphe.hpp
//  SCC
//
//  Created by Amandine Benza on 30/05/2018.
//  Copyright © 2018 Amandine Benza. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <iostream>
#include "Utils.hpp"
#include "Sommet.hpp"
#include <fstream>

namespace LectureGraphe {
    
    extern std::list<Sommet*>* LireGraphe(const char *nom);
}
