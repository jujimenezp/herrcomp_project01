#include "header.h"


std::vector <double> entropy(int tmax, int resol, int N, int m, std::vector<Particle> &Particles, std::vector<int> &Cel, std::vector<double> &S)
{
  int q,p,i,k,j=0;
  double s=0, P=0;
  
  for(int t=0; t<tmax; t++)
    {
      q = rand() % 2;           //genera un numero 0 o 1     
      p = -1 +(rand() % 2)*2;  //genera un numero -1 o 1      
      i=(rand() % N);         //numero aleatorio entre 0 y N-1
      
      k=Particles[i].Getcel();
      Cel[k]-=1;
      k=0;
      Particles[i].Move(p,q);
      k=Particles[i].Getcel();
      Cel[k]+=1;
      

      P=std::log(1.0*N);
      for(int ii=0; ii<m; ++ii){
        if(Cel[ii] != 0) s += Cel[ii]*std::log(1.0*Cel[ii]);
      }
      S[t]=P-s/(1.0*N);   
    }
  return S;
}

