#include "../Functions/coffee_random.h"

int main(void)
{
    int mol_number = 10;
    int grid_size = 100;
    int cell_size = 25;
    int seed = 0;
    int cell_quantity = 2*grid_size/cell_size;
    int N = 4*mol_number*mol_number;

    std::vector <particle> Particles (N);
    std::vector <int> Cells (cell_quantity*cell_quantity);
    std::vector <double> Entropy (cell_quantity*cell_quantity);

    std::mt19937 gen(seed);
    
    std::uniform_int_distribution<int> dis_move(0, 1);
    
    std::uniform_int_distribution<int> dis_particle(0, N - 1);
    
    std::uniform_int_distribution<int> dis_location(-grid_size, grid_size - 1);

    int x, y;

    for (int i = 0; i < N; i++){

        x = dis_location(gen);
        y = dis_location(gen);

        Particles[i].locate (x, y);

    }

    
    init_cells (N, grid_size, cell_size, Particles, Cells);
    
    double total_entropy = init_entropy (N, grid_size, cell_size, Cells, Entropy);

    int j = dis_particle(gen);

    int old_cell = Particles[j].get_cell (grid_size, cell_size);

    for (int i = 0; i < cell_size; i++){

        Particles[j].move(1, -(int)std::copysign (1.0, Particles[j].get_y()), grid_size);

    }

    int new_cell = Particles[j].get_cell (grid_size, cell_size);

    std::cout << "\nOld cell particles \t" << Cells[old_cell] << "\n";
    std::cout << "Old cell pre-entropy \t" << Entropy[old_cell] << "\n";
    std::cout << "New cell particles \t" << Cells[new_cell] << "\n";
    std::cout << "New cell pre-entropy \t" << Entropy[new_cell] << "\n";
    std::cout << "Total entropy \t" << total_entropy << "\n";
    
    std::cout << "La función se ejecuta... \n\n";

    total_entropy = entropy_step (old_cell, new_cell, N, cell_quantity, Cells, Entropy);
    
    std::cout << "\nOld cell particles \t" << Cells[old_cell] << "\n";
    std::cout << "Old cell pre-entropy \t" << Entropy[old_cell] << "\n";
    std::cout << "New cell particles \t" << Cells[new_cell] << "\n";
    std::cout << "New cell pre-entropy \t" << Entropy[new_cell] << "\n";
    std::cout << "Total entropy \t" << total_entropy << "\n";

    return 0;
    
}

