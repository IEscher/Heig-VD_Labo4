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

// Retourne le nombre de jours entre deux dates données par leur mois et leur? année.
/**
 *
 * @param moisDebut
 * @param anneeDebut
 * @param moisFin
 * @param anneeFin
 * @return
 */
unsigned int calculDeltaJours(unsigned int moisDebut, unsigned int anneeDebut,
                              unsigned int moisFin, unsigned int anneeFin);

// Affiche dans la console le mois de l'année en paramètre dans un format calendrier.
/**
 *
 * @param mois
 * @param annee
 */
void afficherMois(unsigned int mois, unsigned int annee);

#endif //OPERATIONCALENDRIER_H