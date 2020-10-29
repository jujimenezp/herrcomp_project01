#include "header.h"

void time_step(const CONFIG &config, int random_particle, int step, int direction, Vec_i &Cells, Vec_p &Particles){

    int m = 0;

    m = Particles[random_particle].Getcell(config);
    Cells[m] -= 1;
    Particles[random_particle].Move(step,direction,config);
    m = Particles[random_particle].Getcell(config);
    Cells[m] += 1;        
}

void time_step_hole(const CONFIG &config, int random_particle, int step, int direction, Vec_i &Cells, Vec_p &Particles){

    int m = 0;

    m = Particles[random_particle].Getcell(config);
    Cells[m] -= 1;
    Particles[random_particle].Move_hole(step,direction,config);
    
    if(Particles[random_particle].position[0] == (config.latticesize+2)/2){
        Vec_p::iterator a = Particles.begin() + random_particle;
        Particles.erase(a);
    }
    
    else{
    m = Particles[random_particle].Getcell(config);
    Cells[m] += 1;
    }
}
