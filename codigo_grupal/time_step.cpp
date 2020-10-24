#include "header.h"


void time_step(const CONFIG &object, Vec_i &Cells, Vec_p &Particles)
{
    std::mt19937 gen(object.seed);
    std::uniform_int_distribution<int> dis_move(0, 1);
    std::uniform_int_distribution<int> dis_particle(0,object.nmolecules-1);

    int j=0, q=0, p=0, m=0;

    j = dis_particle(gen);        //escoge una particula al azar
    q = dis_move(gen);           //genera un numero aleatorio 0 o 1 (0 para x 1 para y)
    p = dis_move(gen)*2 - 1;    //genera un numero aleatorio 1 o -1 (1: arriba o derecha -1:abajo o izquierda)

    m=Particles[j].Getcel(object);
    Cells[m]-=1;
    Particles[j].Move(p,q,object);
    m=Particles[j].Getcel(object);
    Cells[m]+=1;        
}
