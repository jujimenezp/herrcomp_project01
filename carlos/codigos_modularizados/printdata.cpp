#include "header.h"

void print_pos(std::vector<Particle> &x, std::string name){
    std::ofstream file;
    file.open(name);
    for(int ii=0; ii<x.size(); ++ii){
      file << x[ii].Getx()-50 << "\t"
	   << x[ii].Gety()-50
             << "\n";
    }
    file.close();
}
    
void print_entro(std::vector<double> &x, std::string name){
    std::ofstream file;
    file.open(name);
    for(int ii=0; ii<x.size(); ++ii){
        file << ii << "\t"
             << x[ii]
             << "\n";
    }
    file.close();
}
