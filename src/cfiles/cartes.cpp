#include <iostream>
#include <ctime>
using namespace std;

#include "../header/joueur.h"
#include "../header/cartes.h"

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

void SupprimerCarte(unsigned int &nbCarte, Carte *&cartes, unsigned int iCarte){

    //définir un paquet de carte plus petit
    Carte *tempCarte = new Carte[nbCarte - 1];

    //supression à la fin du paquet
    if (iCarte == nbCarte - 1){
        for (unsigned int i = 0; i < iCarte; i++){
            tempCarte[i] = cartes[i];
        }

        delete [] cartes;
        cartes = tempCarte;
    } 

    //supression au milieu du paquet
    else{
        for (unsigned int i = 0; i < iCarte; i++){
            tempCarte[i] = cartes[i];
        }

        for (unsigned int i = iCarte; i < nbCarte - 1; i++){
            tempCarte[i] = cartes[i + 1];
        }

        delete [] cartes;
        cartes = tempCarte;
    }

    nbCarte -- ;
}

void AjouterCarte(unsigned int &nbCarte, Carte *&cartes, Carte nouvelleCarte, unsigned int iCarte){

    //definir un paquet de carte plus grand
    Carte *tempCarte = new Carte[nbCarte + 1];

    //dans le cas où on veut ajouter une carte à la fin du paquet
    if (iCarte >= nbCarte){

        //mettre les cartes actuelles dans le nouveau paquet
        for (unsigned int i = 0; i < nbCarte; i++){
            tempCarte[i] = cartes[i];
        }

        //supprimer l'espace de stockage pour les cartes actuelles et changer le pointeur de cartes vers le nouveau paquet
        delete [] cartes;
        cartes = tempCarte;

        cartes[iCarte] = nouvelleCarte;
    }

    //le cas où on veut inserer une carte entre les cartes existantes
    else {

        for (unsigned int i = 0; i < iCarte; i++){
            tempCarte[i] = cartes[i];
        }

        tempCarte[iCarte] = nouvelleCarte;

        for (unsigned int i = iCarte + 1; i < nbCarte + 1; i++){
            tempCarte[i] = cartes[i - 1];
        }

        delete [] cartes;
        cartes = tempCarte;
    }

    nbCarte++;
}


