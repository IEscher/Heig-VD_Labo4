/*
-----------------------------------------------------------------------------------
Nom du fichier  : controleSaisie.h
Auteur(s)       : Crotti Pablo, Escher Ian, Rosat Cédric
Date creation   : 07.11.2020

Description     : Contrôle que les entrées utilisateur ne soient que des nombres
                  entiers ainsi que leur inclusion dans les plages MAX et MIN.

Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#ifndef CONTROLESAISIE_H
#define CONTROLESAISIE_H

/**
 * @brief               contrôle le format et l'inclusion dans les bornes MIN et MAX
 * @param VALEUR1_MIN   valeur minimale incluse de la première entrée
 * @param VALEUR1_MAX   valeur maximale incluse de la première entrée
 * @param VALEUR2_MIN   valeur minimale incluse de la deuxième entrée
 * @param VALEUR2_MAX   valeur maximale incluse de la deuxième entrée
 * @param valeur1       valeur de la première entrée (par référence)
 * @param valeur2       valeur de la deuxième entrée (par référence)
 * @return              true si tous les contrôles sont justes, sinon false
 */
bool controleSaisie(unsigned int VALEUR1_MIN, unsigned int VALEUR1_MAX,
                    unsigned int VALEUR2_MIN, unsigned int VALEUR2_MAX,
                    unsigned int& valeur1, unsigned int& valeur2);

#endif // CONTROLESAISIE_H