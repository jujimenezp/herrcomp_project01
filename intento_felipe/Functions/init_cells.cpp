#include "coffee_random.h"

void init_cells(int N, int grid_size, int cell_size, std::vector<particle> &Particles, std::vector<int> &Cells){

    int m;
    
    for(int i = 0; i < N; i++){

        m = Particles.operator[](i).get_cell(grid_size, cell_size);
        
        Cells[m] += 1;

    }
    
}
