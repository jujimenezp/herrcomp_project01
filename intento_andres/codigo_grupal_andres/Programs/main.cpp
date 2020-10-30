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
  
  double Entropy = 0;
  int random_particle = 0, step = 0, direction = 0;

  for(int t = 0; t <= config.tmax; t++ ){

    random_particle = dis_particle(gen);
    while(random_particle >= Particles.size()){
      random_particle = dis_particle(gen);
    } //escoge una particula al azar
    step = dis_move(gen)*2 - 1; //genera un numero aleatorio 1 o -1 (1: arriba o derecha -1:abajo o izquierda)
    direction = dis_move(gen); //genera un numero aleatorio 0 o 1 (0 para x 1 para y)
    
    time_step(t, config, random_particle, step, direction, Cells, Particles);
    
    if (t%config.resolution == 0){  
      Entropy = entropy(config, Cells);
      /*std::string fname = "Data/post/datos-" + std::to_string(t) + ".csv";
      std::ofstream fout(fname);
      for (int i = 0; i < Particles.size(); i++){
	fout << Particles[i].position[0] << ", "
	     << Particles[i].position[1] << "\n";
      }
      fout.close();*/
    }
    if (Particles.size() == 0){
      std::cerr << "se acabo la crema perro" << std::endl;
      return 0;}
    
  }

  //std::cout << Entropy;
  
  return 0;
}
