#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class particle{

    private:

        int position[2] = {0,0};

        int cell = 0;
  
    public:
  
        int get_x (void);
        
        int get_y (void);
        
        int get_cell (int cell_size, int grid_size);
        
        void locate (int x, int y);
        
        void move (int q, int p, int grid_size);
        
};

void get_data (int &mol_number, int &grid_size, int &cell_size, int &iterations, int &seed);

void init_particles (int n, std::vector<particle> &Particles);

void init_cells (int N, int cell_size, int grid_size, std::vector<particle> &Particles, std::vector<int> &Cells);

double init_entropy (int N, int cell_size, int grid_size, std::vector<int> &Cells, std::vector<double> &Entropy);

double time_distribution (int N, int cell_size, int grid_size, int iterations, int seed, double pre_entropy, std::vector<particle> &Particles, std::vector<int> &Cells, std::vector<double> &Entropy);

double time_entropy (int N, int cell_size, int grid_size, int iterations, int seed, double pre_entropy, std::vector<particle> &Particles, std::vector<int> &Cells, std::vector<double> &Entropy);

