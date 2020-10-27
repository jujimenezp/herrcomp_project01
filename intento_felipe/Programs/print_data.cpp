#include "header.h"

void print_position(const Vec_p &Particles, const std::string fname){
    
    std::ofstream file;
    file.open(fname);
    
    for (auto p: Particles){
        
        file << 1.0*p.position[0] + 0.5 << "\t"
             << 1.0*p.position[1] + 0.5 << "\n";
        
    }
    
    file.close();
    
}
