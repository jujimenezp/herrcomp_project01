#include "coffee_random.h"

void get_data (int &mols_number, int &grid_size, int &cells_number, int &iterations, int &seed){
    
    std::string line;
    
    std::ifstream init_data;
    
    init_data.open("../Data/init_data.txt");
    
    std::getline(init_data, line);
    
    mols_number = std::stoi(line.erase(line.find('#'), line.size()) );

    //Convierte a mo_number en cuadrado perfecto
    
    mols_number =(int)std::sqrt(mols_number)*(int)std::sqrt(mols_number);
    
    std::getline(init_data, line);
    
    grid_size = std::stoi(line.erase(line.find('#'), line.size()) );
    
    std::getline(init_data, line);
    
    cells_number = std::stoi(line.erase(line.find('#'), line.size()) );
    
    std::getline(init_data, line);

    //Convierte a grid_size en multiplo de cells_number
    
    if(grid_size % cells_number != 0){
        
        grid_size -= grid_size%cells_number;
        
    }
    
    iterations = std::stoi(line.erase(line.find('#'), line.size()) );
    
    std::getline(init_data, line);
    
    seed = std::stoi(line.erase(line.find('#'), line.size()) );
    
    init_data.close();
}
