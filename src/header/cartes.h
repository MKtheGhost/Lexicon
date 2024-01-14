#ifndef CARTES_H
#define CARTES_H

const unsigned int NB_CARTES = 51;

struct Carte {
    char lettre;
    unsigned int points;
    unsigned int qte;
};

/**
 * @brief initialiser un paquet de carte vierge
 * @param{in/out} cartes le tableau de cartes à initialiser
**/
void InitPaquet(Carte (&cartes)[NB_CARTES]);

/**
* @brief mélanger un jeu de carte
* @param{in/out} le paquet de carte à mélanger
**/
void MelangeCarte(Carte (&cartes)[NB_CARTES]);

/**
 * @brief supprimer une carte à la position iCarte dans un paquet quelconque
 * @param[in] nbCartes : le nombre de carte dans le paquet de carte
 * @param{in/out} cartes : la tableau de carte à modifier
 * @param[in] iCarte : la position de la carte à supprimer
*/
void SupprimerCarte(unsigned int &nbCarte, Carte *&cartes, unsigned int iCarte);

/**
 * @brief ajouter une carte à la position iCarte dans un paquet quelconque
 * @param[in] nbCartes : le nombre de carte dans le paquet de carte pre-changement
 * @param{in/out} cartes : le tableau de carte à modifier
 * @param[in] nouveauCarte : la carte à ajouter
 * @param[in] iCarte : la position de la nouvelle carte
*/
void AjouterCarte(unsigned int &nbCarte, Carte *&cartes, Carte nouvelleCarte, unsigned int iCarte);


#endif