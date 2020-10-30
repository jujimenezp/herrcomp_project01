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
    int random_particle = 0, step = 0, direction = 0, t = 0, j = 0;

    const int n = 100000;
    //int counter = 0, counter_max = 10;
    double eps = 0.005;

    Vec_i Times (n,0);
    double times [n];

    times[0] = (n-1)*config.resolution;

    for (int i = 1; i < n; i++) times[i] = (i-1)*config.resolution;
    
    double Entropies[n];

    double mean = 0, dev = 0;

    double coff = 0, c0 = 0, c1 = 0, cv00 = 0, cv01 = 0, cv11 = 0, s;

    std::ofstream file;
    file.open("Data/data_stability.txt");

    for (t = 1; t <= config.tmax; t++){

        random_particle = dis_particle(gen);
        step = dis_move(gen)*2 - 1; 
        direction = dis_move(gen);
    
        time_step(config, random_particle, step, direction, Cells, Particles);

        if (t%config.resolution == 0){

            j = t/config.resolution;

            Times[j%n] = t;

            Entropies[j%n] = entropy(config, Cells);

            if (j%n == 0){

                //mean = gsl_stats_mean(Entropies, 1, n);
                //dev = gsl_stats_absdev_m(Entropies, 1, n, mean);

                coff = gsl_stats_correlation(times, 1, Entropies, 1, n);

                gsl_fit_linear(times, 1, Entropies, 1, n, &c0, &c1, &cv00, &cv01, &cv11, &s);

                file << Times[(n-1)/2]  << "\t" << coff << "\t"
                     << std::abs(c1) << "\t" << c0 << "\n";

            }

        }

            
    }

    file.close();

    //std::cout << mean << "\t" << Times[n/2] << "\n";
  
    return 0;
}

    

/*

  int counter = 0, counter_max = config.tmax/config.resolution;
  double eps = 1;
  
  while (counter < counter_max){

  random_particle = dis_particle(gen);
  step = dis_move(gen)*2 - 1; 
  direction = dis_move(gen);
    
  time_step(config, random_particle, step, direction, Cells, Particles);

  if (t%config.resolution == 0){

  Entropy_change = -Entropy;
            
  Entropy = entropy(config, Cells);

  Entropy_change += Entropy;

  if ( std::abs(Entropy_change/Entropy) < eps) counter += 1;

  }

  t += 1;
        
  }

*/
