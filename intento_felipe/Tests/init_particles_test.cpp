#include "../Functions/coffee_random.h"

int main(void)
{

    int mols_number = 400;
    
    std::vector <particle> Particles (mols_number);

    init_particles(mols_number, Particles);

    distribution (mols_number, Particles, "distribution_start");
    
    return 0;
}
