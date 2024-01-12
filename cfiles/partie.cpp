#include <iostream>
using namespace std;

#include "../header/cartes.h"
#include "../header/joueur.h"
#include "../header/commande.h"
#include "../header/partie.h"
#include "../header/mots.h"

void prendreCommande(char commande){
    
        if (commande == 'T'){
            cout << "talon" << endl;
        }

        if (commande == 'E'){
            cout << "exposee" << endl;
        }

        if (commande == 'P'){
            cout << "poser" << endl;
        }

        if (commande == 'R'){
            cout << "remplacer" << endl;
        }

        if (commande == 'C'){
            cout << "completer" << endl;
        }
}

void InitTour(JoueursActifs &joueurs, Carte (&cartes)[NB_CARTES], Talon&talon){

    //initialiser le tableau de mots posees
    MotsPosee motsPosee;
    motsPosee.nbMots = 0;
    motsPosee.mots = new Mot[motsPosee.nbMots];

    //distribuer les cartes à chacun des joueurs au debut de chaque tour
    InitCartes(joueurs, cartes, talon);

    bool aGagne = false;
    //tant que aucun joueur n'a plus de carte
    while (!aGagne){

        //pour déterminer quel joueur doit jouer
        unsigned int cmpt = 0;
        unsigned int numeroJoueur = cmpt % joueurs.nbJoueur + 1;
        cmpt++;

        //premiere ligne d'affichage : numero de joueur, carte exposee, cartes du joueur
        cout << "Joueur " << numeroJoueur << " (" << talon.carteExposee.lettre << ") ";
        for (unsigned i = 0; i < joueurs.listeJoueurs[numeroJoueur].nbCartes; i++){
            cout << joueurs.listeJoueurs[numeroJoueur].cartes[i].lettre;
        }
        cout << endl;

        //prendre la commande du joueur, afficher sa saisie exécuter la commande
        char commande;
        prendreCommande(commande);

        //troisieme ligne d'affichage : les mots posees
        if ( motsPosee.nbMots > 0){
            for (unsigned int i = 0; i < ; i++){
                cout << i + 1 << " - ";
                for (unsigned int k = 0; k < mots[i].nbLettre; k++){
                    cout << mots[i][k] <<;
                }
                cout << endl;
            }
        }
        
    }



    /*while ( nbCarte != 0){ // tant que aucun des joueurs n'a posé toutes ses cartes

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

    finDeTour();*/
}


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