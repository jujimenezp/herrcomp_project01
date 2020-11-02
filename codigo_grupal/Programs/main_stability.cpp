#include "header.h"

int main(void)
{

    CONFIG config;
    config.read("Data/init_data.txt");

    Vec_p Particles(config.nmolecules);
    Vec_i Cells(config.gridsize*config.gridsize,0);
  
    start(config, Cells, Particles);

    const int partition_size = config.latticesize*config.latticesize/10;

    int stable_time = 0;

    for (int i = 0; i < 10; i++){

        config.seed += i;

      stable_time += stability(config, partition_size, Particles, Cells)/10;  

    }

    std::cout << config.latticesize << "\t"
              << stable_time << "\t" << (partition_size -1)*config.resolution/2 << "\n";
  
    return 0;
}
