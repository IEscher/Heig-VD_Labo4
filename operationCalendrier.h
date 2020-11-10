#ifndef OPERATIONCALENDRIER_H
#define OPERATIONCALENDRIER_H

/**
 * @brief           Test si l'année en paramètre est bissextile
 * @param annee     l'année à tester
 * @return          true si l'année en paramètre est bissextile, sinon false
 */
bool testBissextile(unsigned int annee);

/**
 * @brief           Retourne le nombre de jours que contient un mois donné
 * @param mois      le mois à tester
 * @param annee     l'année pour tester le nombre de jours du mois de février
 * @return          le nombre de jours d'un mois donné
 */
unsigned int nbJoursMois(unsigned int mois, unsigned int annee);

/**
 * @brief               Retourne le nombre de jours entre deux dates, ces dernières
 *                      précisées par leur mois et par leur année. Si la deuxième
 *                      date est plus tôt que la première, les dates sont inversées.
 * @param moisDebut     le mois de la première date
 * @param anneeDebut    l'année de la première date
 * @param moisFin       le mois de la dernère date
 * @param anneeFin      l'année de la dernière date
 * @return              le nombre de jours entre les deux dates.
 */
unsigned int calculDeltaJours(unsigned int moisDebut, unsigned int anneeDebut,
                              unsigned int moisFin, unsigned int anneeFin);

/**
 * @brief       Affiche dans la console le mois de l'année en paramètre dans un
 *              format calendrier.
 * @param mois  le mois à afficher
 * @param annee l'année du mois désiré à afficher
 */
void afficherMois(unsigned int mois, unsigned int annee);

#endif // OPERATIONCALENDRIER_H