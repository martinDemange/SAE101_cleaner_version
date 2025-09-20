#include <fstream>
#include <iostream>
#include "initialisation.h"
#include "types.h"

using namespace std;

void initMat (CMatrix & Mat, const unsigned nbLine, const unsigned nbColumn, CPosition & posP, CPosition & posV, const string& fileName){
    Mat.assign(nbLine,CVLine(nbColumn));
    ifstream mapfile (fileName);
    if (!mapfile.good()) {
        cerr << "i can't find the file moommy" << endl;
        exit(2);
    }
    string input;
    for (unsigned i (0); i < nbLine; ++i){
        getline(mapfile, input);
        for (unsigned j (0); j < nbColumn; ++j) {
            if (input[j] == kTokenP) {
                posP = {i , j};
            }
            if (input[j] == kTokenV) {
                posV = {i, j};
            }
            Mat[i][j] = input[j];
        }
    }
}
