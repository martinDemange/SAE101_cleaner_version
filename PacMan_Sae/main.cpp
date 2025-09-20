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
    string mapPathAbs = "/mnt/Windows/Users/aleni/Mes documents/3_EDUCATION"
                     "/IUT_AIX_MARSEILLE/BUT1_info_2024-2025/SAE/SAE1.01/SAE-101_v.1.00/SAE-DE-TES-MORTS/PacMan_Sae/Map1.txt";
    string mapPath = "../../Map1.txt";

    char tour = 'v' ;
    config param;
    initParam(param);
    CMatrix Mat ;
    CPosition posP ;
    CPosition posV ;

    //initialisation pour Mingl
    MinGL window("01 - Shapes", nsGraphics::Vec2D(640, 640), nsGraphics::Vec2D(140, 140), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    unsigned tabVole = 0;
    initMat(Mat, 15, 15, posP, posV, "/mnt/Windows/Users/aleni/Mes documents/3_EDUCATION/IUT_AIX_MARSEILLE/BUT1_info_2024-2025/SAE/SAE1.01/SAE-101_v.1.00/SAE-DE-TES-MORTS/PacMan_Sae/Map1.txt");
    //

    // showMatrix(Mat,tour); whitouth mingl
    showMatrix(window, Mat, tour);
    set_input_mode ();
    while (true) {
        clearScreen();
        if (posP == posV) {
            couleurF(KNoir);
            couleur(KRouge);
            cout << "Jouini t'as attrapé !" << endl ;
            couleur(KReset);
            break;
        }
        if (tabVole == 5) {
            couleurF(KNoir);
            couleur(KVert);
            cout << "Bravo tu fumes autant que Casali !" << endl ;
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
