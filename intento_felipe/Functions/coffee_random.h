#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <string>
#include <fstream>

class particle{
  
        public:

                int position[2] = {0,0};
        
                int get_cell (int grid_size, int cells_number);

                //Retorna celda de la particula
        
                void move (int q, int p, int grid_size);

                //Mueve la particula aleatoriamente en cuanto a q = 0,1; p = -1, 1. Incluye tambien condiciones de frontera
        
};

void get_data (int &mols_number, int &grid_size, int &cells_number,
               int &iterations, int &seed);

//Lee los datos iniciales de init_data.txt

void distribution (int mols_number, std::vector<particle> Particles, std::string name);

//Escribe la distribución de las particulas en un archivo de texto

void init_particles (int mols_number, std::vector<particle> &Particles);

//Organiza las particulas en su cuadrado inicial

void init_cells (int mols_number, int grid_size, int cells_number,
                 std::vector<particle> Particles, std::vector<int> &Cells);

//Calcula la cantidad de particulas por celda para la distribucion inicial

double init_entropy (int grid_size, int cells_number,
                     std::vector<int> Cells, std::vector<double> &Entropy);

//Calcula el factor m*Ln(m) para cada celda con m particulas en ella, y retorna la entroia inicial

double entropy_step (int old_cell, int new_cell, double pre_entropy,
                     std::vector<int> &Cells, std::vector<double> &Entropy);

//Calcula la entropia cuando una particula cambia de posición

void time_steps (int mols_number, int grid_size, int cells_number,
                   int iterations, int seed, double pre_entropy,
                   std::vector<particle> &Particles, std::vector<int> &Cells, std::vector<double> &Entropy);

//Genera el proceso de disperción para un numero fijo de iteraciones y condiciones iniciales
