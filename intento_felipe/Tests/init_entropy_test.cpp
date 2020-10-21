#include "../Functions/coffee_random.h"

int main()
{

    int mol_number = 10;
    int grid_size = 100;
    int cell_size = 25;
    int N = 4*mol_number*mol_number;
    int cell_quantity = 2*grid_size/cell_size;
 
    std::vector <particle> Particles (N);
    std::vector <int> Cells (cell_quantity*cell_quantity);
    std::vector <double> Entropy (cell_quantity*cell_quantity);

    init_particles(mol_number, Particles);
    init_cells(N, grid_size, cell_size, Particles, Cells);
    double total_entropy = init_entropy(N, grid_size, cell_size, Cells, Entropy);

    for(int i = 0; i < cell_quantity; i++){
        
        for (int j = 0; j < cell_quantity; j++){

            std::cout << Entropy[i + j*cell_quantity] << "\t";

        }

        std::cout << "\n";
    }

    std::cout << "\nEntropy = " << total_entropy;
    
    return 0;
}
