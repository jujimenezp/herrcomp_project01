#include "header.h"

int stability (const CONFIG &config, const int partition_size, Vec_p &Particles, Vec_i &Cells){

    std::mt19937 gen(config.seed);
    std::uniform_int_distribution<int> dis_move(0, 1);
    std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1);
    
    int random_particle = 0, step = 0, direction = 0, t = 0, j = 0;
    
    int counter = 0;
    double eps = 0.005;
    
    double Times [partition_size];
    Times[0] = (partition_size-1)*config.resolution;
    for (int i = 1; i < partition_size; i++) Times[i] = (i-1)*config.resolution;
    
    double Entropies[partition_size];

    double c0 = 0, c1 = 0, cv00 = 0, cv01 = 0, cv11 = 0, s = 0, deviation = 0;

    while (counter < 1){

        t += 1;  

        random_particle = dis_particle(gen);
        step = dis_move(gen)*2 - 1; 
        direction = dis_move(gen);
    
        Particles[random_particle].Move(step, direction, config, Cells);
        
        if (t%config.resolution == 0){

            j = t/config.resolution;

            Entropies[j%partition_size] = entropy(config, Cells);

            if (j%partition_size == 0){

                gsl_fit_linear(Times, 1, Entropies, 1, partition_size, &c0, &c1, &cv00, &cv01, &cv11, &s);

                deviation = std::abs(c1)*Times[0]/c0;
                
                if (deviation < eps) counter = 1;

            }

        }
        
    }

    return t - (partition_size -1)*config.resolution/2;
    
}
