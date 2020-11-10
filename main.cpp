/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Crotti Pablo, Escher Ian, Rosat Cédric
Date creation   : 05.11.2020

Description     : Ce programme demande à l'utilisateur de saisir deux dates et
                  affiche l'ensemble des pages calendrier correspondant à
                  l'intervalle entre les deux dates. Une fois l'affichage terminé,
                  le programme demande à l'utilisateur si il veut afficher un autre
                  calendrier ou quitter le programme.

Remarque(s)     : Les dates autorisées sont comprises entre janvier 1900 et
                  décembre 2020. Les saisies de l'utilisateur sont contrôlées.

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
   do {
      bool saisieDate;
      unsigned int moisDebut, anneeDebut, moisFin, anneeFin;
      do {
         string messageErreur = "Date non valide. Veuillez SVP recommencer.";
         string messageEntree = "Veuillez entrer la date de debut [mm aaaa] :";
         controleSaisie(MOIS_MIN, MOIS_MAX, ANNEE_MIN, ANNEE_MAX, &moisDebut,
                        &anneeDebut, messageEntree, messageErreur);
         messageEntree = "Veuillez entrer la date de fin [mm aaaa] :";
         controleSaisie(MOIS_MIN, MOIS_MAX, ANNEE_MIN, ANNEE_MAX, &moisFin,
                        &anneeFin, messageEntree, messageErreur);

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
      } while (!saisieDate);

      for (; anneeDebut <= anneeFin; anneeDebut++) {
         if (anneeDebut != anneeFin) {
            for (; moisDebut <= MOIS_MAX; moisDebut++) {
               afficherMois(moisDebut, anneeDebut);
            }
         } else {// l'annee est égale à la date de fin
            for (; moisDebut <= moisFin; moisDebut++) {
               afficherMois(moisDebut, anneeDebut);
            }
         }
         moisDebut = MOIS_MIN;
      }
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
