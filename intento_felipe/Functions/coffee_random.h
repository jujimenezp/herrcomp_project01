#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <string>
#include <fstream>

class particle{

    private:

        int position[2] = {0,0};
  
    public:
  
        int get_x (void);

        //Retorna coordenada x de la particula
        
        int get_y (void);

        //Retorna coordenada y de la particula
        
        int get_cell (int grid_size, int cell_size);

        //Retorna celda de la particula
        
        void locate (int x, int y);

        //Ubica la particula en x,y
        
        void move (int q, int p, int grid_size);

        //Mueve la particula aleatoriamente en cuanto a q = 0,1; p = -1, 1. Incluye tambien condiciones de frontera
        
};

void get_data (int &mols_number, int &grid_size, int &cells_number, int &iterations, int &seed);

//Lee los datos iniciales de init_data.txt

void distribution (int N, int grid_size, int cell_size, std::vector<particle> &Particles);

//Escribe la distribución de las particulas en un momento dado dentro de un archivo de texto, junto con las reglas para graficarlo

void init_particles (int n, std::vector<particle> &Particles);

//Organiza las particulas en su cuadrado inicial

void init_cells (int N, int grid_size, int cell_size, std::vector<particle> &Particles, std::vector<int> &Cells);

//Calcula la cantidad de particulas por celda para la distribucion inicial

double init_entropy (int N, int grid_size, int cell_size, std::vector<int> &Cells, std::vector<double> &Entropy);

//Calcula el factor m*Ln(m) para cada celda con m particulas en ella, y retorna la entroia inicial

double entropy_step (int old_cell, int new_cell, int N, int cell_quantity, std::vector<int> &Cells, std::vector<double> &Entropy);

//Calcula la entropia cuando una particula cambia de posición

double time_steps (int N, int grid_size, int cell_size, int iterations, int seed, double total_entropy, std::vector<particle> &Particles, std::vector<int> &Cells, std::vector<double> &Entropy);

//Genera el proceso de disperción para un numero fijo de iteraciones y condiciones iniciales
