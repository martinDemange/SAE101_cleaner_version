#include <fstream>
#include <map>
#include "config.h"
#include "main.cpp"

using namespace std;

void buffer(string& entree) {
    string tmp;
    for (size_t i = 0; i < entree.size(); ++i)
        if (!isspace(entree[i])) tmp += entree[i];
    entree = tmp;
}

void initParam(config& param) {
    // boucle lecture (tant que on lit getline machin)
    // on prend la clé et la valeur avec substr machin
    // on met dans une map temp avec map[clé] = valeur
    // un fois la boucle fini,
    // chaque éléments dans le struct
    // on lui donne la valeur dans la map temp (donc genre param.caracVoleur = map["caracVoleur"])

    // these var are only used for debugging purpose
    string confPath = "../../config.yaml";
    string confPathAbs ="/mnt/Windows/Users/aleni/Mes documents/3_EDUCATION"
                         "/IUT_AIX_MARSEILLE/BUT1_info_2024-2025/SAE/SAE1.01/SAE-101_v.1.00/SAE-DE-TES-MORTS/PacMan_Sae";

    ifstream paramFichier(confPath);
    if (!paramFichier.good())
        exit(2);
    string entree;
    map<string, string> paramTemp;
    while(getline(paramFichier, entree)){
        cout << entree << endl;
        buffer(entree);
        cout << entree << endl;
        size_t sepPos = entree.find(':');
        string clef = entree.substr(0, sepPos);
        string valeur = entree.substr(sepPos+1);
        paramTemp[clef] = valeur;
    }
    param.HautV = paramTemp.find("HautV")->second[0];
    param.HautP = paramTemp.find("HautP")->second[0];
    param.BasV = paramTemp.find("BasV")->second[0];
    param.BasP = paramTemp.find("BasP")->second[0];
    param.GaucheV = paramTemp.find("GaucheV")->second[0];
    param.GaucheP = paramTemp.find("GaucheP")->second[0];
    param.DroiteV = paramTemp.find("DroiteV")->second[0];
    param.DroiteP = paramTemp.find("DroiteP")->second[0];
}
