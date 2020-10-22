#include "coffee_random.h"

void init_particles(int mols_number, std::vector<particle> &Particles){

    int n = std::sqrt(mols_number);

    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < n; j++){

            Particles[i + j*n].position[0] = i - n/2;
            Particles[i + j*n].position[1] = j - n/2;
            
        }
        
    }

}
