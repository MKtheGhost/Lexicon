#ifndef JOUEUR_H
#define JOUEUR_H

#include "cartes.h"

const unsigned int NB_JOUEURS_MAX = 4;

struct Joueur{
    int numero;
    Carte *cartes;
    unsigned int nbCartes;
    int points;
    unsigned int statut;
};

struct JoueursActifs{
    Joueur *listeJoueurs;
    unsigned int nbJoueur;
};

/**
* @brief initialiser les joueurs (numéro, points) selon leur effectif
* @param[in] nbJoueur le nombre de joueur saisie pendant l'appel de l'application
* @param[in] joueurs la liste des joueurs présents dans cette partie de jeu
* @param[in] joueursActifs la liste et le nombre des joueurs qui sont encore dans le jeu
**/
void InitJoueur(unsigned int nbJoueur, Joueur (&joueurs)[NB_JOUEURS_MAX], JoueursActifs& joueursActifs);

/**
 *  @brief supprimer un joueur de la liste des joueurs actifs lorsqu'il a perdu
 *  @param{in/out} joueursActifs : la liste des joueurs actifs à modifier
 *  @param[in] joueurs : la liste des joueurs original 
*/
void supprimerJoueur (JoueursActifs& joueursActifs);

#endif