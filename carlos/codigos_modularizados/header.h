#pragma once
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Particle{

private:

  int position[2]={0,0}; int cel=0; double l=0; double N=0; double L=0;

public:

  void start(int x0, int y0, int NN, double LL);
  void Move(int p, int q);
  int Getx(void){return position[0];};
  int Gety(void){return position[1];};
  int Getcel(void);
};

void getdatos (int &a, int &b, int &c, int &d, int &e);

void start(int N, int m,int M,double L, std::vector<Particle> &Particles, std::vector<int> &Cel);
std::vector<double> entropy(int tmax, int resol, int N, int m, std::vector<Particle> &Particles, std::vector<int> &Cel, std::vector<double> &S);

void print_pos(std::vector<Particle> &x, std::string name);

void print_entro(std::vector<double> &x, std::string name);


