#include "../Functions/coffee_random.h"

int main(void)
{
    //Posición inicial de la particula y vector de particulas
    
    int x0 = 49;
    int y0 = 49;

    std::vector <particle> Particles (1);

    //Dimensiones espacio
    
    int cell_size = 25;
    int grid_size = 100;

    //Condiciona la divisibilidad del tamaño del grid por el tamaño por celda
    
    if(grid_size % cell_size != 0){
        
        grid_size -= grid_size%cell_size;
        
    }

    //Variables y distribuciones aleatoreas
    
    int SEED = 0;
    int q, p;
    
    std::mt19937 gen(SEED);
    
    std::uniform_int_distribution<int> dis(0, 1);

    //Se ubica la particula y se genera una caminata aleatorea
    
    Particles[0].locate(x0, y0);

    std::cout << "\nX \tY \tCelda \n"; 
    
    std::cout << Particles[0].get_x() << "\t" << Particles[0].get_y() << "\t" << Particles[0].get_cell(grid_size, cell_size) << "\n";

    for(int i = 0; i < 10; i++){
        
        q = dis(gen);        
        p = dis(gen)*2 - 1; 

        Particles[0].move(q ,p ,grid_size);
        
        std::cout << Particles[0].get_x() << "\t" << Particles[0].get_y() << "\t" << Particles[0].get_cell(grid_size, cell_size) << "\n";
    }

    std::cout << "\n";

    //Se prueban los casos de frontera

    std::cout << "Frontera derecha \n";

    Particles[0].locate(grid_size - 1, 0);
    std::cout << Particles[0].get_x() << "\t" << Particles[0].get_y() << "\t" << Particles[0].get_cell(grid_size, cell_size) << "\n";
    Particles[0].move(0, 1, grid_size);
    std::cout << Particles[0].get_x() << "\t" << Particles[0].get_y() << "\t" << Particles[0].get_cell(grid_size, cell_size) << "\n";

    std::cout << "Frontera izquierda \n";

    Particles[0].locate(-grid_size, 0);
    std::cout << Particles[0].get_x() << "\t" << Particles[0].get_y() << "\t" << Particles[0].get_cell(grid_size, cell_size) << "\n";
    Particles[0].move(0, -1, grid_size);
    std::cout << Particles[0].get_x() << "\t" << Particles[0].get_y() << "\t" << Particles[0].get_cell(grid_size, cell_size) << "\n";

    std::cout << "Frontera superior \n";

    Particles[0].locate(0, grid_size - 1);
    std::cout << Particles[0].get_x() << "\t" << Particles[0].get_y() << "\t" << Particles[0].get_cell(grid_size, cell_size) << "\n";
    Particles[0].move(1, 1, grid_size);
    std::cout << Particles[0].get_x() << "\t" << Particles[0].get_y() << "\t" << Particles[0].get_cell(grid_size, cell_size) << "\n";

    std::cout << "Frontera inferior \n";

    Particles[0].locate(0, -grid_size);
    std::cout << Particles[0].get_x() << "\t" << Particles[0].get_y() << "\t" << Particles[0].get_cell(grid_size, cell_size) << "\n";
    Particles[0].move(1, -1, grid_size);
    std::cout << Particles[0].get_x() << "\t" << Particles[0].get_y() << "\t" << Particles[0].get_cell(grid_size, cell_size) << "\n\n";

    return 0;
}
