#include "coffee_random.h"

int particle::get_x(void){

    return position[0];

}

int particle::get_y(void){

    return position[1];

}

int particle::get_cell(int grid_size, int cell_size){
    
    int X = (position[0] - (1 - (1 + (int)std::copysign(1.0, position[0]))/2)*(cell_size-1))/cell_size + grid_size/cell_size;
    int Y = (position[1] - (1 - (1 + (int)std::copysign(1.0, position[1]))/2)*(cell_size-1))/cell_size + grid_size/cell_size;

    return X + Y*2*grid_size/cell_size;
}
        
void particle::locate(int x, int y){

    position[0] = x;

    position[1] = y;

}
        
void particle::move(int q, int p, int grid_size){

    position[q] += p;

    if (std::abs(position[q]) == grid_size + (1 - p)/2){

        position[q] -= p;

    }
    
}
