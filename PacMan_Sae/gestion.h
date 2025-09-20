/**
* @file gestion.h
* @author Santos Jorge Francisco
* @brief Contient la signature des fonctions pour gérer le jeu.
**/
#ifndef GESTION_H
#define GESTION_H

#include "types.h"

/**
 * @brief Procédure pour remettre les parametres input de termios par defaut.
 */
void reset_input_mode (void);

/**
 * @brief Procédure pour mettre l'input termios en marche.
 */
void set_input_mode (void);

/**
* @fn clearScreen ();
* @brief Une fonction pour netoyer l'affichache sur le terminal.
**/
void clearScreen ();

/**
* @brief Cette fonction à pour but de donner une couleur au texte sur le terminal.
* @fn couleur (const unsigned & coul);
* @param coul L'identifiant de la couleur de type unsigned.
*/
void couleur (const unsigned & coul);

/**
* @brief Cette fonction à pour but de donner une couleur au fond du terminal. // placeholder
* @fn couleurF (const unsigned & coul);
* @param coul L'identifiant de la couleur de type unsigned.
* @callgraph
* @callergraph
*/
void couleurF (const unsigned & coul);

#endif // GESTION_H
