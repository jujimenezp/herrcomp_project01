#include "header.h"

int main (void){

    int j = 0, q = 0, p = 0;

    double Entropy = 0;

    CONFIG config;
    config.read("Data/init_data.txt");

    std::mt19937 gen(config.seed);
    std::uniform_int_distribution<int> dis_move(0, 1);
    std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1);

    Vec_p Particles(config.nmolecules);
    Vec_i Cells(config.gridsize*config.gridsize,0);

    start(config, Cells, Particles);

    for (int t = 0; t <= config.tmax; t++){

        j = dis_particle(gen);        //escoge una particula al azar
        q = dis_move(gen);           //genera un numero aleatorio 0 o 1 (0 para x 1 para y)
        p = dis_move(gen)*2 - 1;    //genera un numero aleatorio 1 o -1 (1: arriba o derecha -1:abajo o izquierda)
        
        time_step(config, j, q, p, Cells, Particles);

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
