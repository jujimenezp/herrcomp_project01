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
  
  double Entropy_1 = 0, Entropy_0 = entropy(config, Cells);
  int random_particle = 0, step = 0, direction = 0;

  std::ofstream entrofile;   //Salida de entropia
  entrofile.open("Data/data_stability_v1.txt");
  
  for(int t = 1; t <= config.tmax; t++ ){

    random_particle = dis_particle(gen);        //Escoge una particula al azar
    step = dis_move(gen)*2 - 1;    //Genera un numero aleatorio 1 o -1 (1: arriba o derecha -1:abajo o izquierda)
    direction = dis_move(gen);           //Genera un numero aleatorio 0 o 1 (0 para x 1 para y)

    Particles[random_particle].Move(step, direction, config, Cells);

    if (t%config.resolution == 0){
        
        Entropy_1 = entropy(config, Cells);
        entrofile << t << "\t"
                  << std::abs(Entropy_1-Entropy_0)/Entropy_1
                  << "\n";
        
        Entropy_0 = Entropy_1;
        
    }
  }
  
  entrofile.close();
  
  return 0;
}
