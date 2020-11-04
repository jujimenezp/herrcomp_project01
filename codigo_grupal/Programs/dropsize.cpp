#include "header.h"

double dropsize(const CONFIG &config,const Vec_p &Particles)
{
  double suma=0,x=0,y=0,r=0,size=0;
  
    for(auto i: Particles){
      x=i.position[0]+0.5;
      y=i.position[1]+0.5;
      r=std::hypot(x,y);
      suma +=std::pow(r,2);
  }
    size=std::sqrt(suma/config.nmolecules);

    return size;
}
