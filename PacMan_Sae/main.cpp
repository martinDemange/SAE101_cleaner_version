#include <iostream>
// #include <vector>
// #include <fstream>
#include <unistd.h>
// #include <stdio.h>
#include <stdlib.h>
#include <termios.h>

#include "mouvementPerso.h"
#include "config.h"
#include "types.h"
#include "initialisation.h"
#include "gestion.h"

#include"affichage.h"

using namespace std;

int ppal(){
    // these var are only used for debugging purpose :
    string mapPath1 = "../../Map1.txt";
    string mapPath2 = "../../Map2.txt";

    string stealerWinA = "Bravo tu a collecté tous les collectible !";
    string stealerWinB = "Bravo tu fumes autant que Casali !";
    string copWinA = "Oh non, le policier t'a attrapé !";
    string copWinB = "Jouini t'as attrapé !";

    char tour = 'v' ;
    config param;
    initParam(param);
    CMatrix Mat ;
    CPosition posP ;
    CPosition posV ;

    //initialisation pour Mingl
    MinGL window("Game", nsGraphics::Vec2D(640, 640), nsGraphics::Vec2D(140, 140), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    unsigned tabVole = 0;
    initMat(Mat, 15, 15, posP, posV, mapPath1);
    // ver for map 2 :
    // initMat(Mat, 15, 34, posP, posV, mapPath2);

    // showMatrix(Mat,tour); whitouth mingl
    showMatrix(window, Mat, tour);
    set_input_mode ();
    while (true) {
        clearScreen();
        if (posP == posV) {
            couleurF(KNoir);
            couleur(KRouge);
            cout << copWinA << endl ;
            couleur(KReset);
            break;
        }
        if (tabVole == 5) {
            couleurF(KNoir);
            couleur(KVert);
            cout << stealerWinA << endl ;
            couleur(KReset);
            break;
        }

        char move ;
        if (tour == 'v') {
            CPosition PosValid = posV;
            while (posV == PosValid){
                read(STDIN_FILENO, &move, 1);
                moveTokenV(Mat, move, posV, tabVole, param);
            }
            tour = 'p' ;
            // showMatrix(Mat,tour); whitouth mingl
            showMatrix(window, Mat, tour);
            continue ;
        }
        if (tour == 'p') {
            CPosition PosValid = posP;
            while (posP == PosValid){
                read (STDIN_FILENO, &move, 1);
                moveTokenP(Mat, move, posP, param);
            }
            tour = 'v' ;
            // showMatrix(Mat,tour); whitouth mingl
            showMatrix(window, Mat, tour);
            continue ;
        }
    }
    return 0;
}

int main() {
    ppal();
    return 0;
}
