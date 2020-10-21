#pragma once
#include <iostream>

//Declaracion de clase particles
class particles //clase de particulas
{
    private:
        int x, y;
    public:
        int pos[2]={x,y}; //matriz de posiciones
        void step(int a); //ejecuta un paso en una particula
        
};
