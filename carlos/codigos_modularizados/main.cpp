#include "header.h"


int main(void)
{
//-----------------------declaracion de constantes-----------------
 
  int N=0, Latsize=0, tmax=0, SEED=0, Gridsize=0, m=0, M=0, resol=100, t=0;
 
 getdatos(N, Latsize, tmax, SEED, Gridsize);
 
 srand(SEED);
 double L=Latsize; m=(Latsize/Gridsize);  M=m*m; t=tmax/resol;
 //-----------------------declaracion de vectores--------------
 
 std::vector <Particle> Particles (N);
 std::vector <int> Cel (M,0);
 std::vector <double> S (t, 0);
 std::vector <double> Size (t, 0);
 
 //-----------------------inicializa los vectors--------------
 
 start(N,M,m,L, Particles, Cel);
 
 //-------Imprimir las posiciones iniciales de las particulas---
 
 print_pos(Particles, "data_particles_start.txt", L);
 
 
 //---------------------calcula la entropia--------------
 
 entropy(tmax, resol, N, M, Particles, Cel, S, Size);
 
 //-------Imprimir las posiciones finales de las particulas---
 
 print_pos(Particles, "data_particles_end.txt", L);
 
 //-------------------Imprimir la entropia--------------  
 
 print_entro(S, "data_entropy.txt", resol);

 //-------------------Imprimir el tamaño de la gota-------  
 
 print_size(Size, "data_drop_size.txt", resol);
 
 //-----------------------liberar la memoria--------------
 
 std::vector<Particle>().swap(Particles);
 std::vector<int>().swap(Cel);
  std::vector<double>().swap(S);

 
 return 0;
}
