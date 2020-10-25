#include "coffee_random.h"

int particle::get_cell (int grid_size,int cells_number){
    
    int X = (position[0] + grid_size/2)*cells_number/grid_size;
    int Y = (position[1] + grid_size/2)*cells_number/grid_size;

    return X + Y*cells_number;
}

/*

-L-1,L    0, 2L

*/
void particle::move(int q, int p,int grid_size){

    if (labs(position[q] + p) != grid_size/2 + (1 - p)/2){

        position[q] += p;

    }
    
}
