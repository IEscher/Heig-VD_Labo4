#ifndef OPERATIONCALENDRIER_H
#define OPERATIONCALENDRIER_H

// Retourne vrai si l'année en paramètre est bissextile, sinon retourne faux.
/**
 * @brief Test si l'année en paramètre est bissextile
 * @param annee
 * @return true si l'année en paramètre est bissextile, sinon false
 */
bool testBissextile(unsigned int annee);

/**
 * @brief       Retourne le nombre de jours dans un mois donné d'une année donnée.
 * @param mois  le mois duquel on veut afficher le nombre de jours
 * @param annee l'année du mois désiré
 * @return      le nombre de jours du mois entré en paramètre
 */
unsigned int nbJoursMois(unsigned int mois, unsigned int annee);

/**
 * @brief               Retourne le nombre de jours entre deux dates, ces dernières
 *                      précisées par leur mois et par leur année. La deuxième
 *                      date doit être plus tard que la première.
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
 *              format calendrier. La deuxième date doit être plus tard que la
 *              première.
 * @param mois  le mois à afficher
 * @param annee l'année du mois désiré à afficher
 */
void afficherMois(unsigned int mois, unsigned int annee);

#endif //OPERATIONCALENDRIER_H