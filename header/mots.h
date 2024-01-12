#ifndef MOTS_H
#define MOTS_H

#include "cartes.h"

struct Mot {
    Carte *mot;
    unsigned int nbLettre;
};

struct MotsPosee {
    Mot *mots;
    unsigned int nbMots;
};

#endif