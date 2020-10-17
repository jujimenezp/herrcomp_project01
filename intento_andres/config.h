#include <iostream>
#include <fstream>
#include <string>

struct CONFIG{
  int xrange = 0;
  int nmolecules = 0;
  int latticesize = 0;
  int niterations = 0;
  int randomgeneratorseed = 0;
  double eps = 0;
  // method
  void read(const std::string & fname);
  //void print(const std::string & fname);
};
