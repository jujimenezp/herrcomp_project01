#include "coffee_random.h"
#include <string>
#include <fstream>

int main(){

    int mol_number, grid_size, cell_size, iterations, seed;

    get_data (mol_number, grid_size, cell_size, iterations, seed);

    std::cout << mol_number << "\n";
    std::cout << grid_size << "\n";
    std::cout << cell_size << "\n";
    std::cout << iterations << "\n";
    std::cout << seed << "\n";
      
    return 0; 

}
