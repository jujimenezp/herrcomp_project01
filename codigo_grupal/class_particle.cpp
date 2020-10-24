#include "header.h"

int Particle::Getcel (const CONFIG &object){

    int X = (position[0] + object.latticesize/2)*object.gridsize/object.latticesize;
    int Y = (position[1] + object.latticesize/2)*object.gridsize/object.latticesize;

    return X + Y*object.gridsize;
}

void Particle::Move(int p, int q, const CONFIG &object){

    if (labs(position[q] + p) != object.latticesize/2 + (1 - p)/2){

        position[q] += p;

    }

}



