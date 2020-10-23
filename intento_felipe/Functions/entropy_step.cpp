#include "coffee_random.h"

double entropy_step (int old_cell, int new_cell, double pre_entropy,
                     std::vector<int> &Cells, std::vector<double> &Entropy){

    Cells[old_cell] -= 1;

    pre_entropy -= Entropy[old_cell];
            
    Entropy[old_cell] = Cells[old_cell]*std::log(Cells[old_cell]);

    if (Cells[old_cell] == 0){

        Entropy[old_cell] = 0;

    }

    pre_entropy += Entropy[old_cell];
    
        
    Cells[new_cell] += 1;
    
    pre_entropy -= Entropy[new_cell];
        
    Entropy[new_cell] = Cells[new_cell]*std::log(Cells[new_cell]);

    pre_entropy += Entropy[new_cell];

    return pre_entropy;

}
