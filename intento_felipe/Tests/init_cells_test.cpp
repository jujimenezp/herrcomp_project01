#include "../Functions/coffee_random.h"

int main()
{

    int mol_number = 15;
    int grid_size = 100;
    int cell_size = 25;
    int N = 4*mol_number*mol_number;
    int cell_quantity = 2*grid_size/cell_size;
 
    std::vector <particle> Particles (N);
    std::vector <int> Cells (cell_quantity*cell_quantity);

    init_particles(mol_number, Particles);
    init_cells(N, grid_size, cell_size, Particles, Cells);

    for (int i = 0; i < cell_quantity; i++){
        
        for (int j = 0; j < cell_quantity; j++){

            std::cout << Cells[i + j*cell_quantity] << "\t";

        }

        std::cout << "\n";
    }
    
    return 0;
}
