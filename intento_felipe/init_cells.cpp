#include "coffee_random.h"

void init_cells(int N, int cell_size, int grid_size, std::vector<particle> &Particles, std::vector<int> &Cells){

    int m;
    
    for(int i = 0; i < N; i++){

        m = Particles.operator[](i).get_cell(cell_size, grid_size);
        
        Cells.operator[](m) += 1;

    }
    
}
