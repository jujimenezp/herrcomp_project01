#include "header.h"

double entropy (const CONFIG &object, const Vec_i &Cells){

  double s = 0, Entropy = 0;
  
  Entropy = std::log(object.nmolecules);
  
  for (int i = 0; i < object.gridsize*object.gridsize; i ++){
      
    if (Cells[i] != 0) {
      
      s += Cells[i]*std::log(Cells[i]);
      
    }
      
  }
  
  Entropy -= s/(1.0*object.nmolecules);

  return Entropy;
  
}

