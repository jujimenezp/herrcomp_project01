#include "../Functions/coffee_random.h"

int main(void)
{

    int mols_number = 400;
    int grid_size = 200;
    int cells_number = 8;
 
    std::vector <particle> Particles (mols_number);
    std::vector <int> Cells (cells_number*cells_number);

    init_particles(mols_number, Particles);
    init_cells(mols_number, grid_size, cells_number, Particles, Cells);

    for (int i = 0; i < cells_number; i++){
        
        for (int j = 0; j < cells_number; j++){

            std::cout << Cells[i + j*cells_number] << "\t";

        }

        std::cout << "\n";
    }
    
    return 0;
}
