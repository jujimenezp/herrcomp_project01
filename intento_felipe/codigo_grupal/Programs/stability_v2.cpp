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
  
  int random_particle = 0, step = 0, direction = 0, t = 0, j = 0;

  const int partition_size = config.latticesize*config.latticesize/10;

  double Times [partition_size];
  for (int i = 0; i < partition_size; i++) Times[i] = i*config.resolution;
  
  double Entropies[partition_size];

  double c0 = 0, c1 = 0, null = 0, mean = 0, sd = 0;
  double deviation_dis = 0, deviation_fit = 0;
  double eps_dis = 0.003, eps_fit = 0.005;
  int counter_dis = 0, counter_fit = 0, counter_both = 0;
  
  std::ofstream entrofile;   //Salida de entropia
  entrofile.open("Data/data_stability_v2.txt");
  
  for(int t = 1; t <= config.tmax; t++ ){

    random_particle = dis_particle(gen);        //Escoge una particula al azar
    step = dis_move(gen)*2 - 1;    //Genera un numero aleatorio 1 o -1 (1: arriba o derecha -1:abajo o izquierda)
    direction = dis_move(gen);           //Genera un numero aleatorio 0 o 1 (0 para x 1 para y)

    Particles[random_particle].Move(step, direction, config, Cells);

    if (t%config.resolution == 0){
        
      j = t/config.resolution;

      Entropies[j%partition_size] = entropy(config, Cells);

      if (j%partition_size == partition_size - 1){

        mean = gsl_stats_mean (Entropies, 1, partition_size);
        sd = gsl_stats_sd_m (Entropies, 1, partition_size, mean);
        gsl_fit_linear(Times, 1, Entropies, 1, partition_size, &c0, &c1, &null, &null, &null, &null); //Calcula la regresion lineal de las entropias.

        deviation_dis = sd/mean;
        deviation_fit = std::abs(c1)*Times[partition_size - 1]/c0; //Calcula el parametro para cuantizar la desviacion de la funcion a una linea horizontal. 

        if (deviation_dis < eps_dis) counter_dis += 1;
        if (deviation_fit < eps_fit) counter_fit += 1;
        if (deviation_dis < eps_dis && deviation_fit < eps_fit) counter_both += 1;

        entrofile << t << "\t"
                  << deviation_dis << "\t" << deviation_fit << "\t"
                  << counter_dis << "\t" << counter_fit << "\t" << counter_both << "\n";
        
      }
        
    }
  }
  
  entrofile.close();
  
  return 0;
}
