#include "header.h"

void time_step(const CONFIG &object, int j, int q, int p, Vec_i &Cells, Vec_p &Particles)
{
    
    int m=0;
    
    m = Particles[j].Getcel(object);
    Cells[m] -= 1;
    
    Particles[j].Move(p,q,object);
    
    m = Particles[j].Getcel(object);
    Cells[m] += 1;
    
}
