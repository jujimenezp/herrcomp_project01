#include "header.h"

void print_particles(Vec_p Particle, std::string pname)
{
    std::ofstream file;
    file.open(pname);
    
    for(auto p: Particle){
        file << p.position[0] << "\t"
             << p.position[1] << "\n";
    }
    
    file.close();
}
