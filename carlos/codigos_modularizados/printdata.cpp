#include "header.h"

void print_pos(std::vector<Particle> &x, std::string name, double L){
    std::ofstream file;
    file.open(name);
    for(int ii=0; ii<x.size(); ++ii){
      file << x[ii].Getx()-L/2 << "\t"
	   << x[ii].Gety()-L/2
             << "\n";
    }
    file.close();
}
    
void print_entro(std::vector<double> &x, std::string name, double t){
    std::ofstream file;
    file.open(name);
    for(int ii=0; ii<(x.size()-t); ++ii){
        file << ii*t << "\t"
             << x[ii]
             << "\n";
    }
    file.close();
}
void print_size(std::vector<double> &x, std::string name, double t){
    std::ofstream file;
    file.open(name);
    for(int ii=0; ii<(x.size()-t); ++ii){
        file << ii*t << "\t"
             << x[ii]
             << "\n";
    }
    file.close();
}

