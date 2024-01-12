#include <iostream>
using namespace std;

#include "../header/cartes.h"
#include "../header/joueur.h"
#include "../header/commande.h"
#include "../header/partie.h"

/* void prendreCommande(char commande){
    
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
}*/ 



void InitCartes( JoueursActifs &joueurs,Carte (&cartes)[NB_CARTES], Talon &talon){
    MelangeCarte(cartes);
    InitTalon(talon, cartes);
    DistributionCarte(talon, joueurs);
}

void InitTalon(Talon &talon, Carte (&cartes)[NB_CARTES]){
    talon.cartes = new Carte[NB_CARTES - 1];

    for ( unsigned int i = 0; i < NB_CARTES - 1; i++ ){
        talon.cartes[i] = cartes[i + 1];
    }

    talon.nbCartes = 50;
    talon.carteExposee = cartes[0];
}

void DistributionCarte(Talon &talon, JoueursActifs& joueurs){
    //pour chaque joueur
    for (unsigned int i = 0; i < joueurs.nbJoueur; i++){

        //initialiser son paquet de carte dynamique
        joueurs.listeJoueurs[i].cartes = new Carte[NB_CARTES_PAR_PERSONNE];

        for (unsigned int k = 0; k < NB_CARTES_PAR_PERSONNE; k++){

            // initialiser le nombre de carte par personne pour pouvoir utilser AjouterCarte
            joueurs.listeJoueurs[i].nbCartes = NB_CARTES_PAR_PERSONNE;

            //copier les 10 premiers cartes du talon dans la main du joueur
            AjouterCarte(joueurs.listeJoueurs[i].nbCartes, joueurs.listeJoueurs[i].cartes, talon.cartes[k], k);
        }
        for (unsigned int k = 0; k < NB_CARTES_PAR_PERSONNE; k++){
            //supprimer les 10 premiers cartes du talon après les avoir distribués au joueur
            SupprimerCarte(talon.nbCartes, talon.cartes, 0);
        }

        joueurs.listeJoueurs[i].nbCartes--;
    }
}