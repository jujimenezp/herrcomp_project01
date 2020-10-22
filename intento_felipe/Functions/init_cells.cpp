#include "coffee_random.h"

void init_cells(int mols_number, int grid_size, int cells_number,
                std::vector<particle> Particles, std::vector<int> &Cells){

    int m;
    
    for(int i = 0; i < mols_number; i++){

        m = Particles[i].get_cell(grid_size, cells_number);
        
        Cells[m] += 1;

    }
    
}
