#include "header.h"

int main(void)
{

    CONFIG config;
    config.read("Data/init_data.txt");

    Vec_p Particles(config.nmolecules);
    Vec_i Cells(config.gridsize*config.gridsize,0);
  
    start(config, Cells, Particles);

    std::mt19937 gen(config.seed);
    std::uniform_int_distribution<int> dis_move(0, 1);
    std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1);
    
    int random_particle = 0, step = 0, direction = 0, t = 0, j = 0;

    const int partition_size = config.latticesize*config.latticesize/10;
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
    
        time_step(config, random_particle, step, direction, Cells, Particles);

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


    //std::ofstream file;
    //file.open("Data/data_stability.txt");
    //file.close();

    std::cout << c0 << "\t" << cv00 << "\t"
              << t - (partition_size -1)*config.resolution/2 << "\t" << (partition_size -1)*config.resolution/2 << "\n";
  
    return 0;
}
