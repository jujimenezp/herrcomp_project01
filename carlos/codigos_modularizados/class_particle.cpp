#include "header.h"

//------------------------ Declarar constantes globales------------

 int const Nx=8, Ny=8;      //divisiones del latice
 int const Lx=200, Ly=200; //la longitud de los lados del latice


void entropy(int tmax, int N, int m, std::vector<Particle> &Particles, std::vector<int> &Cel)
{
  int q,p,i,k;
  double S=0;
  int tdibujo=tmax/500, tcuadro=0;
  for(int t=0; t<=tmax; t++)
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
      tdibujo+=1;
    double p=std::log(1.0*N);
    for(int ii=0; ii<m; ++ii){
        if(Cel[ii] != 0) S += Cel[ii]*std::log(1.0*Cel[ii]);
    }
    S=p-S/(1.0*N);
    
    if(tdibujo>tcuadro){
      
      // hacer un plot                    
      std::cout << t << "\t" << S << std::endl;                     
      tdibujo=0;
      
    }  
    }
}
