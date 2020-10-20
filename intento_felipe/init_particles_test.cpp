#include "coffee_random.h"

int main(int argc, char *argv[])
{

    int n = atoi(argv[1]);
 
    std::vector <particle> Particles (4*n*n);

    init_particles(n, Particles);

    for(int i = 0; i < 4*n*n; i++){

        std::cout << Particles.operator[](i).get_x() + 0.5 << "\t" << Particles.operator[](i).get_y() + 0.5 << "\n";

    }
    
    return 0;
}
