#ifndef __HEADER_H__
#define __HEADER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <cmath>

struct CONFIG{
  int xmin = 0;
  int xmax = 0;
  int ymin = 0;
  int ymax = 0;
  int xlatticesize = 0;
  int ylatticesize = 0;
  int xgridsize = 0;
  int ygridsize = 0;
  int nparticles = 0;
  int tmax = 0;
  int seed = 0;
  int eps = 0;
  // method
  void read(const std::string & fname);
  //void print(const std::string & fname);
};

struct PARTICLE{
  std::vector<int> posicion{0,0};

  void initialize(const CONFIG &object, const int i, const int j);
  void move(const CONFIG &object);
  int locate(const CONFIG &object);
  void print(const CONFIG &object);
};

void initial_conditions(const CONFIG &object, std::vector<PARTICLE> &configuracion, std::vector<int> &distribucion, std::vector<double> &probabilities);

#endif // __HEADER_H_