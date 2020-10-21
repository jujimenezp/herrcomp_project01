#include "coffee_random.h"

void init_particles(int mol_number, std::vector<particle> &Particles){

    for(int i = 0; i < 2*mol_number; i++){
        
        for(int j = 0; j < 2*mol_number; j++){

            Particles[i + j*2*mol_number].locate(i - mol_number, j - mol_number);
            
        }
        
    }

}
