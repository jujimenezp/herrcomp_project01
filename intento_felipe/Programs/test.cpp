#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

#include "header.h"

TEST_CASE ("All tests", "[Main]"){
    
    CONFIG config;
    config.read("Data/init_data.txt");

    std::mt19937 gen(config.seed);
    std::uniform_int_distribution<int> dis_move(0, 1);
    std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1);
    std::uniform_int_distribution<int> dis_location(-config.latticesize/2, config.latticesize/2 - 1);
    
    Vec_p Particles(config.nmolecules);
    Vec_i Cells(config.gridsize*config.gridsize,0);
    
    int x = 0, y = 0, m = 0;

    for (int i = 0; i < config.nmolecules; i++){

        x = dis_location(gen);
        y = dis_location(gen);

        Particles[i].position[0] = x;
        Particles[i].position[1] = y;
        m = Particles[i].Getcel(config);
        Cells[m] += 1;

    }

    SECTION ("Border conditions"){

        int x_old = 0, y_old = 0, cell_old = 0,
            x_new = 0, y_new = 0, cell_new = 0;

        Particles[0].position[0] = config.latticesize/2 - 1; //Frontera derecha
    
        x_old = Particles[0].position[0];
        y_old = Particles[0].position[1];
        cell_old = Particles[0].Getcel(config);

        Particles[0].Move(1, 0, config);

        x_new = Particles[0].position[0];
        y_new = Particles[0].position[1];
        cell_new = Particles[0].Getcel(config);
    
        REQUIRE (x_old == x_new);
        REQUIRE (y_old == y_new);
        REQUIRE (cell_old == cell_new);

    
        Particles[0].position[1] = config.latticesize/2 - 1; //Frontera arriba
    
        x_old = Particles[0].position[0];
        y_old = Particles[0].position[1];
        cell_old = Particles[0].Getcel(config);

        Particles[0].Move(1, 1, config);

        x_new = Particles[0].position[0];
        y_new = Particles[0].position[1];
        cell_new = Particles[0].Getcel(config);
    
        REQUIRE (x_old == x_new);
        REQUIRE (y_old == y_new);
        REQUIRE (cell_old == cell_new);

    
        Particles[0].position[0] = -config.latticesize/2; //Frontera izquierda
    
        x_old = Particles[0].position[0];
        y_old = Particles[0].position[1];
        cell_old = Particles[0].Getcel(config);

        Particles[0].Move(-1, 0, config);

        x_new = Particles[0].position[0];
        y_new = Particles[0].position[1];
        cell_new = Particles[0].Getcel(config);
    
        REQUIRE (x_old == x_new);
        REQUIRE (y_old == y_new);
        REQUIRE (cell_old == cell_new);

    
        Particles[0].position[1] = -config.latticesize/2; //Frontera abajo
    
        x_old = Particles[0].position[0];
        y_old = Particles[0].position[1];
        cell_old = Particles[0].Getcel(config);

        Particles[0].Move(-1, 1, config);

        x_new = Particles[0].position[0];
        y_new = Particles[0].position[1];
        cell_new = Particles[0].Getcel(config);
    
        REQUIRE (x_old == x_new);
        REQUIRE (y_old == y_new);
        REQUIRE (cell_old == cell_new);

    }

    SECTION ("Cells conditions"){

        int sum = 0;     //La suma de todas las casillas debe dar el número de particulas

        for (int i = 0; i < config.gridsize*config.gridsize; i++){

            sum += Cells[i];

        }

        REQUIRE (sum == config.nmolecules);

        Particles[0].position[0] = -config.latticesize/2;    //Esquina inferior izquierda del grid
        Particles[0].position[1] = -config.latticesize/2;

        m = Particles[0].Getcel(config);

        REQUIRE (m == 0);

        Particles[0].position[0] = config.latticesize/2 - 1;    //Esquina superior derecha del grid
        Particles[0].position[1] = config.latticesize/2 - 1;

        m = Particles[0].Getcel(config);

        REQUIRE (m == config.gridsize*config.gridsize - 1);

    }

    SECTION ("Entropy conditions"){

        double eps = 1e-30, Entropy = 0;

        for (int i = 0; i < config.gridsize*config.gridsize; i++){

            Cells[i] = 0;

        }

        for (int i = 0; i < config.nmolecules; i++){

            Particles[i].position[0] = 0;
            Particles[i].position[1] = 0;
            m = Particles[i].Getcel(config);
            Cells[m] += 1;

        }

        Entropy = entropy(config, Cells);

        REQUIRE (Entropy >= 0);

        REQUIRE (Entropy < eps);

    }
    
}
