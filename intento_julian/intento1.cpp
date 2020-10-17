#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include "getdatos.h"

class particles //clase de particulas
{
    private:
        int x, y;
    public:
        int pos[2]={x,y}; //matriz de posiciones
        void step(int a); //ejecuta un paso en una particula
        
};


std::vector<particles> start(std::vector<particles> x, int N); //inicializa las particulas en un cuadrado
std::vector<int> getgrid(int a, int b, std::vector<particles> d); //cuenta cuantas particulas hay en cada cuadricula
void iteration(int a, int b, std::vector<particles> &d, int N, std::vector<int> &c); //Ejecuta el paso y actualiza el grid
int getg(int a, int b, int cx, int cy);  //encuentra la casilla en la que esta una particula
double entropy(std::vector<int> x, int N); //Calcula la entropia


void pvectorp(std::vector<particles> x); //Imprime vectores tipo particles
void pvectori(std::vector<int> x); //Imprime vectores tipo int




int main()
{
    //Obtencion de constantes de init_data.txt
    int data[5] = {400,200,1000000,1,8};
    //std::vector<int> data;
    //data = getdatos();
    
    
    //Declaracion de constantes
    const int SEED=data[3];           //semilla del generador aleatorio
    const int latsize=data[1];      //tamanio del lattice
    const int N=data[0];     //numero de particulas (Debe ser cuadrado perfecto para inicializacion)
    const int iterations=data[2]; //numero de iteraciones
    const int gridsize=data[4];  //tamanio del grid
    
    srand(SEED); //semilla de generacion

    double S=0; //Entropia
    std::vector <particles> particle (N); //vector de particulas
    std::vector <int> grid (gridsize*gridsize); //numero de particulas por cuadricula

    
    //inicializacion

    particle = start(particle, N);
    grid=getgrid(gridsize, latsize, particle);
    //pvectori(grid);
    //pvectorp(particle);
    
    //iteracion
    for(int ii=0; ii<iterations; ++ii){
        S=entropy(grid, N);
        iteration(gridsize, latsize, particle, N, grid);
        /*std::cout << ii << "\t"
                  << S
                  << "\n";*/
    }

    //pvectori(grid);
    pvectorp(particle);
    
    return 0;
}




//funciones de la clase particles

void particles::step(int a){
    int m = rand()%2;  //numero aleatorio 0 o 1
    int n = 2*(rand()%2)-1;  //numero aleatorio -1 o 1
    if(fabs(pos[m]+n) >= a/2) n=-n;  //condicion de frontera
    pos[m] += n;
}
    
    

//funciones de main

std::vector<particles> start(std::vector<particles> x, int N){
    int l=std::sqrt(N);
    
    for(int ii=0; ii<l; ++ii){
        for(int jj=0; jj<l; ++jj){
            int p=ii*l+jj;
            x[p].pos[0]=jj-l/2;
            x[p].pos[1]=ii-l/2;
        }
    }
    return x;
}

std::vector<int> getgrid(int a, int b, std::vector<particles> d){
    std::vector<int> gi(a*a);
    int m=0, n=0, p=0, g=0;
    for(int ii=0; ii<d.size(); ++ii){ 
        g=getg(a, b, d[ii].pos[0], d[ii].pos[1]);
        gi[g] += 1;
    }
    return gi;
}

void  iteration(int a, int b, std::vector<particles> &d, int N, std::vector<int> &c){

    int g, r=rand()%N;
    g=getg(a, b, d[r].pos[0], d[r].pos[1]);
    c[g] -= 1;
    d[r].step(b);
    g=getg(a, b, d[r].pos[0], d[r].pos[1]);
    c[g] += 1;
}

int getg(int a, int b, int cx, int cy){
    int m, n, p, g;
    m = (cy+b/2)*a/b;
    n = (cx+b/2)*a/b;
    g = a*m+n;
    return g;
}

double entropy(std::vector<int> x, int N){
    double s=0;
    double p=std::log(1.0*N);
    for(int ii=0; ii<x.size(); ++ii){
        if(x[ii] != 0) s += x[ii]*std::log(1.0*x[ii]);
    }
    s=p-s/(1.0*N);
    return s;
}


//funciones temporales
void pvectorp(std::vector<particles> x){
    for(int ii=0; ii<x.size(); ++ii){
        std::cout << ii << "\t"
                  << x[ii].pos[0] << "\t"
                  << x[ii].pos[1] << "\n";
    }
}
    
void pvectori(std::vector<int> x){
    for(int ii=0; ii<x.size(); ++ii){
        std::cout << ii << "\t"
                  << x[ii] << "\n";
    }
}
