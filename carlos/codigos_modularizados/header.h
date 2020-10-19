#pragma once
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Particle;
void entropy(int tmax, int N, int m, std::vector<Particle> &Particles, std::vector<int> &Cel);
