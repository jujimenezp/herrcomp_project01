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
  int gridsize = 0;
  int latticesize = 0;
  int tmax = 0;
  int seed = 0;
  int resolution = 0;
  int holeboolean = 0;
  int holesize = 0;
  int holeposition = 0;
          
  void read(const std::string & fname); //read configuration
};

struct Particle{

  int position[2] = {0,0};  

  void Move(const int &step, const int &direction, const CONFIG &config);
  void Move_hole(const int &time, const int &step, const int &direction, const int &particle_id, const CONFIG &config, std::vector<int> &Cells, std::vector<Particle> &Particles);
  int Getcell(const CONFIG &config);
};

typedef std::vector<Particle> Vec_p;
typedef std::vector<int> Vec_i;
typedef std::vector<double> Vec_d;

void start(const CONFIG &config, Vec_i &Cells, Vec_p &Particles);

void time_step(const int &time, const CONFIG &config, int random_particle, int step, int direction, Vec_i &Cells, Vec_p &Particles);

double entropy(const CONFIG &config,const Vec_i &Cells);
