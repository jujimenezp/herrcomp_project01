#pragma once
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <gsl/gsl_fit.h>
#include <gsl/gsl_statistics.h>

struct CONFIG{
  int nmolecules = 0;
  int gridsize = 0;
  int latticesize = 0;
  int tmax = 0;
  int seed = 0;
  int resolution = 0;
  int holesize = 0;
  int holeposition = 0;
  // read initial conditions                
  void read(const std::string & fname);
};
struct Particle{
  int position[2] = {0,0};

  void Move(const int &step, const int &direction, const CONFIG &config, std::vector<int> &Cells);
  void Move_hole(const int &step, const int &direction, const int &particle_id, const CONFIG &config, std::vector<int> &Cells, std::vector<Particle> &Particles);
  int Getcell(const CONFIG &config);
};

typedef std::vector<Particle> Vec_p;
typedef std::vector<int> Vec_i;
typedef std::vector<double> Vec_d;

void start(const CONFIG &config, Vec_i &Cells, Vec_p &Particles);

double entropy(const CONFIG &config,const Vec_i &Cells);

void print_particles(Vec_p Particle, std::string pname);

double dropsize(const CONFIG &config,const Vec_p &Particles);

int stability (const CONFIG &config, const int partition_size, Vec_p &Particles, Vec_i &Cells);
