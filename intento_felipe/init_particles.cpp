#include "coffee_random.h"

void init_particles(int n, std::vector<particle> &Particles){

    for(int ix = 0; ix < 2*n; ix++){
        for(int iy = 0; iy < 2*n; iy++){

            Particles.operator[](ix + iy*2*n).locate(ix - n, iy - n);
            
        }
        
    }

}
