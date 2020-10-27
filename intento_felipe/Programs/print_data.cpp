#include "header.h"

void print_position(const Vec_p &Particles, const std::string fname){
    
    std::ofstream file;
    file.open(fname);
    
    for (auto p: Particles){
        
        file << p.position[0] << "\t"
             << p.position[1] << "\n";
        
    }
    
    file.close();
    
}
