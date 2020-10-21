#include "coffee_random.h"

double time_steps (int N, int grid_size, int cell_size, int iterations, int seed, double total_entropy, std::vector<particle> &Particles, std::vector<int> &Cells, std::vector<double> &Entropy){

    int cell_quantity = 2*grid_size/cell_size;

    
    std::ofstream file;

    file.open("../Data/entropy_data.txt");
    

    std::mt19937 gen(seed);
    
    std::uniform_int_distribution<int> dis_move(0, 1);
    
    std::uniform_int_distribution<int> dis_particle(0, N-1);
    

    file << "0" << "\t" << total_entropy << "\n";


    int j, q, p, old_cell, new_cell;

    for (int i = 0; i < iterations; i++){

        j = dis_particle(gen);

        old_cell = Particles[j].get_cell(grid_size, cell_size);
        
        q = dis_move(gen);
        p = dis_move(gen)*2 - 1;

        Particles[j].move(q ,p ,grid_size);

        new_cell = Particles[j].get_cell(grid_size, cell_size);

        if (old_cell != new_cell){

            total_entropy = entropy_step (old_cell, new_cell, N, cell_quantity, Cells, Entropy);
            
        }
        
        file << i+1 << "\t" << total_entropy << "\n";

    }

    return total_entropy;

}
