#include "header.h"

double entropy (const CONFIG &object, const Vec_i &Cells){

  double s = 0, Entropy = 0;
  
  Entropy = std::log(object.nmolecules);
  
  for (auto i: Cells){
    if (i != 0) {
      
      s += i*std::log(i);
      
    }
  }
  
  Entropy -= s/(1.0*object.nmolecules);

  return Entropy;
  
}

