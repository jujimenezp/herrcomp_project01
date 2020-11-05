#include "header.h"

void CONFIG::read(const std::string & fname)
{
    std::string line;

    std::ifstream init_data;

    init_data.open(fname);

    std::getline(init_data, line);
    nmolecules = std::labs(std::stoi(line.erase(line.find('#'), line.size()) ));
      
    //Convierte a nmolecules en cuadrado perfecto anterior
    nmolecules =(int)std::sqrt(nmolecules)*(int)std::sqrt(nmolecules);

    std::getline(init_data, line);
    gridsize = std::labs(std::stoi(line.erase(line.find('#'), line.size()) ));
    
    std::getline(init_data, line);
    latticesize = std::labs(std::stoi(line.erase(line.find('#'), line.size()) ));

    //Convierte a latticesize en numero par y multiplo de gridsize
    if (gridsize%2 == 0){
        latticesize = 2*(latticesize/2 - (latticesize/2)%(gridsize/2));
    }
    else {
        latticesize = 2*(latticesize/2 - (latticesize/2)%gridsize);    
    }

    std::getline(init_data, line);
    tmax = std::labs(std::stoi(line.erase(line.find('#'), line.size()) ));

    std::getline(init_data, line);
    seed = std::stoi(line.erase(line.find('#'), line.size()) );

    std::getline(init_data, line);
    resolution = std::labs(std::stoi(line.erase(line.find('#'), line.size()) ));

    std::getline(init_data, line);
    holesize = std::labs(std::stoi(line.erase(line.find('#'), line.size()) ));

    holesize = latticesize/5;
    if (holesize%2 == 0){ //Convierte a holesize en el numero impar siguiente
      holesize += 1;
    }

    std::getline(init_data, line);
    holeposition = std::stoi(line.erase(line.find('#'), line.size()) );

    int proper_hole_position = 0;
    
    for (int i = -1; i <= 2; i++){
      proper_hole_position += (holeposition == i) ? 1 : 0;
    }

    if (nmolecules > latticesize*latticesize || nmolecules == 0 || proper_hole_position == 0 || resolution < 100 || latticesize == 0 || gridsize == 0){
      std::cout << "flaws were found on the configuration, setting everything back to default" << std::endl;
      nmolecules = 400;
      gridsize = 8;
      latticesize = 200;
      tmax = 10000000;
      seed = 0;
      resolution = 100;
      holesize = 41;
      holeposition = 1;
    }
    
    init_data.close();

}
