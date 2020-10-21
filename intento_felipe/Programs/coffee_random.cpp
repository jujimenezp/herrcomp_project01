#include "../Functions/coffee_random.h"

int main ()
{
    
    int mol_number, grid_size, cell_size, iterations, seed;

    get_data (mol_number, grid_size, cell_size, iterations, seed);

    int N = 4*mol_number*mol_number;
    int cell_quantity = 2*grid_size/cell_size;

    std::vector <particle> Particles (N);
    std::vector <int> Cells (cell_quantity*cell_quantity);
    std::vector <double> Entropy (cell_quantity*cell_quantity);

    init_particles (mol_number, Particles);

    init_cells (N, grid_size, cell_size, Particles, Cells);

    double total_entropy = init_entropy (N, grid_size, cell_size, Cells, Entropy);
    
    total_entropy = time_steps (N, grid_size, cell_size, iterations, seed, total_entropy, Particles, Cells, Entropy);

    distribution (N, grid_size, cell_size, Particles);
    
    return 0;
}
