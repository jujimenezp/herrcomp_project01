#include "coffee_random.h"

int main(void)
{
    //Variables iniciales
    
    int x0 = 49;
    int y0 = 49;
    int cell_size = 25;
    int grid_size = 100;

    if(grid_size % cell_size != 0){
        
        grid_size -= grid_size%cell_size;
        
    }
    
    int SEED = 0;
    int q, p;
    
    std::mt19937 gen(SEED);
    
    std::uniform_int_distribution<int> dis(0, 1);

    std::vector <particle> Particles (5);

    //Se ubica la particula en el grid
    
    Particles.operator[](0).locate(x0, y0);

    //Se genera una caminata aleatoria por el grid. Tambien se incluye el calculo de la celda.

    std::cout << "X \tY \tCelda \n"; 
    
    std::cout << Particles.operator[](0).get_x() << "\t" << Particles.operator[](0).get_y() << "\t" << Particles.operator[](0).get_cell(cell_size, grid_size) << "\n";

    for(int i = 0; i < 10; i++){
        
        q = dis(gen);        
        p = dis(gen)*2 - 1; 

        Particles.operator[](0).move(q ,p ,grid_size);
        
        std::cout << Particles.operator[](0).get_x() << "\t" << Particles.operator[](0).get_y() << "\t" << Particles.operator[](0).get_cell(cell_size, grid_size) << "\n";
    }

    std::cout << "\n";

    //Se prueban los casos de frontera

    int i = 1;

    std::cout << "Frontera derecha \n";

    Particles.operator[](i).locate(grid_size - 1, 0);
    std::cout << Particles.operator[](i).get_x() << "\t" << Particles.operator[](i).get_y() << "\t" << Particles.operator[](i).get_cell(cell_size, grid_size) << "\n";
    Particles.operator[](i).move(0, 1, grid_size);
    std::cout << Particles.operator[](i).get_x() << "\t" << Particles.operator[](i).get_y() << "\t" << Particles.operator[](i).get_cell(cell_size, grid_size) << "\n" << "\n";

    i = 2;

    std::cout << "Frontera izquierda \n";

    Particles.operator[](2).locate(-grid_size, 0);
    std::cout << Particles.operator[](i).get_x() << "\t" << Particles.operator[](i).get_y() << "\t" << Particles.operator[](i).get_cell(cell_size, grid_size) << "\n";
    Particles.operator[](i).move(0, -1, grid_size);
    std::cout << Particles.operator[](i).get_x() << "\t" << Particles.operator[](i).get_y() << "\t" << Particles.operator[](i).get_cell(cell_size, grid_size) << "\n" << "\n";

    i = 3;

    std::cout << "Frontera superior \n";

    Particles.operator[](3).locate(0, grid_size - 1);
    std::cout << Particles.operator[](i).get_x() << "\t" << Particles.operator[](i).get_y() << "\t" << Particles.operator[](i).get_cell(cell_size, grid_size) << "\n";
    Particles.operator[](i).move(1, 1, grid_size);
    std::cout << Particles.operator[](i).get_x() << "\t" << Particles.operator[](i).get_y() << "\t" << Particles.operator[](i).get_cell(cell_size, grid_size) << "\n" << "\n";

    i = 4;

    std::cout << "Frontera inferior \n";

    Particles.operator[](4).locate(0, -grid_size);
    std::cout << Particles.operator[](i).get_x() << "\t" << Particles.operator[](i).get_y() << "\t" << Particles.operator[](i).get_cell(cell_size, grid_size) << "\n";
    Particles.operator[](i).move(1, -1, grid_size);
    std::cout << Particles.operator[](i).get_x() << "\t" << Particles.operator[](i).get_y() << "\t" << Particles.operator[](i).get_cell(cell_size, grid_size) << "\n" << "\n";
    
    return 0;
}
