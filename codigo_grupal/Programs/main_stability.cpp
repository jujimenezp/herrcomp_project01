#include "header.h"

int main(void)
{

    CONFIG config;
    config.read("Data/init_data.txt");  //Se leen los datos iniciales.

    Vec_p Particles(config.nmolecules);  //Vector de particulas.
    Vec_i Cells(config.gridsize*config.gridsize,0);  //Vector del número de particulas por celda.
  
    start(config, Cells, Particles); //Inicializa el sistema.

    //Tamaño de los conjuntos a los cuales se le aplica la linealización cuando se calcula la estabilidad. Depende de latticesize al cuadrado para que mantenga la tendencia esperada.
    const int partition_size = config.latticesize*config.latticesize/10;

    int stable_time = 0; //Tiempo de estabilización.
    int iterations = 10; //Número de veces que se calcula el tiempo de estabilización.

    for (int i = 0; i < iterations; i++){

        config.seed += i; //Para cada iteración se varia la seed aleatorea.

      stable_time += stability(config, partition_size, Particles, Cells)/(1.0*iterations); //Se calcula el tiempo de estabilización para una seed en especifico. 

    }

    //Imprime el tiempo de estabilización para el correspondiente tamaño del cuadrado. Tambien imprime el error estimado del tiempo, que se asume como la mitad de los intervalos tomados para el calculo.
    std::cout << config.latticesize << "\t" 
              << stable_time << "\t" << (partition_size -1)*config.resolution/2 << "\n";
  
    return 0;
}
