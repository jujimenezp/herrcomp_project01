#include <iostream>
#include "particle.h"
#include "config.h"

double initial_conditions(const CONFIG &object, std::vector<PARTICLE> &configuracion, std::vector<int> &distribucion, std::vector<double> &PI);
int Locate(const CONFIG object, PARTICLE j);
void distribute(const CONFIG object, double entropia, std::vector<PARTICLE> &configuracion, std::vector<int> &distribucion, std::vector<double> &PI);
double entropy(const CONFIG &object, double entropia,const int origin,const int destiny, std::vector<double> &PI, std::vector<int> distribucion);

int main()
{
  CONFIG config;
  config.read("config.txt");
  double entropia = 0;
  std::vector<PARTICLE> configuracion(config.nmolecules); //configuracion de las particulas en el espacio
  std::vector<int> Distribucion((config.xrange/config.latticesize)*(config.xrange/config.latticesize)); //distribucion de las particulas en el Lattice
  std::vector<double> PI((config.xrange/config.latticesize)*(config.xrange/config.latticesize)); //probabilidades por celda del Lattice
  entropia = initial_conditions(config, configuracion, Distribucion, PI);
  distribute(config, entropia, configuracion, Distribucion, PI);
}

double initial_conditions(const CONFIG &object, std::vector<PARTICLE> &configuracion, std::vector<int> &distribucion, std::vector<double> &PI)
{
  double S = 0.0;
  double nmolecules = object.nmolecules;
  
  for(int j = 0; j < std::sqrt(object.nmolecules); j++){ //ubicacion inicial de las particulas en el espacio
    for(int i = 0; i < std::sqrt(object.nmolecules); i++){
      configuracion[i+j*std::sqrt(nmolecules)].initialize(object.xrange, nmolecules, i, j);
    }
  }
  for(int i = 0; i < nmolecules; i++){ //calcula la distribucion inicial en el lattice
    distribucion[Locate(object, configuracion[i])] += 1;
  }
  for(int i = 0; i < PI.size(); i++){ //calcula la entropia inicial
    PI[i] = distribucion[i]/nmolecules;
    if(PI[i] < object.eps){
      S += PI[i];
      //std::cout << S << "\n";
    }
    else{
      S += PI[i]*std::log(PI[i]);
      //std::cout << S << "\n";
    }
  }
  
  return -S;
}

int Locate(const CONFIG object, PARTICLE j)
{
  //int Cellsize = xrange/Xrange;
  int X = j.posicion[0]/object.latticesize;
  int Y = j.posicion[1]/object.latticesize;
  return X + Y*(object.xrange/object.latticesize);
}

void distribute(const CONFIG object, double entropia, std::vector<PARTICLE> &configuracion, std::vector<int> &distribucion, std::vector<double> &PI)
{
  std::cout.precision(15); // precision de impresion
  std::cout.setf(std::ios::scientific); // notacion
  
  std::mt19937 eng(object.randomgeneratorseed); //generador de numeros aleatorios con semilla 1
  std::uniform_int_distribution<int> gen(0, object.nmolecules-1); //distribución
  
  int particulaj = 0;
  int origin = 0;
  int destiny = 0;
  double S = entropia;
  
  for(int t = 0; t < object.niterations; t++){
    particulaj = gen(eng);//Genera un numero aleatorio entero entre 0 y N-1;
    origin = Locate(object, configuracion[particulaj]);
    configuracion[particulaj].move(object.randomgeneratorseed, object.xrange);
    destiny = Locate(object, configuracion[particulaj]);
    
    if(origin == destiny){std::cout<< S << "\n";}
    else{
      S = entropy(object, S, origin, destiny, PI, distribucion);
      std::cout << S << "\n";
      distribucion[origin] -= 1;
      distribucion[destiny] += 1;
    }
  }
}

double entropy(const CONFIG &object, double entropia,const int origin,const int destiny, std::vector<double> &PI, std::vector<int> distribucion)
{
  if(PI[origin] < object.eps){
    entropia -= PI[origin];
  }
  else{entropia -= PI[origin]*std::log(PI[origin]);}
  if(PI[destiny] < object.eps){
    entropia -= PI[destiny];
  }
  else{entropia -= PI[destiny]*std::log(PI[destiny]);}
  
  /*PI[origin] = (distribucion[origin] - 1.0)*PI[origin] / distribucion[origin];
    PI[destiny] = (distribucion[destiny] + 1.0)*PI[destiny] / distribucion[destiny];*/
  PI[origin] = (distribucion[origin] - 1.0)/object.nmolecules;
  PI[destiny] = (distribucion[destiny] + 1.0)/object.nmolecules;
  
  if(PI[origin] < object.eps){
    entropia += PI[origin];
  }
  else{entropia += PI[origin]*std::log(PI[origin]);}
  if(PI[destiny] < object.eps){
    entropia += PI[destiny];
  }
  else{entropia += PI[destiny]*std::log(PI[destiny]);}
  return -entropia;
}
