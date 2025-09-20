/**
* @file affichage.h
* @author Martin Demange
* @brief Contient la signature des fonctions utiliser pour l'affichage.
**/

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <vector>

#endif // AFFICHAGE_H

// mingl
#include "mingl/mingl.h"
#include "mingl/shape/rectangle.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/line.h"
#include "mingl/shape/triangle.h"

#include "types.h"
#include "gestion.h"

/**
* @brief Cette fonction a pour but de dessiner une mur dans la fenetre mingl
* @fn wallDrawn( MinGL & window, int x, int y);
* @param window La fenetre mingl, de type MinGL
* @param x La position sur l'axe x du mur, de type int
* @param y La position sur l'axe y du mur, de type int
* @callgraph
* @callergraph
*/
void wallDrawn( MinGL & window, int x, int y);

/**
* @brief Cette fonction a pour but de dessiner un espace represente l'aire de jeux dans la fenetre mingl
* @fn spaceDrawn (MinGL & window, int x, int y);
* @param window La fenetre mingl, de type MinGL
* @param x La position sur l'axe x de l'espace, de type int
* @param y La position sur l'axe y de l'espace, de type int
* @callgraph
* @callergraph
*/
void spaceDrawn (MinGL & window, int x, int y);

/**
* @brief Cette fonction a pour but de dessiner le policie dans la fenetre mingl
* @fn policeDraw (MinGL & window, int x, int y);
* @param window La fenetre mingl, de type MinGL
* @param x La position sur l'axe x du policier, de type int
* @param y La position sur l'axe y du policier, de type int
* @callgraph
* @callergraph
*/
void policeDraw (MinGL & window, int x, int y);

/**
* @brief Cette fonction a pour but de dessiner le voleur dans la fenetre mingl
* @fn voleurDraw(MinGL & window, int x, int y);
* @param window La fenetre mingl, de type MinGL
* @param x La position sur l'axe x du voleur, de type int
* @param y La position sur l'axe y du voleur, de type int
* @callgraph
* @callergraph
*/
void voleurDraw(MinGL & window, int x, int y);

/**
* @brief Cette fonction a pour but de dessiner les objet que le voleur doit prendre dans la fenetre mingl
* @fn tableauDraw( MinGL & window, int x, int y);
* @param window La fenetre mingl, de type MinGL
* @param x La position sur l'axe x de l'objet, de type int
* @param y La position sur l'axe y de l'objet, de type int
* @callgraph
* @callergraph
*/
void tableauDraw( MinGL & window, int x, int y);

/**
* @brief Cette fonction a pour but d'afficher sur le terminal et de dessiner sur la fenetre mingl
* @fn showMatrix (MinGL & window ,const CMatrix & Mat, const char &tour);
* @param window La fenetre mingl, de type MinGL
* @param Mat La matrice ou les objets sont posé, de type const CMatrix
* @param tour Sert à indique si c'est le tour du policier ou du voleur, de type const char
* @callgraph
* @callergraph
*/
void showMatrix (MinGL & window , const CMatrix & Mat, const char &tour);
