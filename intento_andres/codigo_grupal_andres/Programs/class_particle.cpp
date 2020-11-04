#include "header.h"

int Particle::Getcell(const CONFIG &config){

    int X = (position[0] + config.latticesize/2)*config.gridsize/config.latticesize;
    int Y = (position[1] + config.latticesize/2)*config.gridsize/config.latticesize;

    return X + Y*config.gridsize;
}

void Particle::Move(const int &step, const int &direction, const CONFIG &config, std::vector<int> &Cells)
{
  if (labs(position[direction] + step) != config.latticesize/2 + (1 - step)/2){
    int m = Getcell(config);
    Cells[m] -= 1; //delete it from the old cell
    
    position[direction] += step; //move the particle
    
    m = Getcell(config);
    Cells[m] += 1; //add it to the new cell
  } 
}

void Particle::Move_hole(const int &step, const int &direction, const int &particle_id, const CONFIG &config, std::vector<int> &Cells, std::vector<Particle> &Particles)
{
  int moved_particle_cell = Particles[particle_id].Getcell(config);
  
  if (labs(position[direction] + step) != config.latticesize/2 + (1 - step)/2){ //the particle is not on the limit after moving
    Cells[moved_particle_cell] -= 1; //delete it form old-cell count
    
    position[direction] += step; //move the particle
    
    moved_particle_cell = Particles[particle_id].Getcell(config);
    Cells[moved_particle_cell] += 1; //add it to new-cell count
  }
  else if (direction + step == config.holeposition && labs(position[(direction+1)%2]) <= config.holesize/2){ //makes sure the particle moved towards the hole and that it can get out
    Cells[moved_particle_cell] -= 1; //delete the particle from the cell count
    Particles[particle_id] = Particles[Particles.size() - 1];
    Particles.pop_back(); //delete the particle
  }
   
}
