#include <iostream>
#include "implementation.h"
#include "printdata.h"


void start(std::vector<particles> &x, int N){
    int l=std::sqrt(N);
    
    for(int ii=0; ii<l; ++ii){
        for(int jj=0; jj<l; ++jj){
            int p=ii*l+jj;
            x[p].pos[0]=jj-l/2;
            x[p].pos[1]=ii-l/2;
        }
    }
}


std::vector<int> getgrid(int a, int b, std::vector<particles> d){
    std::vector<int> gi(a*a);
    int m=0, n=0, p=0, g=0;
    for(int ii=0; ii<d.size(); ++ii){ 
        g=getg(a, b, d[ii].pos[0], d[ii].pos[1]);
        gi[g] += 1;
    }
    return gi;
}


void  iteration(int a, int b, std::vector<particles> &d, int N, std::vector<int> &c, int &oldg, int &newg){
    int g, r=rand()%N;
    oldg=getg(a, b, d[r].pos[0], d[r].pos[1]);
    d[r].step(b);
    newg=getg(a, b, d[r].pos[0], d[r].pos[1]);
}


int getg(int a, int b, int cx, int cy){
    int m, n,  g;
    m = (cy+b/2)*a/b;
    n = (cx+b/2)*a/b;
    g = a*m+n;
    return g;
}


double init_entropy(std::vector<int> x, int N, std::vector<double> &entropy){
    double S=0.0;
    double p=std::log(N);
    for(int ii=0; ii<x.size(); ++ii){
        if(x[ii] != 0) {
            entropy[ii] = x[ii]*std::log(1.0*x[ii]);
            S += entropy[ii];
        }
    }
    S=p-S/(1.0*N);
    return S;
}

void manyite(int a, int b, std::vector<particles> &d, int N, std::vector<int> &c, int e, double S, std::vector<double> &entropy){
    int oldg=0, newg=0;
    std::ofstream file;
    file.open("data/data_entropy.txt");
    for(int ii=0; ii<e; ++ii){
        iteration(a, b, d, N, c, oldg, newg);
        if(oldg != newg) S = entropy_step(N, oldg, newg, S, c, entropy);
        file << ii << "\t" << S << "\n";
    }
    file.close();
}


double entropy_step(int N, int oldg, int newg, double S, std::vector<int> &c, std::vector<double> &entropy){

    S += (1.0/N)*(entropy[oldg]+entropy[newg]);
        
    c[oldg] -= 1;
    c[newg] += 1;
    
    entropy[oldg] = c[oldg]*std::log(c[oldg]);
    if(c[oldg] == 0) entropy[oldg] = 0;
    entropy[newg] = c[newg]*std::log(c[newg]);
    S -= (1.0/N)*(entropy[oldg]+entropy[newg]);
        
    return S;
}
