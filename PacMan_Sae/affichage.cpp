/**
* @file affichage.cpp
* @author Martin Demange
* @brief contient le corps des fonctions utilisés pour l'affichage
**/
#ifndef AFFICHAGE_CPP
#define AFFICHAGE_CPP

#endif // AFFICHAGE_CPP

#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <fstream>
#include <thread>

#include "affichage.h"

// mingl
#include "mingl/mingl.h"

#include "mingl/shape/rectangle.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/line.h"
#include "mingl/shape/triangle.h"


#define FPS_LIMIT 60

using namespace std;

// void clearScreen () {
//     cout << "\033[H\033[2J";
// }

// void couleur (const unsigned & coul) {
//     cout << "\033[" << coul <<"m";
// }

// void couleurF (const unsigned & coul) {
//     cout << "\033[" << coul + 10 <<"m";
// }

void wallDrawn( MinGL & window, int x, int y){
    nsShape::Rectangle wall(nsGraphics::Vec2D(25*x, 25*y), nsGraphics::Vec2D(25*x+25, 25*y+25), nsGraphics::KGray);
    window << wall;
}

void spaceDrawn (MinGL & window, int x, int y){
    nsShape::Rectangle space(nsGraphics::Vec2D(25*x, 25*y), nsGraphics::Vec2D(25*x+25, 25*y+25), nsGraphics::KGray);
    window << space;
}

void policeDraw (MinGL & window, int x, int y){
    // tempory
    window << nsShape::Line(nsGraphics::Vec2D(x*25, y*25), nsGraphics::Vec2D(x*25+25, y*25+25), nsGraphics::KBlue, 3.f);
    window << nsShape::Line(nsGraphics::Vec2D(x*25+25, y*25), nsGraphics::Vec2D(x*25, y*25+25), nsGraphics::KBlue, 3.f);

}

void voleurDraw(MinGL & window, int x, int y){
    //temporary
    window << nsShape::Circle(nsGraphics::Vec2D(x*25+12,y*25+12),12,nsGraphics::KRed);
}

void tableauDraw( MinGL & window, int x, int y){
    window << nsShape::Line(nsGraphics::Vec2D(x*25, y*25), nsGraphics::Vec2D(x*25+5, y*25+5), nsGraphics::KRed, 7.f);
    window << nsShape::Line(nsGraphics::Vec2D(x*25+5, y*25+5), nsGraphics::Vec2D(x*25+20, y*25+20), nsGraphics::KWhite, 7.f);
    window << nsShape::Line(nsGraphics::Vec2D(x*25+20, y*25+20), nsGraphics::Vec2D(x*25+25, y*25+25), nsGraphics::KYellow, 7.f);

}

void  showMatrix (MinGL & window ,const CMatrix & Mat, const char &tour){ // j'ai ajouter le param window car sans ça il serait pas possible d'utiliser la fenetre mingl sans la decalre dans la fonction ce qui posera un probleme
    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    //clear la fenetre mingl
    clearScreen();

    // Récupère l'heure actuelle
    chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

    // On efface la fenêtre
    window.clearScreen();

    if (tour == 'v') cout << "Tour du voleur" << endl;
    if (tour == 'p') cout << "Tour du policier" << endl;
    for (size_t i (0); i < Mat.size(); ++i) {
        for (size_t j (0); j < Mat.size(); ++j) {
            if (Mat[i][j] == kTokenP) {
                couleur(KBleu);
                cout << kTokenP ;
                couleur(KReset);
                policeDraw(window,j,i);
            }
            else if (Mat[i][j] == kTokenV){
                couleur(KRouge);
                cout << kTokenV ;
                couleur(KReset);
                voleurDraw(window,j,i);
            }
            else if (Mat[i][j] == kTableau){
                couleur(KVert);
                cout << kTableau ;
                couleur(KReset);
                tableauDraw(window,j,i);
            }
            else if (Mat[i][j] == kWall){
                couleur(KJaune);
                cout << kWall ;
                couleur(KReset);
                wallDrawn(window,j,i);
            }
            else {
                cout << kEmpty ;
                // spaceDrawn(window,j,i); non used
            }
        }
        cout << endl;
    }

    // On finit la frame en cours
    window.finishFrame();

    // On vide la queue d'évènements
    window.getEventManager().clearEvents();

    // On attend un peu pour limiter le framerate et soulager le CPU
    this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));

    // On récupère le temps de frame
    frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
}
