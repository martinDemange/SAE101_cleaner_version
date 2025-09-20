/**
* @file initialisation.h
* @author Santos Jorge Francisco
* @brief Contient la signature des fonctions utiliser pour initialiser le jeu.
**/
#ifndef INITIALISATION_H
#define INITIALISATION_H

#include "types.h"

/**
 * @brief Procédure permettant l'initialisation de la matrice selon le document mit en paramètres.
 * @param[in out] Mat : Matrice représentant la carte du jeu.
 * @param[in] nbLine : Nombre de lignes de la matrice Mat.
 * @param[in] nbColumn : Nombre de colonnes de la amtrice Mat.
 * @param[in out] posP : Position du Policier alias Jouini.
 * @param[in out] posV : Position du Voleur alias Casali.
 * @param[in] fileName : Nom du fichier contenant la Map.
 */
void initMat (CMatrix & Mat, const unsigned nbLine, const unsigned nbColumn, CPosition & posP, CPosition & posV, const std::string& fileName);

#endif // INITIALISATION_H
