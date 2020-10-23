#include "header.h"

void CONFIG::read(const std::string &fname)
{
  // open file (for reading)
  std::ifstream fin(fname);
  
  // read it
  std::string line;

  std::getline(fin, line);
  xmin = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  xmax = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  ymin = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  ymax = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  xlatticesize = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  ylatticesize = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  xgridsize = std::stod( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  ygridsize = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  nparticles = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  tmax = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  seed = std::stoi( line.erase(line.find('#'), line.size()) );
  std::getline(fin, line);
  eps = std::stoi( line.erase(line.find('#'), line.size()) );
  
  // close it
  fin.close();
}
