#include "../Functions/coffee_random.h"

int main(){

    int mol_number, grid_size, cell_size, iterations, seed;

    get_data (mol_number, grid_size, cell_size, iterations, seed);

    std::cout << "\nmol_number\t" << mol_number << "\n";
    std::cout << "grid_size\t" << grid_size << "\n";
    std::cout << "cell_size\t" << cell_size << "\n";
    std::cout << "iterations\t" << iterations << "\n";
    std::cout << "seed\t" << seed << "\n\n";
      
    return 0; 

}
