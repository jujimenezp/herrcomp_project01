#include <iostream>
#include <cmath>
#include <vector>
//------------------------ Declarar constantes globales------------

 int const Nx=8, Ny=8;      //divisiones del latice
 int const Lx=200, Ly=200; //la longitud de los lados del latice

//------------------------Declarar clases-------------------------
class Particle;

//-----------------------Implementar clase-----------------------

class Particle{
  
private:
  
  int position[2]={0,0}; int cel=0; double lx=Lx/Nx, ly=Ly/Ny;
  
public:
  
  void start(int x0, int y0);
  void Move(int p, int q);
  int Getx(void){return position[0];};       
  int Gety(void){return position[1];};
  int Getcel(void);
};

void Particle::start(int x0,int y0){
  position[0]=x0; position[1]=y0;}

void Particle::Move(int p, int q){

  if((position[q]+p) >= Lx || (position[q]+p) <= 0) p=-p; 
  position[q] += p;
   
}

int Particle::Getcel(void){
  int X=0, Y=0;
  X=position[0]/lx;
  Y=position[1]/ly;
  cel=X+Y*Ny;
  return cel;}
//----------------------declaracion de funciones----------------------

void start(int N, int m, std::vector<Particle> &Particles, std::vector<int> &Cel);
void entropy(int tmax, int N, int m, std::vector<Particle> &Particles, std::vector<int> &Cel);

//-----------------------funcion principal--------------------------

int main(void)
{
 srand(0);
//-----------------------declaracion de constantes-----------------
 
 int tmax=10000000;   //tiempo maximo de la simulacion
 int N=400;        //numero de particulas
 int M=Nx*Ny;     //numero de celdas del latice
    
//-----------------------declaracion de vectores--------------  

 std::vector <Particle> Particles (N);
 std::vector <int> Cel (M,0);

  start(N,M, Particles, Cel); //inicializa los vectors
  
  entropy(tmax, N, M, Particles, Cel); //calcula la entropia y permite graficarla
  std::vector<Particle>().swap(Particles);   //liberar la memoria
  std::vector<int>().swap(Cel);
  
  return 0;
}
//----------------------funcion start----------------------

void start(int N, int m, std::vector<Particle> &Particles, std::vector<int> &Cel)
{
  int k;
  int l=std::sqrt(N);
  
  for(int ii=0; ii<l; ++ii){    //inicializa en un cuadrado
    for(int jj=0; jj<l; ++jj){
      int p=ii*l+jj;
      Particles[p].start(50+(jj-l/2),50+(ii-l/2));
    }
  }
  
  for(int ii=0; ii<N; ii++)
    {
      k=Particles[ii].Getcel();
      Cel[k]+=1;
    }
 
}

//-----------------------función entropia--------------------------

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
