#include "coffee_random.h"

void time_steps (int mols_number, int grid_size, int cells_number,
                   int iterations, int seed, double pre_entropy,
                   std::vector<particle> &Particles, std::vector<int> &Cells, std::vector<double> &Entropy){

    std::mt19937 gen(seed);
    
    std::uniform_int_distribution<int> dis_move(0, 1);
    
    std::uniform_int_distribution<int> dis_particle(0, mols_number-1);
    

    std::cout << "0" << "\t" << std::log(mols_number) - pre_entropy/mols_number << "\n";


    int j, q, p, old_cell, new_cell;

    for (int i = 0; i < iterations; i++){

        j = dis_particle(gen);

        old_cell = Particles[j].get_cell(grid_size, cells_number);
        
        q = dis_move(gen);
        p = dis_move(gen)*2 - 1;

        Particles[j].move(q ,p ,grid_size);

        new_cell = Particles[j].get_cell(grid_size, cells_number);

        if (old_cell != new_cell){

            pre_entropy = entropy_step (old_cell, new_cell, pre_entropy, Cells, Entropy);
            
        }
        
        std::cout << i+1 << "\t" << std::log(mols_number) - pre_entropy/mols_number << "\n";

    }

}
