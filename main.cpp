#include <iostream>
using namespace std;

#include "header/commande.h"
#include "header/partie.h"
#include "header/joueur.h"
#include "header/cartes.h"


int main(int argc, char *argv[]){

    //recuperer le nombre de joueur saisie en argument
    unsigned int nbJoueur = *argv[1] - '0';

    //initialiser les données des joueurs
    Joueur joueurs[NB_JOUEURS_MAX];
    JoueursActifs joueursActifs;
    InitJoueur(nbJoueur, joueurs, joueursActifs);

    //initialiser le paquet de carte
    Carte cartes[NB_CARTES];
    Talon talon;
    InitPaquet(cartes);
    InitTalon(talon, cartes);

    Carte *test = new Carte[4];
    test[0] = talon.cartes[0];
    test[1] = talon.cartes[1];
    test[2] = talon.cartes[2];
    test[3] = talon.cartes[3];

    unsigned int nbCartes = 4;

    for ( unsigned int i = 0; i < nbCartes; i++){
        cout << test[i].lettre << endl;
    }

    SupprimerCarte(nbCartes, test, 2 );

    cout << "test dans main" << endl;
    for ( unsigned int i = 0; i < nbCartes; i++){
        cout << test[i].lettre << endl;
    }


    //cout << talon.cartes[3].lettre << endl;
    //cout << test[3].lettre << endl;

    /*for (unsigned int i = 0; i < 4; i++){
        cout << talon.cartes[i].lettre << endl;
        cout << "carte : " << test[i].lettre << " points : " << test[i].points << endl;
    }*/






    //boucle de jeu
    /*bool estGagne = false;
    while (!estGagne){
        InitCartes(cartes, talon);

    }








    //InitJoueur(nbJoueur);
    /*while (!estgagne()) {
        unsigned int nbJoueur = declareNbJoueur();

        //tant que la partie n'est pas gagné par un joueur, un tour recommence
        InitPartie(nbJoueur);
    }

    //quand une partie est gagné
    cout << "La partie est finie" << endl;*/
}

void testJoueur(unsigned int nbJoueur, Joueur joueurs[NB_JOUEURS_MAX], JoueursActifs joueursActifs){
     for (unsigned int i = 0; i < nbJoueur; ++i){
        cout << "joueur " << joueurs[i].numero << " points : " << joueurs[i].points << endl;
    }

    for (unsigned int i = 0; i < nbJoueur; ++i){
        cout << "numero : " << joueursActifs.listeJoueurs[i].numero << endl;
    }

     supprimerJoueur(joueursActifs, joueurs);
}

void testCarte(Carte cartes[NB_CARTES]){
    for ( unsigned int i = 0; i < NB_CARTES; i++){
        cout << cartes[i].lettre << endl;
    }
}

void testTalon(Talon talon, Carte cartes[NB_CARTES]){
    //InitTalon(talon, cartes);

    cout << talon.carteExposee.lettre << endl;

    cout << talon.cartes[0].lettre << endl;
    cout << talon.cartes[30].lettre << endl;
    cout << talon.cartes[49].lettre << endl;
}

void testAjouterCarte(Talon talon, unsigned int nbCartes){
    Carte *test = new Carte[4];
    test[0] = talon.cartes[0];
    test[1] = talon.cartes[1];
    test[2] = talon.cartes[2];
    test[3] = talon.cartes[3];

    AjouterCarte(nbCartes, test, talon.cartes[13], 4 );

    cout << "test dans main" << endl;
    for ( unsigned int i = 0; i < nbCartes; i++){
        cout << test[i].lettre << endl;
    }
}