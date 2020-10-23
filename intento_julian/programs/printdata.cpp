#include <iostream>
#include "printdata.h"

void print_pos(std::vector<particles> x, std::string name){
    std::ofstream file;
    file.open(name);
    for(int ii=0; ii<x.size(); ++ii){
        file << x[ii].pos[0] << "\t"
             << x[ii].pos[1]
             << "\n";
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
