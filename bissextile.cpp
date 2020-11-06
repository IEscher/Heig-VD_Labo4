#include "bissextile.h"

bool testBissextile(unsigned short annee){
   if(annee%400==0 || (annee%4==0 && annee%100!=0)){
      return true;
   }
   else{
      return false;
   }
}