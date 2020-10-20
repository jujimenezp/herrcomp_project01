#include "header.h"


void start(int N, int m, int M, double L, std::vector<Particle> &Particles, std::vector<int> &Cel)
{
  int k;
  int l=std::sqrt(N);

  for(int ii=0; ii<l; ++ii){    //inicializa en un cuadrado           
    for(int jj=0; jj<l; ++jj){
      int p=ii*l+jj;
      Particles[p].start(50+(jj-l/2),50+(ii-l/2), M, L);
    }
  }
  for(int ii=0; ii<N; ii++)
    {
      k=Particles[ii].Getcel();
      Cel[k]+=1;
    }
}
