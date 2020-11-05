#include "header.h"

int stability (const CONFIG &config, const int partition_size, Vec_p &Particles, Vec_i &Cells){

    /*
      La función estima el tiempo en el que la entropia se estabiliza.
      Esta toma conjuntos de entropias calculadas y les aplica una regresión lineal para
      obtener un estimado de que tan cercana esta la función en esa región a una linea 
      horizontal.
    */

    //Se generan distribuciones aleatorias para diferentes motivos.
    std::mt19937 gen(config.seed);
    std::uniform_int_distribution<int> dis_move(0, 1); //Para escoger a donde se mueve cada particula.
    std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1); //Para escoger la particula que se va a mover.
    
    int random_particle = 0; //ID de la particula que se mueve.
    int step = 0; //Sentido en que se mueve la particula (1 -> positivo)(-1 -> negativo).
    int direction = 0; //Dirección que se mueve la particula (0 -> X)(1 -> Y).
    int t = 0;  //Tiempo de iteración.
    int j = 0;  //Cantidad de resoluciones de tiempo que han pasado.
    
    double eps = 0.005; //Limite para el criterio de estabilidad.

    double Times [partition_size]; //Arreglo que guarda los tiempos para la regresión lineal de las entropias.
    for (int i = 0; i < partition_size; i++) Times[i] = i*config.resolution; 
    //Se acomoda el resto de tiempos desde la posición 1 en adelante, el tiempo inicial es 0 y entre tiempo y tiempo hay una resolución
    
    double Entropies[partition_size]; //Arreglo que guarda las entropias para la regresión lineal.

    double c0 = 0, c1 = 0; //Parametros de la regresión lineal (y = c0 + c1*x)
    double null = 0; //Parámetros que pide la libreria pero no son necesarias para el programa
    double deviation = eps + 1; //Parametro para cuantizar la desviación de la regresión calculada a una linea horizontal.
    //Se inicializa de esta forma para que entre al ciclo while

    while (deviation > eps){

        random_particle = dis_particle(gen);  //Escoge una particula al azar
        step = dis_move(gen)*2 - 1;  //Genera un numero aleatorio 1 o -1 (1: arriba o derecha -1:abajo o izquierda)
        direction = dis_move(gen); //Genera un numero aleatorio 0 o 1 (0 para x, 1 para y)
    
        Particles[random_particle].Move(step, direction, config, Cells);  //Genera la caminata aleatorea
        
        if (t%config.resolution == 0){

            j = t/config.resolution;

            Entropies[j%partition_size] = entropy(config, Cells); //Guarda cada entropia dentro del conjunto escogido.

            if (j%partition_size == partition_size - 1){

                gsl_fit_linear(Times, 1, Entropies, 1, partition_size, &c0, &c1, &null, &null, &null, &null); //Calcula la regresión lineal de las entropias.
                deviation = std::abs(c1)*Times[partition_size - 1]/c0; //Calcula el parametro para cuantizar la desviación de la función a una linea horizontal. 

            }

        }

        t += 1;  
        
    }

    return t - (partition_size -1)*config.resolution/2; //Devuelve el tiempo medio del intervalo en el cual la entropia llego al equilibrio.
    
}
