#include "mouvementPerso.h"
#include "types.h"
#include "config.h"

using namespace std;

void moveTokenV (CMatrix & Mat,const char& move, CPosition& pos, unsigned& tabVole, const config& param){
    Mat[pos.first][pos.second] = kEmpty;
    if (move == param.HautV){
        if (pos.first == 0) {
            pos.first = 0;
        }
        else {
            if (Mat[pos.first-1][pos.second] == kTableau){
                tabVole += 1;
            }
            if (Mat[pos.first-1][pos.second] != kWall){
                pos.first -= 1;
            }

        }
    }
    else if (move == param.GaucheV){
        if (pos.second == 0) {
            pos.second = 0;
        }
        else {
            if (Mat[pos.first][pos.second-1] == kTableau){
                tabVole += 1;
            }
            if (Mat[pos.first][pos.second-1] != kWall){
                pos.second -= 1 ;
            }

        }
    }
    else if (move == param.BasV){
        if (pos.first == 14) {
            pos.first = 14;
        }
        else {
            if (Mat[pos.first+1][pos.second] == kTableau){
                tabVole += 1;
            }
            if (Mat[pos.first+1][pos.second] != kWall){
                pos.first += 1 ;
            }
        }
    }
    else if (move == param.DroiteV){
        if (pos.second == 14) {
            pos.second = 14;
        }
        else {
            if (Mat[pos.first][pos.second+1] == kTableau){
                tabVole += 1;
            }
            if (Mat[pos.first][pos.second+1] != kWall){
                pos.second += 1;
            }
        }
    }
    Mat[pos.first][pos.second] = kTokenV;
}

void moveTokenP (CMatrix & Mat, const char& move, CPosition& pos, const config& param){
    Mat[pos.first][pos.second] = kEmpty;
    if (move == param.HautP){
        if (pos.first == 0) {
            pos.first = 0;
        }
        else {
            if (Mat[pos.first-1][pos.second] != kWall && Mat[pos.first-1][pos.second] != kTableau){
                pos.first -= 1;
            }
        }
    }
    else if (move == param.GaucheP){
        if (pos.second == 0) {
            pos.second = 0;
        }
        else {
            if (Mat[pos.first][pos.second-1] != kWall && Mat[pos.first][pos.second-1] != kTableau){
                pos.second -= 1 ;
            }
        }
    }
    else if (move == param.BasP){
        if (pos.first == 14) {
            pos.first = 14;
        }
        else {
            if (Mat[pos.first+1][pos.second] != kWall && Mat[pos.first+1][pos.second] != kTableau){
                pos.first += 1 ;
            }
        }
    }
    else if (move == param.DroiteP){
        if (pos.second == 14) {
            pos.second = 14;
        }
        else {
            if (Mat[pos.first][pos.second+1] != kWall && Mat[pos.first][pos.second+1] != kTableau){
                pos.second += 1;
            }
        }
    }
    Mat[pos.first][pos.second] = kTokenP;
}
