#include "header.h"

void CONFIG::read(const std::string & fname)
{
    std::string line;

    std::ifstream init_data;

    init_data.open(fname);

    std::getline(init_data, line);
    
    nmolecules = std::stoi(line.erase(line.find('#'), line.size()));
      
    //Convierte a nmolecules en cuadrado perfecto anterior
      
    nmolecules =(int)std::sqrt(nmolecules)*(int)std::sqrt(nmolecules);

    std::getline(init_data, line);

    latticesize = std::stoi(line.erase(line.find('#'), line.size()) );

    std::getline(init_data, line);

    tmax = std::stoi(line.erase(line.find('#'), line.size()) );

    std::getline(init_data, line);                                                                

    seed = std::stoi(line.erase(line.find('#'), line.size()) );

    std::getline(init_data, line);

    gridsize = std::stoi(line.erase(line.find('#'), line.size()) );

    //Convierte a latticesize en número par y multiplo de gridsize

    if (gridsize%2 == 0){
        latticesize = 2*(latticesize/2 - (latticesize/2)%(gridsize/2));
    }
    else {
        latticesize = 2*(latticesize/2 - (latticesize/2)%gridsize);    
    }

    std::getline(init_data, line);

    resolution = std::stoi(line.erase(line.find('#'), line.size()) );

    init_data.close();
	
}

