#include "../../Programs/header.h"

int main(void)
{

    auto a = std::chrono::steady_clock::now();

    CONFIG config;
    config.read("../Data/init_data.txt");  //Se leen los datos iniciales.

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

    auto b = std::chrono::steady_clock::now();

    double time = std::chrono::duration_cast<std::chrono::nanoseconds>(b-a).count()*1.0e-9;
    
    std::cout << stable_time << "\t" 
              << time << "\n";
  
    return 0;
}
