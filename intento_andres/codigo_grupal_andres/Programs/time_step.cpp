#include "header.h"

void time_step(const int &time, const CONFIG &config, int random_particle, int step, int direction, Vec_i &Cells, Vec_p &Particles){

    int m = 0;

    if (config.holeboolean == 0){
      m = Particles[random_particle].Getcell(config);
      Cells[m] -= 1;
      Particles[random_particle].Move(step,direction,config);
      m = Particles[random_particle].Getcell(config);
      Cells[m] += 1;
    }
    else {
      Particles[random_particle].Move_hole(time, step, direction, random_particle, config, Cells, Particles);
    }

}
