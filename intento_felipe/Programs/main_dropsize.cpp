#include "header.h"

int main(void)
{

    CONFIG config;
    config.read("Data/init_data.txt");

    Vec_p Particles(config.nmolecules);
    Vec_i Cells(config.gridsize*config.gridsize,0);
  
    start(config, Cells, Particles);

    const int partition_size = config.latticesize*config.latticesize/10;

    int stable_time = stability(config, partition_size, Particles, Cells);

    start(config, Cells, Particles);

    std::mt19937 gen(config.seed);
    std::uniform_int_distribution<int> dis_move(0, 1);
    std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1);
  
    double Dropsize = 0;
    int random_particle = 0, step = 0, direction = 0;

    config.tmax = config.tmax*config.latticesize*config.latticesize/10;

    std::ofstream sizefile_1;   //Salida de entropia
    sizefile_1.open("Data/data_dropsize_1.txt");
  
    for(int t = 0; t < stable_time; t++ ){

        random_particle = dis_particle(gen);       
        step = dis_move(gen)*2 - 1;  
        direction = dis_move(gen); 
    
        time_step(config, random_particle, step, direction, Cells, Particles);
        
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
    
        time_step(config, random_particle, step, direction, Cells, Particles);
        
        if (t%config.resolution == 0){
        
            Dropsize = dropsize (config, Particles);
            sizefile_2 << t << "\t"
                     << Dropsize << "\n";

        }
    }

    sizefile_2.close();
    
    return 0;
}
