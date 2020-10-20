#include "coffee_random.h"

double time_distribution (int N, int cell_size, int grid_size, int iterations, int seed, double pre_entropy, std::vector<particle> &Particles, std::vector<int> &Cells, std::vector<double> &Entropy){

    std::mt19937 gen(seed);
    
    std::uniform_int_distribution<int> dis_move(0, 1);
    
    std::uniform_int_distribution<int> dis_particle(0, N-1);

    int cell_quantity = 2*grid_size/cell_size;

    int j, m, q, p;

    double total_entropy;

    for (int i = 0; i < iterations; i++){

        j = dis_particle(gen);

        m = Particles.operator[](j).get_cell(cell_size, grid_size);
        
        Cells.operator[](m) -= 1;

        Entropy.operator[](m) = Cells.operator[](m)*std::log(Cells.operator[](m));

            if (Cells.operator[](m) == 0){

                Entropy.operator[](m) = 0;

            }
            
        q = dis_move(gen);
        p = dis_move(gen)*2 - 1;

        Particles.operator[](j).move(q ,p ,grid_size);

        m = Particles.operator[](j).get_cell(cell_size, grid_size);
        
        Cells.operator[](m) += 1;
        
        Entropy.operator[](m) = Cells.operator[](m)*std::log(Cells.operator[](m));

    }

    for (int i = 0; i < N; i++){

        std::cout << Particles.operator[](i).get_x() + 0.5 << "\t" << Particles.operator[](i).get_y() + 0.5 << "\n";

    }

    for (int i = 0; i < cell_quantity*cell_quantity; i++){

                pre_entropy += Entropy.operator[](i);

            }
            
    total_entropy = std::log(N) - pre_entropy/N;

    return total_entropy;

}
