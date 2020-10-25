#include "coffee_random.h"

double init_entropy(int grid_size, int cells_number, std::vector<int> Cells, std::vector<double> &Entropy){

    double pre_entropy = 0; //sum((ni)(Logni))
    
    for(int i = 0; i < cells_number*cells_number; i++){

        if (Cells[i] == 0){
            
            Entropy[i] = 0;
            
        }
        else {
            
            Entropy[i] = Cells[i]*std::log(Cells[i]);

        }

        pre_entropy += Entropy[i];        

    }

    return pre_entropy;

}
