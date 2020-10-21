#include "coffee_random.h"

void distribution (int N, int grid_size, int cell_size, std::vector<particle> &Particles){

    std::ofstream file;
    
    file.open("../Data/distribution_data.txt");
    
    for (int i = 0; i < N; i++){

        file << Particles[i].get_x() << "\t" << Particles[i].get_y() << "\n";

    }

    file.close();

    file.open("../Scripts/distribution_script.gp");

    file << "set xrange [" << -grid_size - cell_size << ":" << grid_size + cell_size << "]\n";
    file << "set yrange [" << -grid_size - cell_size << ":" << grid_size + cell_size << "]\n";
    file << "set xtics " << cell_size << "\n";
    file << "set ytics " << cell_size << "\n";
    file << "set grid\n";
    file << "set size square\n";
    file << "set object 1 rect from " << -grid_size << "," << -grid_size << " to " << grid_size << "," << grid_size << " lw 3 fs empty border lc rgb 'red'\n";
    file << "set term pdf\n";
    file << "set out '../Data/distribution_figure.pdf'\n";
    file << "plot '../Data/distribution_data.txt' w p pt 7 ps 0.5 lc rgb 'black' t 'Particles'";    

    file.close();

}
