#ifndef COMMANDE_H
#define COMMANDE_H

#include "joueur.h"
#include "partie.h"
#include "cartes.h"
#include "mots.h"

/*! \brief Transfère la carte au sommet du talon à la main du joueur
 * \param[in] idJoueur Identifiant du joueur
 * \param[in,out] joueurs Tableau dynamique de joueurs actifs
 * \param[in,out] talon Talon actuel
 */
void CommandeTalon(unsigned int idJoueur, JoueursActifs& joueurs, Talon& talon);

/*! \brief Transfère la carte exposee à la main du joueur
 * \param[in] idJoueur Identifiant du joueur
 * \param[in,out] joueurs Tableau dynamique de joueurs actifs
 * \param[in,out] talon Talon actuel
 */

void CommandeExposee(unsigned int idJoueur, JoueursActifs& joueurs, Talon& talon);

/*! \brief Fonction pour poser un mot sur la table
 \param[in] idJoueur : l'indice du joueur qui appelle la commande
 \param[in,out] motsPoses : la liste des mots poses sur la table
 \param[in,out] jouueurs : la liste des joueurs qui sont encore dans le jeu
*/

void CommandePosee(unsigned int idJoueur, MotsPose &motsPoses, JoueursActifs &joueurs);

#endif