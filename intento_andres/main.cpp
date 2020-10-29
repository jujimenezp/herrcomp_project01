#include "header.h"

typedef std::vector<PARTICLE> particlevector;
typedef std::vector<int> gridvector;
typedef std::vector<double> probvector;

void distribute(const CONFIG object, particlevector &configuracion, gridvector &distribucion, probvector &probabilities);
double entropy(const CONFIG &object, double &entropia, const int origin,const int destiny, const gridvector &distribucion, const probvector &probabilities);

int main()
{
  CONFIG config;
  config.read("config.txt"); //read configuration parameters
  
  double entropia = 0;
  
  particlevector configuracion(config.nparticles); //configuracion de las particulas en el espacio
  gridvector distribucion(config.xgridsize*config.ygridsize); //distribucion de las particulas en el grid
  probvector PI(config.xgridsize*config.ygridsize); //probabilidades por celda del grid
  
  initial_conditions(config, configuracion, distribucion, PI);
  
  distribute(config, configuracion, distribucion, PI);

  return 0;
}

void distribute(const CONFIG object, particlevector &configuracion, gridvector &distribucion, probvector &probabilities)
{
  std::mt19937 seed(object.seed);
  std::uniform_int_distribution<int> dis(0, 1);
  std::uniform_int_distribution<int> jdfhfhufguhrruihghr
  
  std::cout.precision(15);std::cout.setf(std::ios::scientific);
  
  std::mt19937 eng(object.seed);
  std::uniform_int_distribution<int> gen(0, object.nparticles-1);
  
  int particulaj = 0;
  int origin = 0;
  int destiny = 0;
  
  for(int t = 0; t < object.tmax; t++){
    particulaj = gen(eng);
    origin = configuracion[particulaj].locate(object);
    configuracion[particulaj].move(object);
    if (t % 10 == 0) {
      std::string fname = "post/datos-" + std::to_string(t) + ".csv";
      std::ofstream fout(fname);
      for(auto particula : configuracion){
	fout << particula.posicion[0] << ", "
	     << particula.posicion[1] << ", "
	     << "\n";
      }
      fout.close();
    }
    configuracion[particulaj].print(object);
    destiny = configuracion[particulaj].locate(object);

    if(origin == destiny){std::cout<< entropia << "\n";}
    else{
      if(distribucion[origin] != 0){
	entropia += probabilities[origin]*(std::log(distribucion[origin])-std::log(object.nparticles));
      }
      if(distribucion[destiny] != 0){
	entropia += probabilities[destiny]*(std::log(distribucion[destiny])-std::log(object.nparticles));
      }
  
      probabilities[origin] = (distribucion[origin] - 1)/(1.0*object.nparticles);
      probabilities[destiny] = (distribucion[destiny] + 1)/(1.0*object.nparticles);
  
      entropia -= probabilities[origin] + probabilities[destiny];
      //std::cout << entropia << "\n";
      distribucion[origin] -= 1;
      distribucion[destiny] += 1;
    }
  }
}

/*double entropy(const CONFIG &object, double &entropia, const int origin,const int destiny, const gridvector &distribucion, probvector &probabilities)
{
  if(probabilities[origin] != 0){
    entropia += probabilities[origin]*(std::log(distribucion[origin])-std::log(object.nparticles));
  }
  if(probabilities[destiny] != 0){
    entropia += probabilities[destiny]*(std::log(distribucion[destiny])-std::log(object.nparticles));
  }
  
  probabilities[origin] = (distribucion[origin] - 1)/(1.0*object.nparticles);
  probabilities[destiny] = (distribucion[destiny] + 1)/(1.0*object.nparticles);
  
  entropia -= probabilities[origin] + probabilities[destiny];
  
  return entropia;
  }*/
