/**
* @file mouvementPerso.h
* @author Santos Jorge Francisco
* @brief Contient la signature des fonctions utiliser pour bouger les joueurs.
**/
#ifndef MOUVEMENTPERSO_H
#define MOUVEMENTPERSO_H

#include "config.h"
#include "types.h"
/**
 * @brief Procédure permettant de déplacé le Voleur alias Casali.
 * @param[in out] Mat : Matrice representant la map du jeu.
 * @param[in] move : Touche préssé du joueur.
 * @param[in out] pos : Position du Voleur alias Casali qui sera mis à jour à la fin de la procédure.
 * @param[in out] tabVole : Valeur représentant les tableaux volés alias les cigarettes.
 */
void moveTokenV (CMatrix & Mat,const char& move, CPosition& pos, unsigned& tabVole, const config& param);

/**
 * @brief Procédure permettant de déplacé le Policier alias Casali.
 * @param[in out] Mat : Matrice representant la map du jeu.
 * @param[in] move : Touche préssé du joueur.
 * @param[in out] pos : Position du Policier alias Jouini qui sera mis à jour à la fin de la procédure.
 */
void moveTokenP (CMatrix & Mat,const char& move, CPosition& pos, const config& param);
#endif // MOUVEMENTPERSO_H
