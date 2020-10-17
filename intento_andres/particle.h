#include <iostream>
#include <vector>
#include <random>
#include <cmath>

struct PARTICLE{
  std::vector<int> posicion{0,0,0};
  void move(const int randomgeneratorseed, const int xrange);
  void initialize(const int xrange, const int nmolecules, const int i, const int j);
};
