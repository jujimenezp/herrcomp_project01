#include "../Functions/coffee_random.h"

int main(void)
{
    int mols_number = 400;
    int grid_size = 200;
    int cells_number = 8;
    int seed = 5;

    std::vector <particle> Particles (mols_number);
    std::vector <int> Cells (cells_number*cells_number);
    std::vector <double> Entropy (cells_number*cells_number);

    std::mt19937 gen(seed);
    
    std::uniform_int_distribution<int> dis_move(0, 1);
    
    std::uniform_int_distribution<int> dis_particle(0, mols_number - 1);
    
    std::uniform_int_distribution<int> dis_location(-grid_size/2, grid_size/2 - 1);

    int x, y;

    for (int i = 0; i < mols_number; i++){

        x = dis_location(gen);
        y = dis_location(gen);

        Particles[i].position[0] = x;
        Particles[i].position[1] = y;

    }

    
    init_cells (mols_number, grid_size, cells_number, Particles, Cells);
    
    double pre_entropy = init_entropy (grid_size, cells_number, Cells, Entropy);

    int j = dis_particle(gen);

    Particles[j].position[0] = -grid_size/cells_number;

    int old_cell = Particles[j].get_cell (grid_size, cells_number);

    Particles[j].position[0] = grid_size/cells_number;

    int new_cell = Particles[j].get_cell (grid_size, cells_number);

    std::cout << "\nOld cell particles \t" << Cells[old_cell] << "\n"
              << "Old cell pre-entropy \t" << Entropy[old_cell] << "\n"
              << "New cell particles \t" << Cells[new_cell] << "\n"
              << "New cell pre-entropy \t" << Entropy[new_cell] << "\n"
              << "Total pre-entropy \t" << pre_entropy << "\n"
              << "Total entropy \t" << std::log(mols_number) - pre_entropy/mols_number << "\n\n";
    
    std::cout << "La función se ejecuta... \n";

    pre_entropy = entropy_step (old_cell, new_cell, pre_entropy, Cells, Entropy);
    
    std::cout << "\nOld cell particles \t" << Cells[old_cell] << "\n"
              << "Old cell pre-entropy \t" << Entropy[old_cell] << "\n"
              << "New cell particles \t" << Cells[new_cell] << "\n"
              << "New cell pre-entropy \t" << Entropy[new_cell] << "\n"
              << "Total pre-entropy \t" << pre_entropy << "\n"
              << "Total entropy \t" << std::log(mols_number) - pre_entropy/mols_number << "\n\n";

    return 0;
    
}

