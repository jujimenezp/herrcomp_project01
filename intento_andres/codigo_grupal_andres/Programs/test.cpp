#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "header.h"

TEST_CASE ("All tests", "[Main]"){
    
    CONFIG config;
    config.read("Data/init_data.txt");

    std::mt19937 gen(config.seed);
    std::uniform_int_distribution<int> dis_move(0, 1);
    std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1);
    std::uniform_int_distribution<int> dis_location(-config.latticesize/2, config.latticesize/2 - 1);
    std::unifrom_int_distribution<int> dis_hole(-config.holesize/2, config.holesize/2);
    
    Vec_p Particles(config.nmolecules);
    Vec_i Cells(config.gridsize*config.gridsize,0);
    
    int x = 0, y = 0, m = 0;

    for (auto particle : Particles){ //make a random distribution of particles

        x = dis_location(gen);
        y = dis_location(gen);

        particle.position[0] = x;
        particle.position[1] = y;
        m = particle.Getcell(config);
        Cells[m] += 1;

    }

    SECTION ("Border conditions"){
      
      if (config.holeboolean == 0){ //fronteras sin agujero
	
	int x_old = 0, y_old = 0, cell_old = 0;
	
	Particles[0].position[0] = config.latticesize/2 - 1; //Frontera derecha
	
	x_old = Particles[0].position[0];
	
	for(int i = -config.latticesize/2; i < config.latticesize/2; i++){
	  Particles[0].position[1] = i;
	  cell_old = Particles[0].Getcell(config);
	  Particles[0].Move(1, 0, config);
	  
	  REQUIRE (x_old == Particles[0].position[0]);
	  REQUIRE (i == Particles[0].position[1]);
	  REQUIRE (cell_old == Particles[0].Getcell(config));
	}
	
        Particles[0].position[1] = config.latticesize/2 - 1; //Frontera arriba
	
	y_old = Particles[0].position[1];
	
	for(int i = -config.latticesize/2; i < config.latticesize/2; i++){
	  Particles[0].position[0] = i;
	  cell_old = Particles[0].Getcell(config);
	  Particles[0].Move(1, 1, config);
	  
	  REQUIRE (i == Particles[0].position[0]);
	  REQUIRE (y_old == Particles[0].position[1]);
	  REQUIRE (cell_old == Particles[0].Getcell(config));
	}
	
        Particles[0].position[0] = -config.latticesize/2; //Frontera izquierda
	
	x_old = Particles[0].position[0];
	
	for(int i = -config.latticesize/2; i < config.latticesize/2; i++){
	  Particles[0].position[1] = i;
	  cell_old = Particles[0].Getcell(config);
	  Particles[0].Move(-1, 0, config);
	  
	  REQUIRE (x_old == Particles[0].position[0]);
	  REQUIRE (i == Particles[0].position[1]);
	  REQUIRE (cell_old == Particles[0].Getcell(config));
	}
	
        Particles[0].position[1] = -config.latticesize/2; //Frontera abajo
	
	y_old = Particles[0].position[1];
	
	for(int i = -config.latticesize/2; i < config.latticesize/2; i++){
	  Particles[0].position[0] = i;
	  cell_old = Particles[0].Getcell(config);
	  Particles[0].Move(-1, 1, config);
	  
	  REQUIRE (i == Particles[0].position[0]);
	  REQUIRE (y_old == Particles[0].position[1]);
	  REQUIRE (cell_old == Particles[0].Getcell(config));
	}
	
      }
      else{
	int old_count = 0, lost_count = 0, initial_size = Particles.size();
	int future_x = Particles[Particles.size() - 1].position[0];
	int future_y = Particles[Particles.size() - 1].position[1];
	
	Particles[0].position[0] = config.latticesize/2 - 1; //Frontera derecha
	Particles[0].position[1] = dis_hole(gen);
	cell_old = Particles[0].Getcell(config);
	old_count = Cells[cell_old];
	
	config.holeposition = 2;
	
	Particles[0].Move_hole(1, 0, 0, config, Cells, Particles);
	lost_count += 1;
	
	REQUIRE (Particles[0].position[0] == future_x);
	REQUIRE (Particles[0].position[1] == future_y);
	REQUIRE (Particles.size() == initial_size - lost_count);
	REQUIRE (Cells[cell_old] == old_count - 1);
	
	future_x = Particles[Particles.size() - 1].position[0]; //reset future values
	future_y = Particles[Particles.size() - 1].position[1];
	
	Particles[0].position[1] = config.latticesize/2 - 1; //Frontera arriba
	Particles[0].position[0] = dis_hole(gen);
	cell_old = Particles[0].Getcell(config);
	old_count = Cells[cell_old];
	
	config.holeposition = 1;
	
	Particles[0].Move_hole(1, 1, 0, config, Cells, Particles);
	lost_count += 1;
	
	REQUIRE (Particles[0].position[0] == future_x);
	REQUIRE (Particles[0].position[1] == future_y);
	REQUIRE (Particles.size() == initial_size - lost_count);
	REQUIRE (Cells[cell_old] == old_count - 1);
	
	future_x = Particles[Particles.size() - 1].position[0]; //reset future values
	future_y = Particles[Particles.size() - 1].position[1];
	
	Particles[0].position[0] = -config.latticesize/2; //Frontera izquierda
	Particles[0].position[1] = dis_hole(gen);
	cell_old = Particles[0].Getcell(config);
	old_count = Cells[cell_old];
	
	config.holeposition = 0;
	
	Particles[0].Move_hole(-1, 0, 0, config, Cells, Particles);
	lost_count += 1;
	
	REQUIRE (Particles[0].position[0] == future_x);
	REQUIRE (Particles[0].position[1] == future_y);
	REQUIRE (Particles.size() == initial_size - lost_count);
	REQUIRE (Cells[cell_old] == old_count - 1);
	
	future_x = Particles[Particles.size() - 1].position[0]; //reset future values
	future_y = Particles[Particles.size() - 1].position[1];
	
	Particles[0].position[1] = -config.latticesize/2; //Frontera abajo
	Particles[0].position[0] = dis_hole(gen);
	cell_old = Particles[0].Getcell(config);
	old_count = Cells[cell_old];
	
	config.holeposition = 3;
	
	Particles[0].Move_hole(-1, 1, 0, config, Cells, Particles);
	lost_count += 1;
	
	REQUIRE (Particles[0].position[0] == future_x);
	REQUIRE (Particles[0].position[1] == future_y);
	REQUIRE (Particles.size() == initial_size - lost_count);
	REQUIRE (Cells[cell_old] == old_count - 1);
	
      }
      
    }
    
    SECTION ("Cells conditions"){

        int sum = 0;     //La suma de todas las casillas debe dar el número de particulas

        for (int i = 0; i < config.gridsize*config.gridsize; i++){

            sum += Cells[i];

        }

        REQUIRE (sum == config.nmolecules);

        Particles[0].position[0] = -config.latticesize/2;    //Esquina inferior izquierda del grid
        Particles[0].position[1] = -config.latticesize/2;

        m = Particles[0].Getcell(config);

        REQUIRE (m == 0);

        Particles[0].position[0] = config.latticesize/2 - 1;    //Esquina superior derecha del grid
        Particles[0].position[1] = config.latticesize/2 - 1;

        m = Particles[0].Getcell(config);

        REQUIRE (m == config.gridsize*config.gridsize - 1);

        int random_particle = 0, step = 0, direction = 0;

        for (int t = 0; t <= 50; t++){

            random_particle = dis_particle(gen);     
            step = dis_move(gen)*2 - 1;  
            direction = dis_move(gen);

            time_step(config, random_particle, step, direction, Cells, Particles);

        }

        sum = 0;

        for (int i = 0; i < config.gridsize*config.gridsize; i++){

            sum += Cells[i];

        }

        REQUIRE (sum == config.nmolecules);
        
    }

    SECTION ("Entropy conditions"){

        double Entropy = 0;

        for (int i = 0; i < config.gridsize*config.gridsize; i++){

            Cells[i] = 0;

        }

        for (int i = 0; i < config.nmolecules; i++){

            Particles[i].position[0] = 0;
            Particles[i].position[1] = 0;
            m = Particles[i].Getcell(config);
            Cells[m] += 1;

        }

        Entropy = entropy(config, Cells);

        REQUIRE (Entropy == 0);

    }
    
}
