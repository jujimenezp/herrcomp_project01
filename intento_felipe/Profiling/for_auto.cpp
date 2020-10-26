#include "../Programs/header.h"

double for_normal (int j);
double for_auto (int j);

int main(int argc, char **argv) {

    int j = atoi(argv[1]);

    double time_normal = 0, time_auto = 0, normal_error = 0, auto_error = 0;
    double T_normal = 0, T_auto = 0;

    for (int i = 0; i < 50; i ++){

        T_normal = for_normal(j);
        T_auto = for_auto(j);
        
        time_normal += T_normal;
        time_auto += T_auto;

        normal_error += std::pow(T_normal,2);
        auto_error += std::pow(T_auto,2);

    }
    
    time_normal /= 50;
    time_auto /= 50;

    normal_error = std::sqrt(normal_error/48)/std::sqrt(50);
    auto_error = std::sqrt(auto_error/48)/std::sqrt(50);

    std::cout << j*j << "\t"
              << time_normal << "\t"
              << time_auto << "\t"
              << normal_error << "\t"
              << auto_error << "\n";

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

    int i = 0;

    Vec_p Particles(j*j);

    auto start = std::chrono::steady_clock::now();

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
