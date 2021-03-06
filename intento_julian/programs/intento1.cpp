#include <iostream>
#include "getdatos.h"
#include "particles.h"
#include "implementation.h"
#include "printdata.h"


int main()
{    
    //Declaracion de constantes
    
    int SEED=0;           //semilla del generador aleatorio
    int latsize=0;      //tamanio del lattice
    int N=0;     //numero de particulas (Debe ser cuadrado perfecto para inicializacion)
    int iterations=0; //numero de iteraciones
    int gridsize=0;  //numero de celdas

    //Obtencion de constantes iniciales de init_data.txt
    
    getdatos(N, latsize, iterations, SEED, gridsize);
    
    srand(SEED); //semilla de generacion

    //Declaracion de variables

    double S=0.0; //Entropia
    std::vector<double> entropy(gridsize*gridsize, 0.0);
    std::vector <particles> particle (N); //vector de particulas
    std::vector <int> grid (gridsize*gridsize); //numero de particulas por cuadricula

    
    //inicializacion

    start(particle, N);
    grid=getgrid(gridsize, latsize, particle);
    S = init_entropy(grid, N, entropy);
    

    //Imprimir las posiciones iniciales de las particulas
    print_pos(particle, "data/data_particles_start.txt");

    
    //iteraciones
    
    manyite(gridsize, latsize, particle, N, grid, iterations, S, entropy);

    //Imprimir las posiciones finales de las particulas
    print_pos(particle, "data/data_particles_end.txt");

    //Imprimir la entropia
    //print_entro(S, "data/data_entropy.txt");
    
    return 0;
}


