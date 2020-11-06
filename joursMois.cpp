bool testBissextile(unsigned short annee) {
   if (annee % 400 == 0 || (annee % 4 == 0 && annee % 100 != 0)) {
      return true;
   } else { // non divisible par 400 ou non divisible par 4
      return false;
   }
}

unsigned short nbJoursMois(unsigned short mois, unsigned short annee) {
   // Constantes définissant les différentes possibilités de jours dans un mois
   const unsigned short MOIS_LONG = 31;
   const unsigned short MOIS_COURT = 30;
   const unsigned short MOIS_BISSEXTILE = 29;
   const unsigned short MOIS_NON_BISSEXTILE = 28;

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
         } else { // Si il ne s'agit pas d'une annee bissextile
            return MOIS_NON_BISSEXTILE;
         }
      default:
         return MOIS_LONG;
   }
}

