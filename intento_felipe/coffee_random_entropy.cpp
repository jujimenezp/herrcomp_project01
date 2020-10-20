#include "coffee_random.h"

int main (void)
{
    
    int mol_number, grid_size, cell_size, iterations, seed;

    double pre_entropy, total_entropy;

    get_data (mol_number, grid_size, cell_size, iterations, seed);

    int cell_quantity = 2*grid_size/cell_size;

    std::vector <particle> Particles (4*mol_number*mol_number);
    std::vector <int> Cells (cell_quantity*cell_quantity);
    std::vector <double> Entropy (cell_quantity*cell_quantity);

    init_particles (mol_number, Particles);

    init_cells (4*mol_number*mol_number, cell_size, grid_size, Particles, Cells);

    pre_entropy = init_entropy (4*mol_number*mol_number, cell_size, grid_size, Cells, Entropy);
    
    total_entropy = time_entropy (4*mol_number*mol_number, cell_size, grid_size, iterations, seed, pre_entropy, Particles, Cells, Entropy);
    
    return 0;
}
