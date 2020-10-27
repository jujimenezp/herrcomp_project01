#include "header.h"

void start(const CONFIG &object, Vec_i &Cells, Vec_p &Particles){
    
    int n = std::sqrt(object.nmolecules);
    int m = 0;
    
    //inicializa las particulas en un cuadrado
    //calcula las particulas en cada celda
    
    for (int i = 0; i < object.nmolecules; i++){

        Particles[i].position[0] = i%n - n/2;
        Particles[i].position[1] = i/n - n/2;

        m = Particles[i].Getcel(object);
        Cells[m] += 1;
        
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
    
}

