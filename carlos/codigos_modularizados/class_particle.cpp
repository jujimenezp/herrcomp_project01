#include "header.h"

void Particle::start(int x0,int y0, int NN, double LL){
  position[0]=x0; position[1]=y0; N=NN; L=LL; l=L/N;}

void Particle::Move(int p, int q){

  if((position[q]+p) >= L || (position[q]+p) <= 0) p=-p;
  position[q] += p;

}

int Particle::Getcel(void){
  int X=0, Y=0;
  X=position[0]/l;
  Y=position[1]/l;
  cel=X+Y*N;
  return cel;}
