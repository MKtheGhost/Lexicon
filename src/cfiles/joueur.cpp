#include <iostream>
using namespace std;

#include "../header/joueur.h"
#include "../header/cartes.h"

void InitJoueur(unsigned int nbJoueur,Joueur (&joueurs)[NB_JOUEURS_MAX], JoueursActifs& joueursActifs){

    joueursActifs.listeJoueurs = new Joueur[NB_JOUEURS_MAX];

    //affecter chaque joueur à une case mémoire
    for (unsigned int i = 0; i < nbJoueur; ++i){
        joueurs[i].numero = i + 1;
        joueurs[i].points = 0;
        joueurs[i].statut = 1;

        joueursActifs.listeJoueurs[i] = joueurs[i];
    }

    joueursActifs.nbJoueur = nbJoueur;
};

void supprimerJoueur (JoueursActifs& joueursActifs){
    //liberer l'espace du tableau des joueurs actifs
    Joueur *tempJoueur = new Joueur[joueursActifs.nbJoueur - 1];

    unsigned int compteur = 0;

    for ( unsigned int i = 0; i < joueursActifs.nbJoueur; i++){
        if ( joueursActifs.listeJoueurs[i].statut == 1 ){
            tempJoueur[compteur] = joueursActifs.listeJoueurs[i];
            compteur ++;
        }
    }

    delete [] joueursActifs.listeJoueurs;
    joueursActifs.listeJoueurs = tempJoueur;

    joueursActifs.nbJoueur --;
}