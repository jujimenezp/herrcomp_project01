#include "coffee_random.h"

int particle::get_x(void){

    return position[0];

}

int particle::get_y(void){

    return position[1];

}

int particle::get_cell(int cell_size, int grid_size){

    int X = 0, Y = 0;

    X = (position[0] - (1 - (1 + (int)std::copysign(1.0, position[0]))/2)*(cell_size-1))/cell_size + grid_size/cell_size;
    Y = (position[1] - (1 - (1 + (int)std::copysign(1.0, position[1]))/2)*(cell_size-1))/cell_size + grid_size/cell_size;

    cell = X + Y*2*grid_size/cell_size;

    return cell;
}
        
void particle::locate(int x, int y){

    position[0] = x;

    position[1] = y;

}
        
void particle::move(int q, int p, int grid_size){

    position[q] += p;

    if (std::abs(position[0]) == grid_size + (1 - (int)std::copysign(1.0,position[0]))/2){

        position[0] -= (int)std::copysign(1.0,position[0]);

    }

    if (std::abs(position[1]) == grid_size + (1 - (int)std::copysign(1.0,position[1]))/2){

        position[1] -= (int)std::copysign(1.0,position[1]);

    }
    
}
