#include <iostream>
using namespace std;

#include "../header/joueur.h"
#include "../header/cartes.h"

void InitJoueur(unsigned int nbJoueur,Joueur (&joueurs)[NB_JOUEURS_MAX], JoueursActifs& joueursActifs){

    initJoueursActifs(joueursActifs, nbJoueur);

    //affecter chaque joueur à une case mémoire
    for (unsigned int i = 0; i < nbJoueur; ++i){
        joueurs[i].numero = i + 1;
        joueurs[i].points = 0;
        joueurs[i].statut = 1;

        joueursActifs.listeJoueurs[i] = joueurs[i];
    }

    joueursActifs.nbJoueur = nbJoueur;
};

void initJoueursActifs(JoueursActifs& joueursActifs, unsigned int nbJoueur){
    joueursActifs.listeJoueurs = new Joueur[nbJoueur];
}

void supprimerJoueur (JoueursActifs& joueursActifs, Joueur joueurs[NB_JOUEURS_MAX]){
    //liberer l'espace du tableau des joueurs actifs
    delete [] joueursActifs.listeJoueurs;

    //créer un nouveau emplacement pour les joueurs actifs
    initJoueursActifs(joueursActifs, joueursActifs.nbJoueur - 1);

    unsigned int compteur = 0;

    for ( unsigned int i = 0; i < joueursActifs.nbJoueur; i++){
        if ( joueurs[i].statut == 1 ){
            joueursActifs.listeJoueurs[compteur] = joueurs[i];
            compteur ++;
        }
    }

    joueursActifs.nbJoueur --;
}