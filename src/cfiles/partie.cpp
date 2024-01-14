#include <iostream>
using namespace std;

#include "../header/cartes.h"
#include "../header/joueur.h"
#include "../header/commande.h"
#include "../header/partie.h"
#include "../header/mots.h"

void prendreCommande(unsigned int idJoueur, char commande, JoueursActifs &joueurs, Talon &talon, MotsPose &motsPoses){

    bool validCommand = false;

    while (!validCommand) {
        if (commande == 'T') {
            CommandeTalon(idJoueur, joueurs, talon);
            validCommand = true;

        } else if (commande == 'E') {
            CommandeExposee(idJoueur, joueurs, talon);
            validCommand = true;

        } else if (commande == 'P') {
            CommandePosee(idJoueur, motsPoses, joueurs);
            validCommand = true;

        } else if (commande == 'R') {
            cout << "remplacer" << endl;
            validCommand = true;

        } else if (commande == 'C') {
            cout << "completer" << endl;
            validCommand = true;

        } else {
            cout << "Coup invalide. Recommencez" << endl;
            cin >> commande; 
        }
    }
}

void InitTour(JoueursActifs &joueurs, Carte (&cartes)[NB_CARTES], Talon&talon){

    //initialiser le tableau de mots posees
    MotsPose motsPose;
    motsPose.nbMots = 0;
    motsPose.mots = new char*[motsPose.nbMots];

    //distribuer les cartes à chacun des joueurs au debut de chaque tour
    InitCartes(joueurs, cartes, talon);

    bool aGagne = false;
    unsigned int cmpt = 0;
    //tant que aucun joueur n'a plus de carte
    while (!aGagne){

        //pour déterminer quel joueur doit jouer
        unsigned int idJoueur = cmpt % joueurs.nbJoueur;
        cmpt++;

        //premiere ligne d'affichage : numero de joueur, carte exposee, cartes du joueur
        cout << "* Joueur " << joueurs.listeJoueurs[idJoueur].numero << " (" << talon.carteExposee[0].lettre << ") ";
        for (unsigned i = 0; i < joueurs.listeJoueurs[idJoueur].nbCartes; i++){
            cout << joueurs.listeJoueurs[idJoueur].cartes[i].lettre;
        }
        cout << endl;

        //supprimer le joueur de la liste de joueurs actifs s'il a perdu
        if (joueurs.listeJoueurs[idJoueur].points >= 100){
            cout << "perdu! vous aves depassee 100 points" << endl;
            joueurs.listeJoueurs[idJoueur].statut = 0;
            supprimerJoueur(joueurs);
            cout << endl;
            cmpt++;
        }

        else if (joueurs.nbJoueur <= 1){
            aGagne = true;
            cout << endl;
        }

        else{
            //deuxieme ligne d'affichage : les mots posees
            if (motsPose.nbMots > 0){
                for (unsigned int i = 0; i < motsPose.nbMots; i++){
                    cout << i + 1 << " - " << motsPose.mots[i] << endl;
                }
            }

            cout << "> ";

            //prendre la commande du joueur, afficher sa saisie et exécuter la commande
            char commande;
            cin >> commande;
            prendreCommande(idJoueur, commande, joueurs, talon, motsPose);

            //pour la lisibilité de l'affichage
            cout << endl;

            //terminer le tour si un joueur a pose toutes ses cartes
            if (joueurs.listeJoueurs[idJoueur].nbCartes <= 0){
                aGagne = true;
            }

            if (joueurs.nbJoueur <= 1){
                aGagne = true;
            }
        }
        
    }

    //supprimer les mots poses apres avoir fini un tour
    for (unsigned int i = 0; i < motsPose.nbMots; i++){
        delete [] motsPose.mots[i];
        motsPose.mots[i] = NULL;
    }
    delete [] motsPose.mots;
    motsPose.mots = NULL;

    //affichage de fin de tour
    cout << "Le tour est fini" << endl;
    cout << "*Score" << endl;
    for (unsigned int i = 0; i < joueurs.nbJoueur; i++){
        cout << "Joueur " << joueurs.listeJoueurs[i].numero << " : " << joueurs.listeJoueurs[i].points << endl;
    }
    cout << endl;
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
    talon.carteExposee[0] = cartes[0];
    talon.nbCartesExposees = 1;
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
            joueurs.listeJoueurs[i].points += talon.cartes[k].points;
        }

        for (unsigned int k = 0; k < NB_CARTES_PAR_PERSONNE; k++){
            //supprimer les 10 premiers cartes du talon après les avoir distribués au joueur
            SupprimerCarte(talon.nbCartes, talon.cartes, 0);
        }

        joueurs.listeJoueurs[i].nbCartes--;
    }
}