#include "../Programs/header.h"

double for_normal (int j);
double for_auto (int j);

int main(int argc, char **argv) {

    int N = 100;

    int j = atoi(argv[1]);

    double time_normal = 0, time_auto = 0, error_normal = 0, error_auto = 0;
    double T_normal = 0, T_auto = 0;

    for (int i = 0; i < N; i ++){

        T_normal = for_normal(j);
        T_auto = for_auto(j);
        
        time_normal += T_normal;
        time_auto += T_auto;

        error_normal += std::pow(T_normal,2);
        error_auto += std::pow(T_auto,2);

    }
    
    time_normal /= 1.0*N;
    time_auto /= 1.0*N;

    error_normal = std::sqrt((error_normal - N*std::pow(time_normal,2))/(1.0*(N-2)))/std::sqrt(N);
    error_auto = std::sqrt((error_auto - N*std::pow(time_auto,2))/(1.0*(N-2)))/std::sqrt(N);

    std::cout << j << "\t"
              << time_normal << "\t"
              << time_auto << "\t"
              << error_normal << "\t"
              << error_auto << "\n";

    return 0;

}

double for_normal (int j){
    
    Vec_i Cells(j,0);
    double s = 0;

    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < j; i++){

        Cells[i] = i%j;

        if (Cells[i] != 0) {

            s += Cells[i]*std::log(Cells[i]);

        }

    }

    auto end = std::chrono::steady_clock::now();

    //std::cout << s << "\n";

    return std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()*1.0e-9;

}


double for_auto (int j){

    Vec_i Cells(j,0);
    double s = 0;

    auto start = std::chrono::steady_clock::now();

    int i = 0;

    for(auto c: Cells){

        c = i%j;
        
        if(c != 0) {

            s += c*std::log(c);

        }

        i += 1;
        
    }

    auto end = std::chrono::steady_clock::now();

    //std::cout << s << "\n";

    return std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()*1.0e-9;

}
