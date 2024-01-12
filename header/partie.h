#ifndef PARTIE_H
#define PARTIE_H

#include "cartes.h"
#include "joueur.h"

const unsigned int NB_CARTES_PAR_PERSONNE = 10;

struct Talon{
    Carte *cartes;
    Carte carteExposee;
    unsigned int nbCartes;
};

/**
 * @brief distribuer les cartes parmi les joueurs
 * @param{in/out} talon : cartes à distribuer à partir du talon
 * @param{in/out} joueurs : les joueurs actifs jouant dans cette partie
*/
void DistributionCarte(Talon &talon, JoueursActifs& joueurs);

/**
* @brief initialiser un jeu de carte ( mélange, distribution, talon, carte exposee)
* @param{in/out} joueurs : les joueurs actifs dans la partie en cours
* @param{in/out} cartes le paquet de cartes à traiter
* @param{in/out} talon le talon de carte à initialiser
**/
void InitCartes( JoueursActifs &joueurs,Carte (&cartes)[NB_CARTES], Talon &talon);

/**
 *  @brief initialiser un talon de cartes au début du jeu ainsi que la carte exposée
 *  @param{in/out} talon : le talon de cartes à initialiser
 *  @param[in] cartes : les cartes dans le paquet mélangées à mettre dans le talon
*/
void InitTalon(Talon &talon, Carte (&cartes)[NB_CARTES]);

#endif