#include <fstream>
#include <iostream>

using namespace std;

#include "../header/cartes.h"
#include "../header/joueur.h"


void talon(unsigned int idJoueur, JoueursActifs& joueurs, Talon& talon){

    //ajouter la carte au sommet du talon à la main du joueur
    ajouterCarte(joueurs.listeJoueurs[idJoueur].cartes, talon.cartes[0]);
    joueurs.listeJoueurs[idJoueur].nbCartes++;
    joueurs.listeJoueurs[idJoueur].points += talon.cartes[0].points;

    //supprimer la carte prise du talon
    SupprimerCarte(talon.nbCartes, talon.cartes, 0);
    talon.nbCartes--;
};

void exposee(unsigned int idJoueur, JoueursActifs& joueurs, Talon& talon){

    //ajouter la carte exposee dans la main du joueur
    ajouterCarte(joueurs.listeJoueurs[idJoueur].cartes, talon.carteExposee);
    joueurs.listeJoueurs[idJoueur].nbCartes++;
    joueurs.listeJoueurs[idJoueur].points += talon.carteExposee.points;

    //supprimer la carte exposee prise et la remplacer par une autre carte du talon
    talon.carteExposee = talon.cartes[0];

    //supprimer la carte prise du talon
    SupprimerCarte(talon.nbCartes, talon.cartes, 0);
    talon.nbCartes--;
};

void posee(){
    char mot;
    cin >> mot;

    //vérifier si le mot posé par l'utilisateur est bien présent dans le dictionnaire
    ifstream dictionnaire("ods4.txt");
    char motDico;

    bool est_present = false;

    while( dictionnaire >> motDico ){
        if ( motDico == mot){
            est_present = true;
        }
    }

    if (est_present){
        //poser le mot sur la table
    }
};

void completer();

void remplacer();

