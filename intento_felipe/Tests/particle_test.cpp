#include "../Functions/coffee_random.h"

int main(void)
{
    //Posición inicial de la particula y vector de particulas
    
    int x0 = 45;
    int y0 = 45;

    std::vector <particle> Particles (1);

    //Dimensiones espacio

    int grid_size = 200;
    int cells_number = 8;

    //Variables y distribuciones aleatoreas
    
    int SEED = 0;
    int q, p;
    
    std::mt19937 gen(SEED);
    
    std::uniform_int_distribution<int> dis(0, 1);

    //Se ubica la particula y se genera una caminata aleatorea
    
    Particles[0].position[0] = x0;
    Particles[0].position[1] = y0;

    std::cout << "\nX \tY \tCelda \n"; 
    
    std::cout << Particles[0].position[0] << "\t"
              << Particles[0].position[1] << "\t"
              << Particles[0].get_cell(grid_size, cells_number)
              << "\n";

    for(int i = 0; i < 10; i++){
        
        q = dis(gen);        
        p = dis(gen)*2 - 1; 

        Particles[0].move(q ,p ,grid_size);

        std::cout << Particles[0].position[0] << "\t"
                  << Particles[0].position[1] << "\t"
                  << Particles[0].get_cell(grid_size, cells_number)
                  << "\n";
        
    }

    //Se prueban los casos de frontera

    std::cout << "\nFrontera derecha \n";

    Particles[0].position[0] = grid_size/2 - 1;
    
    std::cout << Particles[0].position[0] << "\t"
              << Particles[0].position[1] << "\t"
              << Particles[0].get_cell(grid_size, cells_number)
              << "\n";

    Particles[0].move(0, 1, grid_size);

    std::cout << Particles[0].position[0] << "\t"
              << Particles[0].position[1] << "\t"
              << Particles[0].get_cell(grid_size, cells_number)
              << "\n";
    
    
    std::cout << "\nFrontera arriba \n";

    Particles[0].position[1] = grid_size/2 - 1;
    
    std::cout << Particles[0].position[0] << "\t"
              << Particles[0].position[1] << "\t"
              << Particles[0].get_cell(grid_size, cells_number)
              << "\n";

    Particles[0].move(1, 1, grid_size);

    std::cout << Particles[0].position[0] << "\t"
              << Particles[0].position[1] << "\t"
              << Particles[0].get_cell(grid_size, cells_number)
              << "\n";
    

    std::cout << "\nFrontera izquierda \n";

    Particles[0].position[0] = -grid_size/2;
    
    std::cout << Particles[0].position[0] << "\t"
              << Particles[0].position[1] << "\t"
              << Particles[0].get_cell(grid_size, cells_number)
              << "\n";

    Particles[0].move(0, -1, grid_size);

    std::cout << Particles[0].position[0] << "\t"
              << Particles[0].position[1] << "\t"
              << Particles[0].get_cell(grid_size,  cells_number)
              << "\n";
    

    std::cout << "\nFrontera abajo \n";

    Particles[0].position[1] = -grid_size/2;
    
    std::cout << Particles[0].position[0] << "\t"
              << Particles[0].position[1] << "\t"
              << Particles[0].get_cell(grid_size, cells_number)
              << "\n";

    Particles[0].move(1, -1, grid_size);

    std::cout << Particles[0].position[0] << "\t"
              << Particles[0].position[1] << "\t"
              << Particles[0].get_cell(grid_size, cells_number)
              << "\n\n";

    return 0;
}
