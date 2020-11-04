#include "header.h"

int main(void)
{

  CONFIG config;
  config.read("../Data/init_data.txt");

  Vec_p Particles(config.nmolecules);
  Vec_i Cells(config.gridsize*config.gridsize,0);
  
  start(config, Cells, Particles);

  std::mt19937 gen(config.seed);
  std::uniform_int_distribution<int> dis_move(0, 1);
  std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1);
  
  int random_particle = 0, step = 0, direction = 0;
  int previous_size = 0;

  for(int t = 0; t <= config.tmax; t++ ){

    random_particle = dis_particle(gen); //escoge una particula al azar
    step = dis_move(gen)*2 - 1; //genera un numero aleatorio 1 o -1 (1: arriba o derecha -1:abajo o izquierda)
    direction = dis_move(gen); //genera un numero aleatorio 0 o 1 (0 para x 1 para y)
    
    previous_size = Particles.size();

    //impresion para simulacion en paraview
    std::string fname = "../Data/post_wrong/datos-" + std::to_string(t) + ".csv";
    std::ofstream fout(fname);
    for (int i = 0; i < Particles.size(); i++){
      fout << Particles[i].position[0] << ", "
	   << Particles[i].position[1] << "\n";
    }
    fout.close();
    
    Particles[random_particle].Move_hole(t, step, direction, random_particle, config, Cells, Particles);

    if (Particles.size() != previous_size){ //se asegura de tener el rango correcto para escoger particulas
      dis_particle.param(typename decltype(dis_particle)::param_type( 0,Particles.size()-1 ));
    }
    
  }
  
  return 0;
}
