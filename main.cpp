/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Crotti Pablo, Escher Ian, Rosat Cédric
Date creation   : 06.11.2020

Description     : Fichier principal du programme Labo3

Remarque(s)     : <à compléter>

Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include <string>
#include "controleSaisie.h"
#include "operationCalendrier.h"

using namespace std;

int main() {
   const unsigned int MOIS_MIN = 0, MOIS_MAX = 12;
   const unsigned int ANNEE_MIN = 1900, ANNEE_MAX = 2100;

   bool programmeActif = true;
   do {
      bool saisieDate;
      unsigned int moisDebut, anneeDebut, moisFin, anneeFin;
      do {
         // Pas d'erreur en début de boucle
         saisieDate = true;

         string messageErreur = "Date non valide. Veuillez SVP recommencer.";
         string messageEntree = "Veuillez entrer la date de debut [mm aaaa] :";
         controleSaisie(MOIS_MIN, MOIS_MAX, ANNEE_MIN, ANNEE_MAX, &moisDebut,
                        &anneeDebut, messageEntree, messageErreur);
         messageEntree = "Veuillez entrer la date de fin [mm aaaa] :";
         controleSaisie(MOIS_MIN, MOIS_MAX, ANNEE_MIN, ANNEE_MAX, &moisFin,
                        &anneeFin, messageEntree, messageErreur);

         // Contrôle la cohérence des dates
         if (anneeDebut > anneeFin) saisieDate = false;
         if (anneeDebut == anneeFin) {
            if (moisDebut > moisFin) saisieDate = false;
         }

         cout << moisDebut << "/" << anneeDebut << " - "
              << moisFin << "/" << anneeFin << endl;
      } while (!saisieDate);

      for (anneeDebut; anneeDebut <= anneeFin; anneeDebut++) {
         if (anneeDebut != anneeFin) {
            for (moisDebut; moisDebut <= 12; moisDebut++) {
               afficherMois(moisDebut, anneeDebut);
            }
         } else {// l'annee est égale à la date de fin
            for (moisDebut; moisDebut <= moisFin; moisDebut++) {
               afficherMois(moisDebut, anneeDebut);
            }
         }
         moisDebut = 1;
      }

      char nouvelleSaisie;
      cout << "Voulez-vous quitter le programme ? [o/n] :";
      cin >> nouvelleSaisie;
      if (nouvelleSaisie == 'o') programmeActif = true;
      if (nouvelleSaisie == 'n') programmeActif = false;
   } while (!programmeActif);

   return EXIT_SUCCESS;
}
