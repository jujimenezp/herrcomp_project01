#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "particles.h"

 //inicializa las particulas en un cuadrado
std::vector<particles> start(std::vector<particles> x, int N);

 //cuenta cuantas particulas hay en cada cuadricula
std::vector<int> getgrid(int a, int b, std::vector<particles> d);

 //Ejecuta el paso y actualiza el grid
void iteration(int a, int b, std::vector<particles> &d, int N, std::vector<int> &c);

  //encuentra la casilla en la que esta una particula
int getg(int a, int b, int cx, int cy);

 //Calcula la entropia
void entropy(std::vector<int> x, int N, double &s);

//Ejecuta iteration y entropy durante el # de iteracones especificado
void manyite(int a, int b, std::vector<particles> &d, int N, std::vector<int> &c, int e, double &s);
