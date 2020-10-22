#include "coffee_random.h"

void distribution (int mols_number, std::vector<particle> Particles, std::string name){

    std::ofstream file;

    std::string fname = "../Data/" + name + ".txt";
    
    file.open(fname);
    
    for (int i = 0; i < mols_number; i++){

        file << Particles[i].position[0] << "\t"
             << Particles[i].position[1] << "\n";

    }

    file.close();

}
