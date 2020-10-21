#include "coffee_random.h"

double init_entropy(int N, int grid_size, int cell_size, std::vector<int> &Cells, std::vector<double> &Entropy){

    int cell_quantity = 2*(grid_size/cell_size);
    double pre_entropy = 0;
    
    for(int i = 0; i < cell_quantity*cell_quantity; i++){

        if (Cells[i] == 0){
            
            Entropy[i] = 0;
            
        }
        else {
            
            Entropy[i] = Cells[i]*std::log(Cells[i]);

        }

        pre_entropy += Entropy[i];        

    }

    return std::log(N) - pre_entropy/N;

}
