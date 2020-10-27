#include "../Programs/header.h"

double print_here (const CONFIG &config, Vec_i &Cells, Vec_p &Particles);
double print_out (const CONFIG &config, Vec_i &Cells, Vec_p &Particles);

int main (void){
    
    double time_here = 0, time_out = 0;

    CONFIG config;
    config.read("../Data/init_data.txt");

    Vec_p Particles(config.nmolecules);
    Vec_i Cells(config.gridsize*config.gridsize,0);
  
    start(config, Cells, Particles);

    time_here = print_here (config, Cells, Particles);

    start(config, Cells, Particles);

    time_out = print_out (config, Cells, Particles);

    std::ofstream file;
    file.open("data_1.txt");
    
    file << time_here << "\n"
         << time_out;

    file.close();
    
    return 0;
}

double print_here (const CONFIG &config, Vec_i &Cells, Vec_p &Particles){

    std::mt19937 gen(config.seed);
    std::uniform_int_distribution<int> dis_move(0, 1);
    std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1);

    double Entropy = 0; 
    
    int j = 0, q = 0, p = 0;

    auto start = std::chrono::steady_clock::now();
  
    for (int t = 0; t <= config.tmax; t++){

        j = dis_particle(gen);        //escoge una particula al azar
        q = dis_move(gen);           //genera un numero aleatorio 0 o 1 (0 para x 1 para y)
        p = dis_move(gen)*2 - 1;    //genera un numero aleatorio 1 o -1 (1: arriba o derecha -1:abajo o izquierda)
        
        time_step(config, j, q, p, Cells, Particles);

        if (t%config.resolution == 0){
        
            Entropy = entropy(config, Cells);

            std::cout << t << "\t" << Entropy << "\n";

        }
        
    }

    auto end = std::chrono::steady_clock::now();

    double time = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()*1.0e-9;

    return time;

}

double print_out (const CONFIG &config, Vec_i &Cells, Vec_p &Particles){

    std::mt19937 gen(config.seed);
    std::uniform_int_distribution<int> dis_move(0, 1);
    std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1);

    double Entropy = 0;
    
    int j = 0, q = 0, p = 0;

    auto start = std::chrono::steady_clock::now();

    std::ofstream file;
    file.open("../Data/data_entropy.txt");
  
    for (int t = 0; t <= config.tmax; t++){

        j = dis_particle(gen);        //escoge una particula al azar
        q = dis_move(gen);           //genera un numero aleatorio 0 o 1 (0 para x 1 para y)
        p = dis_move(gen)*2 - 1;    //genera un numero aleatorio 1 o -1 (1: arriba o derecha -1:abajo o izquierda)
        
        time_step(config, j, q, p, Cells, Particles);

        if (t%config.resolution == 0){
        
            Entropy = entropy(config, Cells);

            file << t << "\t" << Entropy << "\n";

        }
        
    }

    file.close();

    auto end = std::chrono::steady_clock::now();

    double time = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()*1.0e-9;

    return time;

}
