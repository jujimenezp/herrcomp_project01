#include "coffee_random.h"
#include <string>
#include <fstream>

void get_data (int &mol_number, int &grid_size, int &cell_size, int &iterations, int &seed){
    
    std::string line;
    
    std::ifstream init_data;
    
    init_data.open("init_data.txt");
    
    std::getline(init_data, line);
    
    mol_number = std::stoi(line.erase(line.find('#'), line.size()) );

    mol_number = std::ceil(std::sqrt(mol_number/4));
    
    std::getline(init_data, line);
    
    grid_size = std::stoi(line.erase(line.find('#'), line.size()) );
    
    std::getline(init_data, line);
    
    cell_size = std::stoi(line.erase(line.find('#'), line.size()) );
    
    std::getline(init_data, line);

    if(grid_size % cell_size != 0){
        grid_size -= grid_size%cell_size;
    }
    
    iterations = std::stoi(line.erase(line.find('#'), line.size()) );
    
    std::getline(init_data, line);
    
    seed = std::stoi(line.erase(line.find('#'), line.size()) );
    
    init_data.close();
}
