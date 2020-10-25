#include "header.h"

void start(const CONFIG &object, Vec_i &Cells, Vec_p &Particles){
    
    int n = std::sqrt(object.nmolecules);
    int m =0 ;
    
    //inicializa las particulas en un cuadrado (revisar cambio por auto)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            Particles[i + j*n].position[0] = i - n/2;
            Particles[i + j*n].position[1] = j - n/2;
            
        }
    }
    //calcula las particulas en cada celda
    for(int i = 0; i < object.nmolecules; i++){
        
        m = Particles[i].Getcel(object);
        Cells[m] += 1;
        
    }
    
}

