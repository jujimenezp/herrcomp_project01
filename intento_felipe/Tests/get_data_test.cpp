#include "../Functions/coffee_random.h"

int main(void){

    int mols_number, grid_size, cells_number, iterations, seed;

    get_data (mols_number, grid_size, cells_number, iterations, seed);

    std::cout << "\nmols_number\t" << mols_number << "\n";
    std::cout << "grid_size\t" << grid_size << "\n";
    std::cout << "cells_number\t" << cells_number << "\n";
    std::cout << "iterations\t" << iterations << "\n";
    std::cout << "seed\t" << seed << "\n\n";
      
    return 0; 

}
