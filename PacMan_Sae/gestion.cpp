
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <iostream>

#include "gestion.h"
#include "types.h"

using namespace std;

struct termios saved_attributes;

void
reset_input_mode (void) {
    tcsetattr (STDIN_FILENO, TCSANOW, &saved_attributes);
}

void
set_input_mode (void) {
    struct termios tattr;

    /* Make sure stdin is a terminal. */
    if (!isatty (STDIN_FILENO))
    {
        fprintf (stderr, "Not a terminal.\n");
        exit (EXIT_FAILURE);
    }

    /* Save the terminal attributes so we can restore them later. */
    tcgetattr (STDIN_FILENO, &saved_attributes);
    atexit (reset_input_mode);

    /* Set the funny terminal modes. */
    tcgetattr (STDIN_FILENO, &tattr);
    tattr.c_lflag &= ~(ICANON|ECHO); /* Clear ICANON and ECHO. */
    tattr.c_cc[VMIN] = 1;
    tattr.c_cc[VTIME] = 0;
    tcsetattr (STDIN_FILENO, TCSAFLUSH, &tattr);
}


void clearScreen () {
    cout << "\033[H\033[2J";
}

void couleur (const unsigned & coul) {
    cout << "\033[" << coul <<"m";
}

void couleurF (const unsigned & coul) {
    cout << "\033[" << coul + 10 <<"m";
}

// void  showMatrix (const CMatrix & Mat, const char &tour){
//     clearScreen();
//     if (tour == 'v') cout << "Tour du voleur" << endl;
//     if (tour == 'p') cout << "Tour du policier" << endl;
//     for (size_t i (0); i < Mat.size(); ++i) {
//         for (size_t j (0); j < Mat.size(); ++j) {
//             if (Mat[i][j] == kTokenP) {
//                 couleur(KBleu);
//                 cout << kTokenP ;
//                 couleur(KReset);
//             }
//             else if (Mat[i][j] == kTokenV){
//                 couleur(KRouge);
//                 cout << kTokenV ;
//                 couleur(KReset);
//             }
//             else if (Mat[i][j] == kTableau){
//                 couleur(KVert);
//                 cout << kTableau ;
//                 couleur(KReset);
//             }
//             else if (Mat[i][j] == kWall){
//                 couleur(KJaune);
//                 cout << kWall ;
//                 couleur(KReset);
//             }
//             else {
//                 cout << kEmpty ;
//             }
//         }
//         cout << endl ;
//     }
// }
