#include "header.h"



double drop_size(int N, std::vector <Particle> &Particles)
{

  double Size=0;
  double I=0, sum=0;

  for (int t=0; t<N; t++)
    {
      I= std::pow(Particles[t].Getx(),2)+std::pow(Particles[t].Gety(),2);
      sum+=I;
    }
  Size=std::sqrt(sum/N);

  return Size;
}
