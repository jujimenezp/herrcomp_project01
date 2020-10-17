#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "getdatos.h"

std::vector<int> getdatos(){
//int main(){
    std::string strdata[5];
    std::ifstream initdata;
    initdata.open("init_data.txt");
    for(int ii=0; ii<5; ++ii){
        std::getline(initdata, strdata[ii],' ');
        initdata.ignore(50,'\n');
    }

    initdata.close();
    
    std::vector<int> data(5);
    for(int ii=0; ii<5; ++ii){
        data[ii] = std::stoi(strdata[ii]);
        std::cout << data[ii] << "\n";
    }

    return data;
}
