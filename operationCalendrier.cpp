/*
-----------------------------------------------------------------------------------
Nom du fichier  : operationCalendrier.cpp
Auteur(s)       : Ian Escher, Crotti Pablo, Rosat Cédric
Date creation   : 05.11.2020

Description     : Contient une fonction permettant de calculer si une année est
                  bissextille ou non, une fonction retournant le nombre de jours
                  que contient chaque mois, une fonction calculant le nombre de
                  jours entre deux dates et une fonction pour afficher le calendrier.

Remarque(s)     :

Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
#include "operationCalendrier.h"

using namespace std;

bool testBissextile(unsigned int annee) {
   if (annee % 400 == 0 || (annee % 4 == 0 && annee % 100 != 0)) {
      return true;
   } else { // Non divisible par 400 ou non divisible par 4
      return false;
   }
}

unsigned int nbJoursMois(unsigned int mois, unsigned int annee) {
   // Constantes définissant les différentes possibilités de jours dans un mois
   const unsigned int MOIS_LONG = 31;
   const unsigned int MOIS_COURT = 30;
   const unsigned int MOIS_BISSEXTILE = 29;
   const unsigned int MOIS_NON_BISSEXTILE = 28;

   // Janvier = 1, Fevrier = 2, etc...
   enum numMois {
      JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT, SEPTEMBRE,
      OCTOBRE, NOVEMBRE, DECEMBRE
   };

   switch ((numMois) mois) {
      case numMois::JANVIER:
      case numMois::MARS:
      case numMois::MAI:
      case numMois::JUILLET:
      case numMois::AOUT:
      case numMois::OCTOBRE:
      case numMois::DECEMBRE:
         return MOIS_LONG;
      case numMois::AVRIL:
      case numMois::JUIN:
      case numMois::SEPTEMBRE:
      case numMois::NOVEMBRE:
         return MOIS_COURT;
      case numMois::FEVRIER:
         if (testBissextile(annee)) {
            return MOIS_BISSEXTILE;
         } else { // Si il ne s'agit pas d'une année bissextile
            return MOIS_NON_BISSEXTILE;
         }
      default:
         return MOIS_LONG;
   }
}

unsigned int calculDeltaJours(unsigned int moisDebut, unsigned int anneeDebut,
                              unsigned int moisFin, unsigned int anneeFin) {

   // Contrôle la cohérence des dates et les inverse si necéssaire
   if (anneeDebut > anneeFin || (anneeDebut == anneeFin && moisDebut < moisFin)) {
      unsigned int moisTemp;
      unsigned int anneeTemp;

      anneeTemp = anneeFin;
      anneeFin = anneeDebut;
      anneeDebut = anneeTemp;

      moisTemp = moisFin;
      moisFin = moisDebut;
      moisDebut = moisTemp;
   }

   unsigned int deltaJours = 0;  // Nombre de jours entre la première date et la
   // deuxième

   for (unsigned int deltaAnnee = 0;
        deltaAnnee < anneeFin - anneeDebut; deltaAnnee++) {
      if (testBissextile(anneeDebut + deltaAnnee)) {
         deltaJours += 1;
      }
      deltaJours += 365;
   }

   if (moisFin - moisDebut < 0) { // Quand le mois de début est plus tard que le
      // mois de fin.
      unsigned int moisCalcul = moisDebut - 1;
      while (moisCalcul >= moisFin) {
         // Il faut enlever les jours qui ont été ajoutés en trop pour le nombre
         // d'années séparant les deux dates.
         deltaJours = deltaJours - nbJoursMois(moisCalcul, anneeFin);
         moisCalcul--;
      }
   } else if (moisFin - moisDebut > 0) { // Quand le mois de début est plus tôt que
      // le mois de fin.
      unsigned int moisCalcul = moisDebut;
      while (moisCalcul < moisFin) {
         // Il faut ajouter le nombre de jour séparant les deux dates.
         deltaJours = deltaJours + nbJoursMois(moisCalcul, anneeFin);
         moisCalcul++;
      }
   } // Si les deux mois correspondent, aucun calcul n'est nécessaire.

   return deltaJours;
}

void afficherMois(unsigned int mois, unsigned int annee) {
   // La date de référence ci-dessous doit correspondre obligatoirement à Lundi.
   const unsigned int MOIS_DE_REFERENCE = 1;
   const unsigned int ANNEE_DE_REFERENCE = 1900;

   unsigned int jourSurLaSemaine =
      calculDeltaJours(MOIS_DE_REFERENCE, ANNEE_DE_REFERENCE, mois, annee) % 7 + 1;
   // 1 = lundi, 2 = mardi, etc...

   string nomMois;
   switch (mois) {
      case 1:
         nomMois = "Janvier";
         break;
      case 2:
         nomMois = "Fevrier";
         break;
      case 3:
         nomMois = "Mars";
         break;
      case 4:
         nomMois = "Avril";
         break;
      case 5:
         nomMois = "Mai";
         break;
      case 6:
         nomMois = "Juin";
         break;
      case 7:
         nomMois = "Juillet";
         break;
      case 8:
         nomMois = "Aout";
         break;
      case 9:
         nomMois = "Septembre";
         break;
      case 10:
         nomMois = "Octobre";
         break;
      case 11:
         nomMois = "Novembre";
         break;
      case 12:
         nomMois = "Decembre";
         break;
      default:
         break;
   }

   // Affichage de l'entête
   cout << endl;
   cout << nomMois << " " << annee << endl;
   cout << endl;
   cout << " L  M  M  J  V  S  D" << endl;

   unsigned int jourDuMois = 1;
   cout << setw((int)(jourSurLaSemaine * 3 - 1)); // Décalage du premier jour sur
   // le calendrier

   // Affichage de tous les jours du mois
   while (jourDuMois <= nbJoursMois(mois, annee)) {
      cout << jourDuMois;
      jourDuMois++;
      if (jourSurLaSemaine == 7) { // Si un lundi
         jourSurLaSemaine = 1;
         cout << endl;
         cout << setw(2); // Décalage pour avoir un aspect de calendrier
      } else {
         jourSurLaSemaine++;
         cout << setw(3); // Décalage pour avoir un aspect de calendrier
      }
   }
   cout << endl;
}