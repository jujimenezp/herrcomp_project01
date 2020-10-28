#include "header.h"

void start(const CONFIG &config, Vec_i &Cells, Vec_p &Particles)
{
    int n = std::sqrt(config.nmolecules);
    int m = 0;
    
    for(int i = 0; i < config.nmolecules; i++){
        //inicializa las particulas en un cuadrado
        Particles[i].position[0] = i%n - n/2;
        Particles[i].position[1] = i/n - n/2;
        //calcula las particulas en cada celda
        m = Particles[i].Getcell(config);
        Cells[m] += 1;
    }
    
}

    /*
    int j = 0;

    for (auto p: Particles){

        std::cout << p.position[0] << "\t"
                  << p.position[1] << "\n";

        p.position[0] = j%n - n/2;
        p.position[1] = j/n - n/2;

        m = p.Getcel(object);
        Cells[m] += 1;

        j += 1;
    }*/
    


