/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Crotti Pablo, Escher Ian, Rosat Cédric
Date creation   : 05.11.2020

Description     : Ce programme demande à l'utilisateur de saisir deux dates et
                  affiche l'ensemble des pages calendrier correspondant à
                  l'intervalle entre les deux dates. Une fois l'affichage terminé,
                  le programme demande à l'utilisateur s'il veut afficher un autre
                  calendrier ou quitter le programme.

Remarque(s)     : Les dates autorisées sont comprises entre janvier 1900 et
                  décembre 2100. Les saisies de l'utilisateur sont contrôlées.

Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include <string>
#include "controleSaisie.h"
#include "operationCalendrier.h"

using namespace std;

int main() {
   const unsigned int MOIS_MIN = 1, MOIS_MAX = 12;
   const unsigned int ANNEE_MIN = 1900, ANNEE_MAX = 2100;

   bool programmeActif;
   do { // Boucle de répétition du programme
      bool saisieDate;
      unsigned int moisDebut, anneeDebut, moisFin, anneeFin;

      do { // Boucle de contrôle de saisie des dates
         bool valeur1_OK;
         do { // Boucle de contrôle du format et de la valeur de la première date
            cout << "Veuillez entrer la date de debut [mm aaaa] :";
            valeur1_OK = controleSaisie(MOIS_MIN, MOIS_MAX, ANNEE_MIN, ANNEE_MAX,
                                        moisDebut, anneeDebut);
            if (!valeur1_OK) {
               cout << "Date non valide. Veuillez SVP recommencer." << endl;
            }
         } while (!valeur1_OK);

         bool valeur2_OK;
         do { // Boucle de contrôle du format et de la valeur de la deuxième date
            cout << "Veuillez entrer la date de fin [mm aaaa] :";
            valeur2_OK = controleSaisie(MOIS_MIN, MOIS_MAX, ANNEE_MIN, ANNEE_MAX,
                                        moisFin, anneeFin);
            if (!valeur2_OK) {
               cout << "Date non valide. Veuillez SVP recommencer." << endl;
            }
         } while (!valeur2_OK);

         // Contrôle la cohérence des dates
         if (anneeDebut > anneeFin) {
            saisieDate = false;
         } else if (anneeDebut == anneeFin) {
            saisieDate = (moisDebut <= moisFin);
         } else {
            saisieDate = true;
         }

         if (!saisieDate) {
            cout << "Veuillez entrer une date de debut < que la date de fin."
                 << endl;
         }
      } while (!saisieDate); // Recommencer tant que les dates ne sont pas dans
      // le bon ordre


      // Affichage du calendrier
      for (; anneeDebut <= anneeFin; anneeDebut++) {
         if (anneeDebut != anneeFin) {
            for (; moisDebut <= MOIS_MAX; moisDebut++) { // Affiche tous les mois
               // d'une année
               afficherMois(moisDebut, anneeDebut);
            }
         } else {// L'année est égale à la date de fin
            for (; moisDebut <= moisFin; moisDebut++) {
               afficherMois(moisDebut, anneeDebut);
            }
         }
         moisDebut = MOIS_MIN; // Reset du compteur des mois
      }


      // Demande à l'utilisateur s'il souhaite recommencer
      char quitterProgramme;
      bool saisieOk = false;
      do {
         cout << "Voulez-vous quitter le programme ? [o/n] :";
         cin >> quitterProgramme;
         if (quitterProgramme == 'o') {
            programmeActif = false;
            saisieOk = true;
         } else if (quitterProgramme == 'n') {
            programmeActif = true;
            saisieOk = true;
         }
         if (!saisieOk) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Saisie incorrecte" << endl;
         }
      } while (!saisieOk);
   } while (programmeActif);

   return EXIT_SUCCESS;
}