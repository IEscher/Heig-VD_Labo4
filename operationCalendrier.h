#ifndef OPERATIONCALENDRIER_H
#define OPERATIONCALENDRIER_H

// Retourne vrai si l'année en paramètre est bissextile, sinon retourne faux.
bool testBissextile(unsigned int annee);

// Retourne le nombre de jours dans un mois donné d'une année donnée.
unsigned int nbJoursMois(unsigned int mois, unsigned int annee);

// Retourne le nombre de jours entre deux dates données par leur mois et leur? année.
unsigned int calculDeltaJours(unsigned int moisDebut, unsigned int anneeDebut,
                              unsigned int moisFin, unsigned int anneeFin);

// Affiche dans la console le mois de l'année en paramètre dans un format calendrier.
void afficherMois(unsigned int mois, unsigned int annee);

#endif //OPERATIONCALENDRIER_H