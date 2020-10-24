#pragma once
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <random>


struct CONFIG{
  int nmolecules = 0;
  int latticesize = 0;
  int tmax = 0;
  int seed = 0;
  int gridsize = 0;
  int resolution=0;
  // read initial conditions                
  void read(const std::string & fname);                                    
};
struct Particle{

  int position[2]={0,0};  

  void Move(int p, int q, const CONFIG &object);
  int Getcel(const CONFIG &object);
};

typedef std::vector<Particle> Vec_p;
typedef std::vector<int> Vec_i;
typedef std::vector<double> Vec_d;

void start(const CONFIG &object, Vec_i &Cells, Vec_p &Particles);

void time_step(const CONFIG &object, Vec_i &Cells, Vec_p &Particles);

double entropy(const CONFIG &object,const Vec_i &Cells);

//drop_size;

//print_pos;

//print_drop;







