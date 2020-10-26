#include "header.h"

void print_position(const Vec_p &Particles, const std::string fname){
    
    std::ofstream file;
    file.open(fname);
    
    for (int i = 0; i < Particles.size(); i++){
        
        file << Particles[i].position[0] << "\t"
             << Particles[i].position[1] << "\n";
        
    }
    
    file.close();
    
}
    
/*void print_entro(std::vector<double> x, std::string name){
    std::ofstream file;
    file.open(name);
    for(int ii=0; ii<x.size(); ++ii){
        file << ii << "\t"
             << x[ii]
             << "\n";
    }
    file.close();
}
*/
