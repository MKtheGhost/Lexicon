#include <iostream>
using namespace std;

#include "src/header/commande.h"
#include "src/header/partie.h"
#include "src/header/joueur.h"
#include "src/header/cartes.h"


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
    
    //boucle de jeu
    bool estGagne = false;

    cout << "(commandes valides : TEP)" << endl;

    //tant que le jeu n'est pas gagné
    while (!estGagne){

        //recommencer un tour de jeu
        InitTour(joueursActifs, cartes, talon);

        if (joueursActifs.nbJoueur <= 1){
            estGagne = true;
        }
    }

    cout << endl;
    cout << "La partie est finie" << endl;

    //desallouer tous les tableaux dynamiques
    delete [] joueursActifs.listeJoueurs;
    joueursActifs.listeJoueurs = NULL;

    delete [] talon.cartes;
    talon.cartes = NULL;


}

void testJoueur(unsigned int nbJoueur, Joueur joueurs[NB_JOUEURS_MAX], JoueursActifs joueursActifs){
     for (unsigned int i = 0; i < nbJoueur; ++i){
        cout << "joueur " << joueurs[i].numero << " points : " << joueurs[i].points << endl;
    }

    for (unsigned int i = 0; i < nbJoueur; ++i){
        cout << "numero : " << joueursActifs.listeJoueurs[i].numero << endl;
    }

     supprimerJoueur(joueursActifs);
}

void testCarte(Carte cartes[NB_CARTES]){
    for ( unsigned int i = 0; i < NB_CARTES; i++){
        cout << cartes[i].lettre << endl;
    }
}

void testTalon(Talon talon, Carte cartes[NB_CARTES]){
    //InitTalon(talon, cartes);

    //cout << talon.carteExposee.lettre << endl;

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

void testInitCarte(unsigned int nbJoueur, JoueursActifs joueursActifs, Talon talon, Carte (&cartes)[NB_CARTES]){
    InitCartes(joueursActifs, cartes, talon);
    cout << "test joueur" << endl;
    for (unsigned int i = 0; i < nbJoueur; ++i){
        cout << "numero : " << joueursActifs.listeJoueurs[i].numero << endl;
        for ( unsigned int k = 0; k < 10; k++){
            cout << joueursActifs.listeJoueurs[i].cartes[k].lettre << " ";
        }
        cout << endl;
        cout << "nb Carte : " << joueursActifs.listeJoueurs[i].nbCartes << endl;
    }

    cout << "test talon" << endl;
    for (unsigned int i = 0; i < talon.nbCartes; ++i){
        cout << talon.cartes[i].lettre << " ";
    }
    cout << endl;

     cout << talon.nbCartes << endl;
}