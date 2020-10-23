#include "coffee_random.h"

void get_data (int &mols_number, int &grid_size, int &cells_number,
               int &iterations, int &seed){
    
    std::string line;
    
    std::ifstream init_data;
    
    init_data.open("../Data/init_data.txt");
    
    std::getline(init_data, line);
    
    mols_number = std::stoi(line.erase(line.find('#'), line.size()) );

    //Convierte a mol_number en cuadrado perfecto
    
    mols_number =(int)std::sqrt(mols_number)*(int)std::sqrt(mols_number);
    
    std::getline(init_data, line);
    
    grid_size = std::stoi(line.erase(line.find('#'), line.size()) );
    
    std::getline(init_data, line);
    
    cells_number = std::stoi(line.erase(line.find('#'), line.size()) );
    
    std::getline(init_data, line);

    //Convierte a grid_size en número par y multiplo de cells_number

    grid_size = 2*(grid_size/2 - (grid_size/2)%cells_number);
    
    iterations = std::stoi(line.erase(line.find('#'), line.size()) );
    
    std::getline(init_data, line);
    
    seed = std::stoi(line.erase(line.find('#'), line.size()) );
    
    init_data.close();
}
