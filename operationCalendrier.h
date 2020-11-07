#ifndef OPERATIONCALENDRIER_H
#define OPERATIONCALENDRIER_H

bool testBissextile(unsigned int annee);

unsigned int nbJoursMois(unsigned int mois, unsigned int annee);

unsigned int calculDeltaJours(unsigned int moisDebut, unsigned int anneeDebut,
                              unsigned int moisFin, unsigned int anneeFin);

#endif //OPERATIONCALENDRIER_H
