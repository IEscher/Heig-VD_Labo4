#include "bissextiles.h"

bool testBissextile(unsigned int annee){
   if(annee%400==0 || (annee%4==0 && annee%100!=0)){
      return true;
   }
   else{
      return false;
   }
}