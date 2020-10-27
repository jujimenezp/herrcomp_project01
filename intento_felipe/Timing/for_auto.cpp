#include "../Programs/header.h"

double for_normal (int j);
double for_auto (int j);

int main(int argc, char **argv) {

    int j = atoi(argv[1]);

    double time_normal = 0, time_auto = 0, error_normal = 0, error_auto = 0;
    double T_normal = 0, T_auto = 0;

    for (int i = 0; i < 50; i ++){

        T_normal = for_normal(j);
        T_auto = for_auto(j);
        
        time_normal += T_normal;
        time_auto += T_auto;

        error_normal += std::pow(T_normal,2);
        error_auto += std::pow(T_auto,2);

    }
    
    time_normal /= 50.0;
    time_auto /= 50.0;

    error_normal = std::sqrt((error_normal - 50.0*std::pow(time_normal,2))/48.0)/std::sqrt(50);
    error_auto = std::sqrt((error_auto - 50.0*std::pow(time_auto,2))/48.0)/std::sqrt(50);

    std::cout << j*j << "\t"
              << time_normal << "\t"
              << time_auto << "\t"
              << error_normal << "\t"
              << error_auto << "\n";

    return 0;

}

double for_normal (int j){

    Vec_p Particles(j*j);

    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < j*j; i++){

        Particles[i].position[0] = i%j - j/2;
        Particles[i].position[1] = i/j - j/2;

        /*
        std::cout << Particles[i].position[0] << "\t"
                  << Particles[i].position[1] << "\n";
        */

    }

    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()*1.0e-9;

}


double for_auto (int j){

    Vec_p Particles(j*j);

    auto start = std::chrono::steady_clock::now();

    int i = 0;

    for (auto p: Particles){

        p.position[0] = i%j - j/2;
        p.position[1] = i/j - j/2;

        i += 1;

        /*
        std::cout << p.position[0] << "\t"
                  << p.position[1] << "\n";
        */
    }

    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()*1.0e-9;

}
