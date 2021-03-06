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
  
  int random_particle = 0, step = 0, direction = 0;

  std::ofstream holefile;   //Salida de entropia
  holefile.open("Data/data_hole.txt");

  int t = -1, size = config.nmolecules;

  while (Particles.size()/(1.0*config.nmolecules) > 0.1){

    t += 1;
    size = Particles.size();
    
    random_particle = dis_particle(gen); //escoge una particula al azar
    step = dis_move(gen)*2 - 1; //genera un numero aleatorio 1 o -1 (1: arriba o derecha -1:abajo o izquierda)
    direction = dis_move(gen); //genera un numero aleatorio 0 o 1 (0 para x 1 para y)

    if (random_particle > Particles.size()){ //se asegura de tener el rango correcto para escoger particulas
      continue;
    }

    Particles[random_particle].Move_hole(step, direction, random_particle, config, Cells, Particles);

    if (Particles.size() != size){
        
      holefile << t-1 << "\t"
               << Particles.size() << "\n";

    }

  }

  holefile.close();
  
  return 0;
}
