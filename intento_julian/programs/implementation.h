#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "particles.h"

 //inicializa las particulas en un cuadrado
void start(std::vector<particles> &x, int N);

 //cuenta cuantas particulas hay en cada cuadricula
std::vector<int> getgrid(int a, int b, std::vector<particles> d);

 //Ejecuta el paso
void iteration(int a, int b, std::vector<particles> &d, int N, std::vector<int> &c, int &oldg, int &newg);

  //encuentra la casilla en la que esta una particula
int getg(int a, int b, int cx, int cy);

  //Da el valor inicial de la entropia
double init_entropy(std::vector<int> x, int N, std::vector<double> &entropy);

  //Actualiza el grid y la entropia
double entropy_step(int N, int oldg, int newg, double S, std::vector<int> &c, std::vector<double> &entropy);

  //Ejecuta iteration y entropy_step durante el # de iteracones especificado
void manyite(int a, int b, std::vector<particles> &d, int N, std::vector<int> &c, int e, double S, std::vector<double> &entropy);
