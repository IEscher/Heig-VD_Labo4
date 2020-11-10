/*
-----------------------------------------------------------------------------------
Nom du fichier  : controleSaisie.cpp
Auteur(s)       : Crotti Pablo, Escher Ian, Rosat Cédric
Date creation   : 07.11.2020

Description     : Contrôle que les entrées utilisateur ne soient que des nombres
                  entiers ainsi que leur inclusion dans les plages MAX et MIN.

Remarque(s)     : Boucle de contrôle inspirée du cours de PRG1 et modifiée pour
                  les besoins du programme.

Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "controleSaisie.h"
#include <iostream>
#include <string>

using namespace std;

void controleSaisie(unsigned int VALEUR1_MIN, unsigned int VALEUR1_MAX,
                    unsigned int VALEUR2_MIN, unsigned int VALEUR2_MAX,
                    unsigned int *valeur1, unsigned int *valeur2,
                    string messageEntree, string messageErreur) {

    bool saisieOK;
    while (!saisieOK) {
        // Pas d'erreur en début de boucle
        saisieOK = true;
        cout << messageEntree;
        // Contrôle que les entrées soient numériques et entre MIN et MAX
        if (!(cin >> *valeur1 >> *valeur2)) {
            cin.clear();
            saisieOK = false;
        } else {
            if (*valeur1 < VALEUR1_MIN || *valeur1 > VALEUR1_MAX) saisieOK = false;
            if (*valeur2 < VALEUR2_MIN || *valeur2 > VALEUR2_MAX) saisieOK = false;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        saisieOK ? cout << endl : cout << messageErreur << endl << endl;
    }
}