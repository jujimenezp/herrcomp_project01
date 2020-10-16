#include <iostream>
#include <cmath>
#include <vector>

class particles //clase de particulas
{
    private:
        int x, y;
    public:
        int pos[2]={x,y};
        void initialize(int a); //
        void step();
        
};

std::vector<particles> start(std::vector<particles> x, int y); //inicializa las particulas en un cuadrado
std::vector<int> getgrid(int a, int b, std::vector<particles> d); //cuenta cuantas particulas hay en cada cuadricula
std::vector<int> iteration(int a, int b, std::vector<particles> d, int N, std::vector<int> c); //Ejecuta el paso y actualiza el grid
int getg(int a, int b, int cx, int cy);  //encuentra la casilla en la que esta una particula

void pvectorp(std::vector<particles> x);
void pvectori(std::vector<int> x);




int main()
{
    //Declaracion de constantes
    const int SEED=1;           //semilla del generador aleatorio
    const int latsize=200;      //tamanio del lattice
    const int N=400;     //numero de particulas
    const int iterations=1000000; //numero de iteraciones
    const int initsize=20; //tamanio del cuadro de inicio
    const int gridsize=8;  //tamanio del grid
    
    srand(SEED); //semilla de generacion

    std::vector <particles> particle (N); //vector de particulas
    std::vector <int> grid (gridsize*gridsize); //numero de particulas por cuadricula

    //inicializacion

    particle = start(particle, initsize);
    grid=getgrid(gridsize, latsize, particle);
    pvectori(grid);
    //pvectorp(particle);
    
    //iteracion
    for(int ii=0; ii<200000; ++ii){
        //grid=iteration(gridsize, latsize, particle, N, grid);
        int g, r=rand()%N;
        g=getg(gridsize, latsize, particle[r].pos[0], particle[r].pos[1]);
        grid[g] -= 1;
        particle[r].step();
        g=getg(gridsize, latsize, particle[r].pos[0], particle[r].pos[1]);
        grid[g] += 1;
    }

    pvectori(grid);
    //pvectorp(particle);
    
    return 0;
}




//funciones de la clase particles

void particles::initialize(int a){
    pos[0]=(rand())%(a+1)-a/2;
    pos[1]=(rand())%(a+1)-a/2;
}

void particles::step(){
    int m = rand()%2;  //numero aleatorio 0 o 1
    int n = 2*(rand()%2)-1;  //numero aleatorio -1 o 1
    pos[m] += n;
}
    
    

//funciones de main

std::vector<particles> start(std::vector<particles> x, int y){
    for(int ii=0; ii < x.size(); ++ii){
        x[ii].initialize(y);

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

std::vector<int> iteration(int a, int b, std::vector<particles> d, int N, std::vector<int> c){
    std::vector<int> gi = c;
    int g, r=rand()%N;
    g=getg(a, b, d[r].pos[0], d[r].pos[1]);
    gi[g] -= 1;
    d[r].step();
    g=getg(a, b, d[r].pos[0], d[r].pos[1]);
    gi[g] += 1;
    return gi;
}

int getg(int a, int b, int cx, int cy){
    int m, n, p, g;
    m = (cy+b/2)*a/b;
    n = (cx+b/2)*a/b;
    g = a*m+n;
    return g;
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

