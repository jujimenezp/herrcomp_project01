#include "../Programs/header.h"

int main (void){

    double time_cout = 0, time_ofstream = 0, error_cout = 0, error_ofstream = 0;
    double T = 0;

    int n = 1, N = 0;

    std::string line;

    std::ifstream times;

    times.open("data_2.txt");

    while (getline (times,line)){
        
        T = std::stod(line);

        if (n%2 == 1){

            time_cout += T;
            error_cout += std::pow(T,2);

        }
        else {
            
            time_ofstream += T;
            error_ofstream += std::pow(T,2);

            N = n/2;

        }

        n += 1;
        
    }    

    times.close();

    time_cout /= 1.0*N;
    time_ofstream /= 1.0*N;

    error_cout = std::sqrt((error_cout - N*std::pow(time_cout,2))/(1.0*(N-2)))/std::sqrt(N);
    error_ofstream = std::sqrt((error_ofstream - N*std::pow(time_ofstream,2))/(1.0*(N-2)))/std::sqrt(N);

    std::cout << "\t" << time_cout << "\t" << time_ofstream << "\t"
              << error_cout << "\t" << error_ofstream << "\n";
    
    return 0;
}
