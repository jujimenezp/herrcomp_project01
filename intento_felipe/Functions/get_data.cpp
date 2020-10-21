#include "coffee_random.h"

void get_data (int &mol_number, int &grid_size, int &cell_size, int &iterations, int &seed){
    
    std::string line;
    
    std::ifstream init_data;
    
    init_data.open("../Data/init_data.txt");
    
    std::getline(init_data, line);
    
    mol_number = std::stoi(line.erase(line.find('#'), line.size()) );

    //Convierte a mo_number en cuadrado perfecto de un numero par
    
    mol_number = std::ceil(std::sqrt(mol_number/4));
    
    std::getline(init_data, line);
    
    grid_size = std::stoi(line.erase(line.find('#'), line.size()) );
    
    std::getline(init_data, line);
    
    cell_size = std::stoi(line.erase(line.find('#'), line.size()) );
    
    std::getline(init_data, line);

    //Convierte a grid_size en multiplo de cell_size
    
    if(grid_size % cell_size != 0){
        
        grid_size -= grid_size%cell_size;
        
    }
    
    iterations = std::stoi(line.erase(line.find('#'), line.size()) );
    
    std::getline(init_data, line);
    
    seed = std::stoi(line.erase(line.find('#'), line.size()) );
    
    init_data.close();
}
