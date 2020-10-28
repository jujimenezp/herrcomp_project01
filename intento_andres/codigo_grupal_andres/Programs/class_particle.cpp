#include "header.h"

int Particle::Getcell(const CONFIG &config){

    int X = (position[0] + config.latticesize/2)*config.gridsize/config.latticesize;
    int Y = (position[1] + config.latticesize/2)*config.gridsize/config.latticesize;

    return X + Y*config.gridsize;
}

void Particle::Move(const int &step, const int &direction, const CONFIG &config);

  if (labs(position[direction] + step) != config.latticesize/2 + (1 - step)/2){
    
    position[direction] += step;
    
  }
  
}

void Particle::Move_hole(const int &step, const int &direction, const int &particle_id, const CONFIG &config, Vec_p &Particles){

  if (labs(position[direction] + step) != config.latticesize/2 + (1 - step)/2){
    
    position[direction] += step;
    
  }
  else if (direction == 0 && config.holeposition == step + 1){ //verify if the particle moved in the direction of the hole
    int sign = (position[1] > 0) ? 1 : ((position[1] < 0) ? -1 : 0);
    
    if (labs(position[1]) <= config.holesize/2 - ((sign+1)/2)){ //the particle is actually on the hole
      Particle end = Particles[Particles.size()];
      Particles[Particles.size()] = Particles[Particle_id];
      Particles[Particle_id] = end;
      Particles.resize(Particles.size() - 1); //delete the particle
    }
    
  }
  else if (direction == 1 && config.holeposition == -step + 2){ //verify if the particle moved in the direction of the hole
    int sign = (position[0] > 0) ? 1 : ((position[0] < 0) ? -1 : 0);
    
    if (labs(position[0]) <= config.holesize/2 - ((sign+1)/2)){ //the particle is actually on the hole
      Particle end = Particles[Particles.size()];
      Particles[Particles.size()] = Particles[Particle_id];
      Particles[Particle_id] = end;
      Particles.resize(Particles.size() - 1); //delete the particle
    }
    
  }

}
