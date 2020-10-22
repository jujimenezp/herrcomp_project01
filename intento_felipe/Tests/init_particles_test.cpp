#include "../Functions/coffee_random.h"

int main(void)
{

    int mol_number = 15;
    int grid_size = 100;
    int cell_size = 25;
    int N = 4*mol_number*mol_number;
 
    std::vector <particle> Particles (N);

    init_particles(mol_number, Particles);

    distribution (N, grid_size, cell_size, Particles);
    
    return 0;
}
