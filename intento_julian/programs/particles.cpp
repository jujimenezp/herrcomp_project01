#include <iostream>
#include <cmath>
#include "particles.h"

//funciones de la clase particles

void particles::step(int a){
    int m = rand()%2;  //numero aleatorio 0 o 1
    int n = 2*(rand()%2)-1;  //numero aleatorio -1 o 1
    if(fabs(pos[m]+n) >= a/2) n=0;  //condicion de frontera
    pos[m] += n;
}
