/**
* @file config.h
* @author Santos Jorge Francisco
* @brief Contient la signature des fonctions utiliser pour configurer le jeu.
**/

#ifndef CONFIG_H
#define CONFIG_H

/**
 * @brief Une classe regrouant les variables de configuration lors l'initParam
 */
struct config {
    char GaucheP = 'q';
    char DroiteP = 'd';
    char HautP = 'z';
    char BasP = 's';
    char GaucheV = 'q';
    char DroiteV = 'd';
    char HautV = 'z';
    char BasV = 's';
};

/**
 * @brief Fonction permettant d'initialiser les différents paramètres de configuration.
 * @param[in out] param : Un dictionnaire contenant en clé l'élément à modifier et la valeur.
 */
void initParam(config& param);

#endif // CONFIG_H
