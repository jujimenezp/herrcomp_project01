#include "coffee_random.h"

double init_entropy(int N, int cell_size, int grid_size, std::vector<int> &Cells, std::vector<double> &Entropy){

    int cell_quantity = 2*(grid_size/cell_size);
    double total_entropy = 0;
    
    for(int i = 0; i < cell_quantity*cell_quantity; i++){

        if (Cells.operator[](i) == 0){
            
            Entropy.operator[](i) = 0;
            
        }
        else {
            
            Entropy.operator[](i) = Cells.operator[](i)*std::log(Cells.operator[](i));

        }

        total_entropy += Entropy.operator[](i);        

    }

    return total_entropy;

}
