/*
-----------------------------------------------------------------------------------
Nom du fichier  : controleSaisie.h
Auteur(s)       : Crotti Pablo, Escher Ian, Rosat Cédric
Date creation   : 07.11.2020

Description     : Ficher header de la fonction de contrôle des dates saisies.

Remarque(s)     : <à compléter>

Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include <string>

using namespace std;

#ifndef HEIG_VD_LABO4_CONTROLESAISIE_H
#define HEIG_VD_LABO4_CONTROLESAISIE_H

void controleSaisie(unsigned int VALEUR1_MIN, unsigned int VALEUR1_MAX,
                    unsigned int VALEUR2_MIN, unsigned int VALEUR2_MAX,
                    unsigned int *valeur1, unsigned int *valeur2,
                    string messageEntree, string messageErreur);

#endif //HEIG_VD_LABO4_CONTROLESAISIE_H
