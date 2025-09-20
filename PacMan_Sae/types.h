/**
* @file types.h
* @author Santos Jorge Francisco
* @brief Contient les différents types personnalisés utilisables pour le code.
**/
#ifndef TYPES_H
#define TYPES_H

#include <vector>

/**
* Un type représentant une ligne de la grille
*/
typedef std::vector <char> CVLine;

/**
* un type représentant la grille
*/
typedef std::vector <CVLine> CMatrix;

/**
* un type représentant une coordonnée dans la grille
*/
typedef std::pair <unsigned, unsigned> CPosition;

// id des couleurs du terminal

/**
* Variable representant la couleur par defaut du terminal
**/
const unsigned KReset =0;

/**
* Variable representant la couleur noir dans le terminal
**/
const unsigned KNoir = 30;

/**
* Variable representant la couleur rouge dans le terminal
**/
const unsigned KRouge = 31;

/**
* Variable representant la couleur vert dans le terminal
**/
const unsigned KVert = 32;

/**
* Variable representant la couleur jaune dans le terminal
**/
const unsigned KJaune = 33;

/**
* Variable representant la couleur bleu dans le terminal
**/
const unsigned KBleu = 34;

/**
* Variable representant la couleur magenta dans le terminal
**/
const unsigned KMagenta = 35;

/**
* Variable representant la couleur cyan dans le terminal
**/
const unsigned KCyan = 36;

// pour les elements sur le terminal

/**
* Variable representant le policier dans le terminal, la valeur est : " X "
**/
const char kTokenP = 'X';

/**
* Variable representant le voleur dans le terminal, la valeur est : " O "
**/
const char kTokenV = 'O';

/**
* Variable representant l'espace non occuper dans le terminal, la valeur est : " - "
**/
const char kEmpty = '-';

/**
* Variable representant les objets dans le terminal, la valeur est : " * "
**/
const char kTableau = '*';

/**
* Variable representant le mur dans le terminal, la valeur est : " # "
**/
const char kWall = '#';

#endif // TYPES_H
