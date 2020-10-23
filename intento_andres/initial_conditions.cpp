#include "header.h"

void initial_conditions(const CONFIG &object, std::vector<PARTICLE> &configuracion, std::vector<int> &distribucion, std::vector<double> &probabilities)
{
  double nparticles = object.nparticles;
  
  for(int line = 0; line < std::sqrt(nparticles); line++){ //ubicacion inicial de las particulas en el espacio
    for(int column = 0; column < std::sqrt(nparticles); column++){
      configuracion[column+line*std::sqrt(nparticles)].initialize(object, column, line);
    }
  }

  for(int i = 0; i < nparticles; i++){ //calcula la distribucion inicial en el grid
    distribucion[configuracion[i].locate(object)] += 1;
  }

  int i = 0;
  for(auto pi : probabilities){
    pi = distribucion[i]/nparticles;
  }
  /*
  for(int i = 0; i < probabilities.size(); i++){ //probabilidades iniciales
    probabilities[i] = distribucion[i]/nparticles;
    if(distribucion[i] != 0){
      entropia -= probabilities[i]*(std::log(distribucion[i])-std::log(nparticles));
    }
  }
  */
}
