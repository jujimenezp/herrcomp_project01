#include <iostream>
#include "getdatos.h"
#include "particles.h"
#include "implementation.h"
#include "printdata.h"


void pvectorp(std::vector<particles> x); //Imprime vectores tipo particles
void pvectori(std::vector<int> x); //Imprime vectores tipo int


int main()
{   
    
    //Declaracion de constantes
    int SEED=0;           //semilla del generador aleatorio
    int latsize=0;      //tamanio del lattice
    int N=0;     //numero de particulas (Debe ser cuadrado perfecto para inicializacion)
    int iterations=0; //numero de iteraciones
    int gridsize=0;  //tamanio del grid


    //Obtencion de constantes de init_data.txt
    getdatos(N, latsize, iterations, SEED, gridsize);
    
    
    srand(SEED); //semilla de generacion

    double S=0.0; //Entropia
    std::vector <particles> particle (N); //vector de particulas
    std::vector <int> grid (gridsize*gridsize); //numero de particulas por cuadricula

    
    //inicializacion

    particle = start(particle, N);
    grid=getgrid(gridsize, latsize, particle);

    //Imprimir las posiciones iniciales de las particulas
    print_pos(particle, "data_particles_start.txt");
    
    //pvectori(grid);
    
    //iteraciones
    
    manyite(gridsize, latsize, particle, N, grid, iterations, S);

    //Imprimir las posiciones finales de las particulas
    print_pos(particle, "data_particles_end.txt");

    //pvectori(grid);
    //pvectorp(particle);
    
    return 0;
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
