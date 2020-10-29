#include "header.h"

int Particle::Getcell(const CONFIG &config){

    int X = (position[0] + config.latticesize/2)*config.gridsize/config.latticesize;
    int Y = (position[1] + config.latticesize/2)*config.gridsize/config.latticesize;

    return X + Y*config.gridsize;
}

void Particle::Move(int step, int direction, const CONFIG &config){

    if (labs(position[direction] + step) != config.latticesize/2 + (1 - step)/2){

        position[direction] += step;

    }

}

void Particle::Move_hole(int step, int direction, const CONFIG &config){
    
     if (labs(position[direction] + step) != config.latticesize/2 + (1 - step)/2){

        position[direction] += step;

     }

     if(position[0] == (config.latticesize-2)/2 && labs(position[1]) <= config.latticesize/2.5){
         position[0] += 2;
     }
}
