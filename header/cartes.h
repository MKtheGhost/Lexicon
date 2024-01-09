const unsigned int NB_CARTES = 51;
const unsigned int NB_CARTES_PAR_PERSONNE = 10;

struct Carte {
    char lettre;
    unsigned int points;
    unsigned int qte;
};

struct Talon{
    Carte *cartes;
    Carte carteExposee;
    unsigned int nbCartes;
};

/**
* @brief initialiser un jeu de carte ( mélange, distribution, talon, carte exposee)
* @param{in/out} joueurs : les joueurs actifs dans la partie en cours
* @param{in/out} cartes le paquet de cartes à traiter
* @param{in/out} talon le talon de carte à initialiser
**/
void InitCartes( JoueursActifs &joueurs,Carte (&cartes)[NB_CARTES], Talon &talon);

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
 *  @brief initialiser un talon de cartes au début du jeu ainsi que la carte exposée
 *  @param{in/out} talon : le talon de cartes à initialiser
 *  @param[in] cartes : les cartes dans le paquet mélangées à mettre dans le talon
*/
void InitTalon(Talon &talon, Carte (&cartes)[NB_CARTES]);

/**
 * @brief supprimer une carte à la position iCarte dans un paquet quelconque
 * @param[in] nbCartes : le nombre de carte dans le paquet de carte
 * @param{in/out} cartes : la tableau de carte à modifier
 * @param[in] iCarte : la position de la carte à supprimer
*/
void SupprimerCarte(unsigned int nbCartes, Carte *cartes, unsigned int iCarte);

/**
 * @brief distribuer les cartes parmi les joueurs
 * @param{in/out} talon : le talon de carte à distribuer
 * @param{in/out} joueurs : les joueurs actifs jouant dans cette partie
*/
void DistributionCarte(Talon &talon, JoueursActifs &joueurs);