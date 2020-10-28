#include "header.h"

void PARTICLE::initialize(const CONFIG &object, const int i, const int j)
{
  posicion[0] = object.xlatticesize/2 - std::sqrt(object.nparticles)/2 + i;
  posicion[1] = object.ylatticesize/2 - std::sqrt(object.nparticles)/2 + j;
}

void PARTICLE::move(const CONFIG &object)
{
  int q = dis(seed);
  int p = dis(seed); //mover el aleatoreo al time step

  std::cout << q << "\n";
  std::cout << p << "\n";
  posicion[q] += 2*p-1;

  if(posicion[0] < 0 || posicion[0] > object.xlatticesize){
    posicion[0] -= 2*p-1; //bounce
  }
  
  if(posicion[1] < 0 || posicion[1] > object.ylatticesize){
    posicion[1] -= 2*p-1; //bounce
  }
  //posicion[2] = posicion[0] + posicion[1]*xlatticesize;
}

int PARTICLE::locate(const CONFIG &object)
{
  //int Cellsize = xrange/Xrange;
  int X = posicion[0]/object.xgridsize;
  int Y = posicion[1]/object.ygridsize;
  return X + Y*(object.xlatticesize/object.xgridsize);
}

void PARTICLE::print(const CONFIG &object)
{
  std::cout << posicion[0] << "\t" << posicion[1] << "\n";
}
