#include "header.h"

int main(void)
{

    CONFIG config;
    config.read("Data/init_data.txt");

    Vec_p Particles(config.nmolecules);
    Vec_i Cells(config.gridsize*config.gridsize,0);
    Vec_i Cells_null(config.gridsize*config.gridsize,0);  
  
    start(config, Cells, Particles);

    const int partition_size = config.latticesize*config.latticesize/10;
    
    const int iterations = 10; //Número de veces que se calcula el tiempo de estabilización.
    double Stable_times[iterations]; //Tiempos de estabilización.
    
    for (int i = 0; i < iterations; i++){

        config.seed += i; //Para cada iteración se varia la seed aleatorea.

        Stable_times[i] += stability(config, partition_size, Particles, Cells); //Se calcula el tiempo de estabilización para una seed en especifico. 

        Cells = Cells_null;  //Reinicializa las celdas
        start(config, Cells, Particles); //Reinicializa las particulas.
    }

    double stable_time = gsl_stats_mean(Stable_times, 1, iterations);
    config.seed -= (iterations*(iterations-1))/2;

    start(config, Cells, Particles);

    std::mt19937 gen(config.seed);
    std::uniform_int_distribution<int> dis_move(0, 1);
    std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1);
  
    double Dropsize = 0;
    int random_particle = 0, step = 0, direction = 0;

    std::ofstream sizefile_1;   //Salida de entropia
    sizefile_1.open("Data/data_dropsize_1.txt");
  
    for(int t = 0; t < stable_time; t++ ){

        random_particle = dis_particle(gen);       
        step = dis_move(gen)*2 - 1;  
        direction = dis_move(gen); 
    
        Particles[random_particle].Move(step, direction, config, Cells);
        
        if (t%config.resolution == 0){
        
            Dropsize = dropsize (config, Particles);
            sizefile_1 << t << "\t"
                       << Dropsize << "\n";

        }
    }

    sizefile_1.close();

    std::ofstream sizefile_2;   //Salida de entropia
    sizefile_2.open("Data/data_dropsize_2.txt");
  
    for(int t = stable_time; t < config.tmax; t++){

        random_particle = dis_particle(gen);       
        step = dis_move(gen)*2 - 1;  
        direction = dis_move(gen); 
    
        Particles[random_particle].Move(step, direction, config, Cells);
        
        if (t%config.resolution == 0){
        
            Dropsize = dropsize (config, Particles);
            sizefile_2 << t << "\t"
                     << Dropsize << "\n";

        }
    }

    sizefile_2.close();
    
    return 0;
}
