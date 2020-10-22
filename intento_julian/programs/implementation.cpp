#include <iostream>
#include "implementation.h"
#include "printdata.h"


std::vector<particles> start(std::vector<particles> x, int N){
    int l=std::sqrt(N);
    
    for(int ii=0; ii<l; ++ii){
        for(int jj=0; jj<l; ++jj){
            int p=ii*l+jj;
            x[p].pos[0]=jj-l/2;
            x[p].pos[1]=ii-l/2;
        }
    }
    return x;
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


void  iteration(int a, int b, std::vector<particles> &d, int N, std::vector<int> &c){

    int g, r=rand()%N;
    g=getg(a, b, d[r].pos[0], d[r].pos[1]);
    c[g] -= 1;
    d[r].step(b);
    g=getg(a, b, d[r].pos[0], d[r].pos[1]);
    c[g] += 1;
}


int getg(int a, int b, int cx, int cy){
    int m, n,  g;
    m = (cy+b/2)*a/b;
    n = (cx+b/2)*a/b;
    g = a*m+n;
    return g;
}


void entropy(std::vector<int> x, int N, std::vector<double> &ent, int i){
    double s=0.0;
    double p=std::log(N);
    for(int ii=0; ii<x.size(); ++ii){
        if(x[ii] != 0) s += x[ii]*std::log(1.0*x[ii]);
    }
    s=p-s/(1.0*N);
    ent[i]=s;
}

void manyite(int a, int b, std::vector<particles> &d, int N, std::vector<int> &c, int e, std::vector<double> &ent){
    for(int ii=0; ii<e; ++ii){
        entropy(c, N, ent, ii);
        iteration(a, b, d, N, c);
    }
}
