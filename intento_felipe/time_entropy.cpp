#include "coffee_random.h"

double time_entropy (int N, int cell_size, int grid_size, int iterations, int seed, double pre_entropy, std::vector<particle> &Particles, std::vector<int> &Cells, std::vector<double> &Entropy){

    std::mt19937 gen(seed);
    
    std::uniform_int_distribution<int> dis_move(0, 1);
    
    std::uniform_int_distribution<int> dis_particle(0, N-1);

    int cell_quantity = 2*grid_size/cell_size;

    int j, m1, m2, q, p;

    double total_entropy = std::log(N) - pre_entropy/N;

    std::cout << "0" << "\t" << total_entropy << "\n";

    pre_entropy = 0;

    for (int i = 0; i < iterations; i++){

        j = dis_particle(gen);

        m1 = Particles.operator[](j).get_cell(cell_size, grid_size);
        
        q = dis_move(gen);
        p = dis_move(gen)*2 - 1;

        Particles.operator[](j).move(q ,p ,grid_size);

        m2 = Particles.operator[](j).get_cell(cell_size, grid_size);

        if (m1 != m2){
        
            Cells.operator[](m1) -= 1;
            
            Entropy.operator[](m1) = Cells.operator[](m1)*std::log(Cells.operator[](m1));

            if (Cells.operator[](m1) == 0){

                Entropy.operator[](m1) = 0;

            }
        
            Cells.operator[](m2) += 1;
        
            Entropy.operator[](m2) = Cells.operator[](m2)*std::log(Cells.operator[](m2));

            for (int k = 0; k < cell_quantity*cell_quantity; k++){

                pre_entropy += Entropy.operator[](k);

            }
            
            total_entropy = std::log(N) - pre_entropy/N;
            
        }
        
        std::cout << i+1 << "\t" << total_entropy << "\n";
        
        pre_entropy = 0;

    }

    return total_entropy;

}
