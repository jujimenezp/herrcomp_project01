#include "header.h"



int main(void)
{
  double Entropy=0;

  CONFIG config;
  config.read("init_data.txt");

  Vec_p Particles(config.nmolecules);
  Vec_i Cells(config.gridsize*config.gridsize,0);
  
  
  start(config, Cells, Particles);
  
  for(int t=0; t<=config.tmax; t++ ){
    time_step(config, Cells, Particles);
    Entropy=entropy(config, Cells);
  }
  
  return 0;
}
