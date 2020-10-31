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
  
    double Entropy = 0;
    int random_particle = 0, step = 0, direction = 0, j = 0;

    const int n = config.latticesize*config.latticesize/10;
    int counter_1 = 0, counter_2 = 0, counter_12 = 0;
    double eps_1 = 0.005;
    double eps_2 = 0.003;
    
    double Times [n];

    Times[0] = (n-1)*config.resolution;

    for (int i = 1; i < n; i++) Times[i] = (i-1)*config.resolution;
    
    double Entropies[n];

    double mean = 0, dev = 0, ab_dev = 0;

    double coff = 0, c0 = 0, c1 = 0, cv00 = 0, cv01 = 0, cv11 = 0, s;

    std::ofstream file;
    file.open("Data/data_stability_test.txt");

    for (int t = 1; t <= config.tmax*n; t++){

        random_particle = dis_particle(gen);
        step = dis_move(gen)*2 - 1; 
        direction = dis_move(gen);
    
        time_step(config, random_particle, step, direction, Cells, Particles);

        if (t%config.resolution == 0){

            j = t/config.resolution;

            Entropies[j%n] = entropy(config, Cells);

            if (j%n == 0){

                mean = gsl_stats_mean(Entropies, 1, n);
                dev = gsl_stats_sd_m(Entropies, 1, n, mean);
                gsl_fit_linear(Times, 1, Entropies, 1, n, &c0, &c1, &cv00, &cv01, &cv11, &s);
                
                if (std::abs(c1)*Times[0]/c0 < eps_1) counter_1 += 1;
                if (dev/mean < eps_2) counter_2 += 1;
                if (std::abs(c1)*Times[0]/c0 < eps_1 && dev/mean < eps_2) counter_12 += 1; 

                file << t - (n-1)*config.resolution/2  << "\t"
                     << std::abs(c1)*Times[0]/c0 << "\t"
                     << dev/mean << "\t"
                     << counter_1 << "\t"
                     << counter_2 << "\t"
                     << counter_12 << "\n";

            }

        }
 
    }

    file.close();
  
    return 0;
}
