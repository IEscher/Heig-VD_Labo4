/*
-----------------------------------------------------------------------------------
Nom du fichier  : controleSaisie.cpp
Auteur(s)       : Crotti Pablo, Escher Ian, Rosat Cédric
Date creation   : 07.11.2020

Description     : Contrôle que les entrées utilisateur ne soient que des nombres
                  entiers non-signés ainsi que leur inclusion dans les plages
                  MAX et MIN.

Remarque(s)     : Boucle de contrôle inspirée du cours de PRG1 et modifiée pour
                  les besoins du programme.
                  Une répétition de code à lieu lors du contrôle du type de la
                  valeur entrée, cela est nécessaire car 2 valeurs différentes sont
                  contrôlées.

Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include "controleSaisie.h"
#include <iostream>
using namespace std;

bool controleSaisie(unsigned int VALEUR1_MIN, unsigned int VALEUR1_MAX,
                    unsigned int VALEUR2_MIN, unsigned int VALEUR2_MAX,
                    unsigned int& valeur1, unsigned int& valeur2) {
    bool saisieOK;
    bool limitesOK;
    // Contrôle des limite défini à false. Il sera défini à true si les valeurs
    // 1 et 2 sont entrées correctement.
    limitesOK = false;
    // Contrôle entrée utilisateur
    if (!(cin >> valeur1)) { // Valeur n'est pas égal au type attendu
        cin.clear();
        saisieOK = false;
    } else if (cin.get() == '\n') { // Retour à la ligne entre valeur 1 et 2
        saisieOK = false;
    } else if (!(cin >> valeur2)) { // Valeur n'est pas égal au type attendu
        cin.clear();
        saisieOK = false;
    } else { // Aucune erreur de saisie
        saisieOK = true;
        // Contrôle que les valeurs soient dans les limites MAX et MIN si les
        // valeurs 1 et 2 sont correctes
        if (valeur1 >= VALEUR1_MIN && valeur1 <= VALEUR1_MAX) {
            if (valeur2 >= VALEUR2_MIN && valeur2 <= VALEUR2_MAX) {
                limitesOK = true;
            }
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Vide buffer
    return (saisieOK && limitesOK);
}