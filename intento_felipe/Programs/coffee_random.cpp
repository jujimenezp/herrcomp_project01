#include "../Functions/coffee_random.h"

int main ()
{
    
    int mols_number, grid_size, cells_number, iterations, seed;

    get_data (mols_number, grid_size, cells_number, iterations, seed);

    std::vector <particle> Particles (mols_number);
    std::vector <int> Cells (cells_number*cells_number);
    std::vector <double> Entropy (cells_number*cells_number);

    init_particles (mols_number, Particles);

    distribution (mols_number, Particles, "distribution_start");

    init_cells (mols_number, grid_size, cells_number,
                Particles, Cells);

    double pre_entropy = init_entropy (grid_size, cells_number,
                                       Cells, Entropy);
    
    time_steps (mols_number, grid_size, cells_number,
                iterations, seed, pre_entropy,
                Particles, Cells, Entropy);

    distribution (mols_number, Particles, "distribution_end");
    
    return 0;
}
