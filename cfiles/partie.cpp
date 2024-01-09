#include <iostream>
#include "cartes.h"
using namespace std;

void prendreCommande(char commande){
    
        if (commande == 'T'){
            talon();
        }

        if (commande == 'E'){
            exposee();
        }

        if (commande == 'P'){
            posee();
        }

        if (commande == 'R'){
            remplacer();
        }

        if (commande == 'C'){
            Completer();
        }
}

void finDeTour(){
    cout << "Le tour est fini" << endl;
    cout << "*Score" << endl;
    for ( unsigned int i = 0; i <= nbjoueur; ++i){
        cout << "joueur " << i + 1 << " : " << joueurs[i].points << "points" << endl;
    } 
};

void InitTour(unsigned int nbJoueur){

    //distribuer les cartes à chacun des joueurs au debut de chaque tour
    attributionCarte();
    cout << "Commandes valides : TEPRC" << endl;

    unsigned int cmpt = 0;
    unsigned int nbCarte = 10;

    while ( nbCarte != 0){ // tant que aucun des joueurs n'a posé toutes ses cartes

        Joueur joueur = cmpt % nbJoueur + 1;
        cmpt++;
        char commande;

        cout << "joueur " << joueur.numero << " (" << carteExpose << ") " << joueur.carte << endl;

        //prendre et exécuter la commande saisi par le joueur
        cin >> commande;
        prendreCommande(commande);

        //vérifier le nombre de point du joueur
        if (joueur.points >= 100){
            eliminer(joueur);
        }

        //vérifier le nombre de carte du joueur
        if (joueur.cartes == 0){
            nbCarte = 0;
        }
    }

    finDeTour();
}

bool estgagne(unsigned int nbJoueur){
    if (nbJoueur <= 1){
        return true;
    }
}

void initPartie(unsigned int NbJoueur){

    //initialiser les joueurs selon leur nombre
    Joueur joueurs[4];
    initJoueur(NbJoueur);

    //initialiser un jeu de carte
    Carte Cartes;
    initcarte(Cartes);
    MelangeCarte();

    //Initialiser le talon
    Talon talon;
    initTalon(talon);
}