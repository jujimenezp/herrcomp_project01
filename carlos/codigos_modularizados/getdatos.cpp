#include "header.h"

void getdatos (int &a, int &b, int &c, int &d, int &e){
    std::string line;
    std::ifstream init_data;
    init_data.open("init_data.txt");
    std::getline(init_data, line);
    a=std::stoi(line.erase(line.find('#'), line.size()) );
    std::getline(init_data, line);
    b=std::stoi(line.erase(line.find('#'), line.size()) );
    std::getline(init_data, line);
    c=std::stoi(line.erase(line.find('#'), line.size()) );
    std::getline(init_data, line);
    d=std::stoi(line.erase(line.find('#'), line.size()) );
    std::getline(init_data, line);
    e=std::stoi(line.erase(line.find('#'), line.size()) );
    init_data.close();
}
