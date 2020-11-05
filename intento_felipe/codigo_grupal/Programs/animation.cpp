#include "header.h"

int main(void)
{

  CONFIG config;
  config.read("Data/init_data.txt");

  Vec_p Particles(config.nmolecules);
  Vec_i Cells(config.gridsize*config.gridsize,0);
  
  start(config, Cells, Particles);

  std::mt19937 gen(config.seed);
  std::uniform_int_distribution<int> dis_move(0, 1);
  std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1);
  
  double Entropy = 0, Dropsize = 0;
  double Entropy_0 = entropy(config, Cells);
  int random_particle = 0, step = 0, direction = 0;
  std::string fname;
  
  for(int t = 0; t <= config.tmax; t++ ){

    random_particle = dis_particle(gen);        //Escoge una particula al azar
    step = dis_move(gen)*2 - 1;    //Genera un numero aleatorio 1 o -1 (1: arriba o derecha -1:abajo o izquierda)
    direction = dis_move(gen);           //Genera un numero aleatorio 0 o 1 (0 para x 1 para y)

    Particles[random_particle].Move(step, direction, config, Cells);

    if (t%config.resolution == 0){

        Entropy = entropy(config, Cells);
        Dropsize = dropsize (config, Particles);
        
        fname = "Data/Animation/data-" + std::to_string(t/config.resolution) + ".csv";

        std::ofstream file;
        file.open(fname);
    
        for (auto p: Particles){
        
            file << 1.0*p.position[0] + 0.5 << ","
                 << 1.0*p.position[1] + 0.5 <<  ","
                 << 1 << "," << Entropy_0 << "\n";
        
        }

        file << 0 << "," << 0 <<  ","
             << Dropsize << ","
             << Entropy << "\n";

        file.close();
    }
  }
  
  return 0;
}
