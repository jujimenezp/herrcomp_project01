#include "header.h"

int main(void)
{

    CONFIG config;
    config.read("Data/init_data.txt");  //Se leen los datos iniciales.

    Vec_p Particles(config.nmolecules);  //Vector de particulas.
    Vec_i Cells(config.gridsize*config.gridsize,0);  //Vector del numero de particulas por celda.
    Vec_i Cells_null(config.gridsize*config.gridsize,0);  //Vector nulo
  
    start(config, Cells, Particles); //Inicializa el sistema.

    //Tamaño de los conjuntos a los cuales se le aplica la linealización cuando se calcula la estabilidad.
    //Depende de latticesize al cuadrado para que mantenga la tendencia esperada.
    const int partition_size = config.latticesize*config.latticesize/10;
    
    const int iterations = 10; //Numero de veces que se calcula el tiempo de estabilizacion
    double Stable_times[iterations]; //Tiempos de estabilizacion.
    
    for (int i = 0; i < iterations; i++){

        config.seed += i; //Para cada iteracion se varia la seed aleatoria.

        Stable_times[i] = stability(config, partition_size, Particles, Cells); //Se calcula el tiempo de estabilizacion para una seed en especifico. 

        Cells = Cells_null;  //Reinicializa las celdas
        start(config, Cells, Particles); //Reinicializa las particulas.
    }

    double stable_time = gsl_stats_mean (Stable_times, 1, iterations); //Calcula el promedio de los tiempos
    double stable_time_error = gsl_stats_sd_m (Stable_times, 1, iterations, stable_time);  //Calcula el error en la estimacion de los tiempos
    
    //Imprime el tiempo de estabilizacion para el correspondiente tamaño del cuadrado. Tambien imprime el error estimado del tiempo, que se asume como la desviación estandar calculada.
    std::cout << config.latticesize << "\t" 
              << stable_time << "\t" << stable_time_error << "\n";
  
    return 0;
}
