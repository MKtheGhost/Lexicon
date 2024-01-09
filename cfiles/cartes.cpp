#include <iostream>
#include <time.h>
using namespace std;

#include "../header/cartes.h"
#include "../header/joueur.h"

void InitCartes( JoueursActifs &joueurs,Carte (&cartes)[NB_CARTES], Talon &talon){
    MelangeCarte(cartes);
    InitTalon(talon, cartes);
    DistributionCarte(talon, joueurs);
}

void InitPaquet(Carte (&cartes)[NB_CARTES]){

    const unsigned int NB_ELEMENT_TAB_CARTE = 26;

    Carte tabCarte[NB_ELEMENT_TAB_CARTE] = {{'A', 10, 2}, {'B', 2, 2}, {'C', 8, 2}, {'D', 6, 2},
                          {'E', 10, 5}, {'F', 2, 1}, {'G', 4, 2}, {'H', 8, 2},
                          {'I', 10, 4}, {'J', 6, 1}, {'K', 8, 1}, {'L', 8, 2},
                          {'M', 8, 1}, {'N', 8, 3}, {'O', 8, 2}, {'P', 8, 1},
                          {'Q', 4, 1}, {'R', 8, 3}, {'S', 8, 3}, {'T', 8, 3},
                          {'U', 8, 3}, {'V', 8, 1}, {'W', 8, 1}, {'X', 2, 1},
                          {'Y', 4, 1}, {'Z', 2, 1}};

    unsigned int compteur = 0;

    for ( unsigned int i = 0; i < NB_ELEMENT_TAB_CARTE; i++){
        for ( unsigned int k = 0; k < tabCarte[i].qte; k++ ){
            cartes[compteur] = tabCarte[i];
            compteur++;
        }
    }
}

void MelangeCarte(Carte (&cartes)[NB_CARTES]){

    srand(time(NULL));

    for ( unsigned int i = 0; i < NB_CARTES; i++ ){
        unsigned int randomIndex = rand() % (NB_CARTES);
        Carte temp = cartes[i];
        cartes[i] = cartes[randomIndex];
        cartes[randomIndex] = temp;
    }
}

void InitTalon(Talon &talon, Carte (&cartes)[NB_CARTES]){
    talon.cartes = new Carte[NB_CARTES - 1];

    for ( unsigned int i = 0; i < NB_CARTES - 1; i++ ){
        talon.cartes[i] = cartes[i + 1];
    }

    talon.nbCartes = 50;
    talon.carteExposee = cartes[0];
}

void SupprimerCarte(unsigned int nbCartes, Carte *cartes, unsigned int iCarte){

    Carte *tempCarte = new Carte;
    *tempCarte = *cartes;
    delete [] cartes;

    for (unsigned int i; i < nbCartes; i++){
        if (i != iCarte){
            cartes[i] = tempCarte[i];
        }
    }
    delete [] tempCarte;
    tempCarte = NULL;
}

void DistributionCarte(Talon &talon, JoueursActifs &joueurs){
   for ( unsigned int i = 0; i < joueurs.nbJoueur; i++){
        for ( unsigned int k = 0; k < 10; k++){
            joueurs.listeJoueurs[i].cartes[k] = talon.cartes[k];
        }

        for ( unsigned int k = 0; k < 10; k++){
            SupprimerCarte(talon.nbCartes, talon.cartes, k);
        }
        joueurs.listeJoueurs[i].nbCartes = 10;
    }
}
/*void DistributionCarte(unsigned int NB_CARTES_PAR_PERSONNE, Carte (&cartes)[NB_CARTES], JoueursActifs &joueursActifs){

    for ( unsigned int i = 0; i < joueursActifs.nbJoueur; i++){

        for ( unsigned int k; k < NB_CARTES_PAR_PERSONNE; i++){
            joueursActifs.listeJoueurs[i].cartes[k] = cartes[0];
            supprimerCarte(carte[0]);
        }

    }
}*/






/*void MelangeCarte(Carte& cartes[]){
    ...
}

void attributionCarte(Joueur joueurs, Carte cartes);

void supprimeCarte();

void ajouterCarte();

void initTalon();*/

