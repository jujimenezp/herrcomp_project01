#include "coffee_random.h"

int main(int argc, char *argv[])
{

    int n = atoi(argv[1]);
    int cell_size = atoi(argv[2]);
    int grid_size = atoi(argv[3]);
    int cell_quantity = 2*grid_size/cell_size;
 
    std::vector <particle> Particles (4*n*n);
    std::vector <int> Cells (cell_quantity*cell_quantity);
    std::vector <double> Entropy (cell_quantity*cell_quantity);

    init_particles(n, Particles);
    init_cells(4*n*n, cell_size, grid_size, Particles, Cells);
    double total_entropy = init_entropy(4*n*n, cell_size, grid_size, Cells, Entropy);

    for(int i = 0; i < cell_quantity; i++){
        for (int j = 0; j < cell_quantity; j++){

            std::cout << Entropy.operator[](i + j*cell_quantity) << "\t";

        }

        std::cout << "\n";
    }

    total_entropy = std::log(4*n*n) - total_entropy/(4.0*n*n);

    std::cout << "\nEntropy = " << total_entropy;
    
    return 0;
}
