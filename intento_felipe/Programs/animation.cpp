#include "header.h"

int main (void){

    CONFIG config;
    config.read("Data/init_data.txt");

    Vec_p Particles(config.nmolecules);
    Vec_i Cells(config.gridsize*config.gridsize,0);
  
    start(config, Cells, Particles);

    std::mt19937 gen(config.seed);
    std::uniform_int_distribution<int> dis_move(0, 1);
    std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1);
  
    double Entropy = 0;
    int random_particle = 0, step = 0, direction = 0;

    for (int t = 0; t <= config.tmax; t++){

        random_particle = dis_particle(gen);       
        step = dis_move(gen);      
        direction = dis_move(gen)*2 - 1;  
        
        time_step(config, random_particle, step, direction, Cells, Particles);

        if (t%config.resolution == 0){

            std::string fname = "Data/Animation/data-" + std::to_string(t/config.resolution) + ".csv";

            std::ofstream file;
            file.open(fname);
    
            for (auto p: Particles){
        
                file << 1.0*p.position[0] + 0.5 << ","
                     << 1.0*p.position[1] + 0.5 << "\n";
        
            }

        }
        
    }
    
    return 0;
}
