#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

#include "../header/cartes.h"
#include "../header/joueur.h"
#include "../header/partie.h"
#include "../header/mots.h"

void CommandeTalon(unsigned int idJoueur, JoueursActifs& joueurs, Talon& talon){

    char carteAbandonnee;
    cin >> carteAbandonnee;

    //vérifier si la carte posee est present parmi les cartes du joueur
    bool estPresent = false;
    unsigned int idCarte;
    for (unsigned int i = 0; i < joueurs.listeJoueurs[idJoueur].nbCartes; i++){
        if (joueurs.listeJoueurs[idJoueur].cartes[i].lettre == carteAbandonnee){
            estPresent = true;
            idCarte = i;
            
        }
    }

    //poser la carte sur la pile des cartes exposées, sinon signaler l'erreur et demande à l'utilisateur de saisir une autre carte
    if (estPresent){
        //ajouter la carte saisie à la pile de cartes exposees
        AjouterCarte(talon.nbCartesExposees, talon.carteExposee, joueurs.listeJoueurs[idJoueur].cartes[idCarte], 0);
        //supprimer la carte posee de la main du joueur
        joueurs.listeJoueurs[idJoueur].points -= joueurs.listeJoueurs[idJoueur].cartes[idCarte].points;
        SupprimerCarte(joueurs.listeJoueurs[idJoueur].nbCartes, joueurs.listeJoueurs[idJoueur].cartes, idCarte);

        //ajouter une carte du talon à la main du joueur
        AjouterCarte(joueurs.listeJoueurs[idJoueur].nbCartes, joueurs.listeJoueurs[idJoueur].cartes, talon.cartes[0], 0);
        joueurs.listeJoueurs[idJoueur].points += talon.cartes[0].points;
        //supprimer la carte prise du talon
        SupprimerCarte(talon.nbCartes, talon.cartes, 0);

    }
    else{
        cout << "Coup invalide. Recommencez" << endl;
        cout << "> T ";
        CommandeTalon(idJoueur, joueurs, talon);
    }
}

void CommandeExposee(unsigned int idJoueur, JoueursActifs& joueurs, Talon& talon){

    char carteAbandonnee;
    cin >> carteAbandonnee;

    //vérifier si la carte posee est present parmi les cartes du joueur
    bool estPresent = false;
    unsigned int idCarte;
    for (unsigned int i = 0; i < joueurs.listeJoueurs[idJoueur].nbCartes; i++){
        if (joueurs.listeJoueurs[idJoueur].cartes[i].lettre == carteAbandonnee){
            estPresent = true;
            idCarte = i; 
        }
    }

    //poser la carte sur la pile des cartes exposées, sinon signaler l'erreur et demande à l'utilisateur de saisir une autre carte
    if (estPresent){
        //ajouter la carte dans la main du joueur au talon
        AjouterCarte(talon.nbCartesExposees, talon.carteExposee, joueurs.listeJoueurs[idJoueur].cartes[idCarte], 0);
        //suprimer la carte posee de la main du joueur
        joueurs.listeJoueurs[idJoueur].points -= joueurs.listeJoueurs[idJoueur].cartes[idCarte].points;
        SupprimerCarte(joueurs.listeJoueurs[idJoueur].nbCartes, joueurs.listeJoueurs[idJoueur].cartes, idCarte);

        //ajouter la carte du talon dans la main du joueur
        AjouterCarte(joueurs.listeJoueurs[idJoueur].nbCartes, joueurs.listeJoueurs[idJoueur].cartes, talon.carteExposee[1], 0);
        joueurs.listeJoueurs[idJoueur].points += talon.carteExposee[1].points; 
        //suprimer la carte du talon
        SupprimerCarte(talon.nbCartesExposees, talon.carteExposee, 1);

    }
    else{
        cout << "Coup invalide. Recommencez" << endl;
        cout << "> E ";
        CommandeExposee(idJoueur, joueurs, talon);
    }
}

void CommandePosee(unsigned int idJoueur, MotsPose &motsPoses, JoueursActifs &joueurs) {
    //recuperer le mot saisie apres la commande
    char motSaisie[21]; 
    cin >> motSaisie;

    //ouvrir le dictionnaire de mots

    char motDico[21];
    ifstream dictionnaire("ods4.txt");

    bool estPresent = false;
    // vérifier si le mot posé par l'utilisateur est bien présent dans le dictionnaire
    while (dictionnaire >> motDico){
        if (strcmp(motSaisie, motDico) == 0){
            estPresent = true;
            break;
        }
    }

    if (estPresent == false){
        cout <<  "Mot invalide, vous passez votre tour" << endl;
        joueurs.listeJoueurs[idJoueur].points += 3;
    }

    else{
        bool possedeMot = true;
        //verifier si le joueur possede les cartes qui constituent le mot

        for (unsigned int k = 0; k < strlen(motSaisie); k++){
            bool possedeCarte = false;
            for (unsigned int i = 0; i < joueurs.listeJoueurs[idJoueur].nbCartes; i++){

                if (joueurs.listeJoueurs[idJoueur].cartes[i].lettre == motSaisie[k]){
                    possedeCarte = true;
                }
            }

            if (!possedeCarte){
                possedeMot = false;
            }
        }

        if (!possedeMot){
            joueurs.listeJoueurs[idJoueur].points += 3;
            cout << "Coup invalide. Recommencez" << endl;
            cout << "> P ";
            CommandePosee(idJoueur, motsPoses, joueurs);
        }

        else{
            char **tempMots = new char*[motsPoses.nbMots + 1];

            // Allocate memory for the new word
            tempMots[motsPoses.nbMots] = new char[strlen(motSaisie) + 1];
            strcpy(tempMots[motsPoses.nbMots], motSaisie);

            // Copy the existing words to the new array
            for (unsigned int i = 0; i < motsPoses.nbMots; i++) {
                tempMots[i] = motsPoses.mots[i];
            }

            // Deallocate the old array of pointers and assign the new one
            delete[] motsPoses.mots;
            motsPoses.mots = tempMots;


            motsPoses.nbMots ++;

            for (unsigned int k = 0; k < strlen(motSaisie); k++){
                for (unsigned int i = 0; i < joueurs.listeJoueurs[idJoueur].nbCartes; i++){
                    if (joueurs.listeJoueurs[idJoueur].cartes[i].lettre == motSaisie[k]){
                        joueurs.listeJoueurs[idJoueur].points -= joueurs.listeJoueurs[idJoueur].cartes[i].points;
                        SupprimerCarte(joueurs.listeJoueurs[idJoueur].nbCartes, joueurs.listeJoueurs[idJoueur].cartes, i);
                        break;
                    }
                }
            } 
        }
    }
}