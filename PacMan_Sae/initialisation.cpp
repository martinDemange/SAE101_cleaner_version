#include <fstream>
#include <iostream>
#include "initialisation.h"
#include "types.h"

using namespace std;

void initMat (CMatrix & Mat, CPosition & posP, CPosition & posV, const string& fileName){
    ifstream mapfile (fileName);
    if (!mapfile.good()) {
        cerr << "i can't find the file moommy" << endl;
        exit(2);
    }
    // file exists, get mapsize from it. maybe find a better way to do that lol
    size_t nbLine;
    nbLine << mapfile;
    size_t nbColumn;
    nbColumn << mapfile;
    
    Mat.assign(nbLine,CVLine(nbColumn));
    string input;  // warn: this input var isn't used out of the for loop.
    getline(mapfile, input);  // TODO: get rid of the first line after getting size
    for (unsigned i = 0; i < nbLine; ++i){
        getline(mapfile, input);
        for (unsigned j = 0; j < nbColumn; ++j) {
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
