#ifndef OPERATIONCALENDRIER_H
#define OPERATIONCALENDRIER_H

// Retourne vrai si l'année en paramètre est bissextile, sinon retourne faux.
/**
 * @brief Test si l'année en paramètre est bissextile
 * @param annee
 * @return true si l'année en paramètre est bissextile, sinon false
 */
bool testBissextile(unsigned int annee);

// Retourne le nombre de jours dans un mois donné d'une année donnée.
/**
 *
 * @param mois
 * @param annee permet de retourner le bon nombre de jours pour le mois de fevrier
 * @return
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