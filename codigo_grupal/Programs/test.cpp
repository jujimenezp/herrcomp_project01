#define CATCH_CONFIG_MAIN 
#include "catch2/catch.hpp"

#include "header.h"

TEST_CASE ("All tests", "[Main]"){
    
  CONFIG config;
  config.read("Data/init_data.txt"); //Se leen los datos iniciales

  //Distribuciones aleatias
  std::mt19937 gen(config.seed);
  std::uniform_int_distribution<int> dis_move(0, 1); //Movimiento de particula
  std::uniform_int_distribution<int> dis_particle(0,config.nmolecules-1); //Selección de particula
  std::uniform_int_distribution<int> dis_location(-config.latticesize/2, config.latticesize/2 - 1); //Ubicación de particula
  std::uniform_int_distribution<int> dis_hole(-config.holesize/2, config.holesize/2); //Ubicación del 
    
  Vec_p Particles(config.nmolecules);
  Vec_i Cells(config.gridsize*config.gridsize,0);
  Vec_i Cells_null(config.gridsize*config.gridsize,0);
    
  int x = 0, y = 0, m = 0;

  //Se inicializan las particulas aleatoreamente
  for (int i = 0; i < config.nmolecules; i++){

    x = dis_location(gen);
    y = dis_location(gen);

    Particles[i].position[0] = x;
    Particles[i].position[1] = y;
    m = Particles[i].Getcell(config);
    Cells[m] += 1;

  }

  SECTION ("Border conditions without holes"){

    /*
    Para cada frontera se ubica una particula antes de ella, se mueve hacia ella,
    y se debe cumplir que antes y despues del movimiento el sistema no cambie
    */
    
    int x_old = 0, y_old = 0, cell_old = 0,
      x_new = 0, y_new = 0, cell_new = 0;

    Particles[0].position[0] = config.latticesize/2 - 1; //Frontera derecha
    
    x_old = Particles[0].position[0];
    y_old = Particles[0].position[1];
    cell_old = Particles[0].Getcell(config);

    Particles[0].Move(1, 0, config, Cells);

    x_new = Particles[0].position[0];
    y_new = Particles[0].position[1];
    cell_new = Particles[0].Getcell(config);
    
    REQUIRE (x_old == x_new);
    REQUIRE (y_old == y_new);
    REQUIRE (cell_old == cell_new);

    
    Particles[0].position[1] = config.latticesize/2 - 1; //Frontera arriba
    
    x_old = Particles[0].position[0];
    y_old = Particles[0].position[1];
    cell_old = Particles[0].Getcell(config);

    Particles[0].Move(1, 1, config, Cells);

    x_new = Particles[0].position[0];
    y_new = Particles[0].position[1];
    cell_new = Particles[0].Getcell(config);
    
    REQUIRE (x_old == x_new);
    REQUIRE (y_old == y_new);
    REQUIRE (cell_old == cell_new);

    
    Particles[0].position[0] = -config.latticesize/2; //Frontera izquierda
    
    x_old = Particles[0].position[0];
    y_old = Particles[0].position[1];
    cell_old = Particles[0].Getcell(config);

    Particles[0].Move(-1, 0, config, Cells);

    x_new = Particles[0].position[0];
    y_new = Particles[0].position[1];
    cell_new = Particles[0].Getcell(config);
    
    REQUIRE (x_old == x_new);
    REQUIRE (y_old == y_new);
    REQUIRE (cell_old == cell_new);

    
    Particles[0].position[1] = -config.latticesize/2; //Frontera abajo
    
    x_old = Particles[0].position[0];
    y_old = Particles[0].position[1];
    cell_old = Particles[0].Getcell(config);

    Particles[0].Move(-1, 1, config, Cells);

    x_new = Particles[0].position[0];
    y_new = Particles[0].position[1];
    cell_new = Particles[0].Getcell(config);
    
    REQUIRE (x_old == x_new);
    REQUIRE (y_old == y_new);
    REQUIRE (cell_old == cell_new);

  }

  SECTION ("Border conditions with holes"){
    /*Particles debe reducirse si la particula i escapa,
      el numero de particulas en la celda de i debe disminuir en 1
      y los nuevos valores de i deben ser los de la 
      ultima entrada de Particles*/

    if (config.nmolecules < 4){
      Particles.resize(5);
      Particles[4].position[0] = 0;
      Particles[4].position[1] = 0;
    }
      
    int old_cell = 0, old_cell_count = 0, lost_count = 0;
    int initial_size = Particles.size();
    int future_x = Particles[Particles.size() - 1].position[0];
    int future_y = Particles[Particles.size() - 1].position[1];

    config.holeposition = 1; //Frontera derecha
    Particles[0].position[0] = config.latticesize/2 - 1;
    Particles[0].position[1] = dis_hole(gen);
    old_cell = Particles[0].Getcell(config);
    old_cell_count = Cells[old_cell];
      
    Particles[0].Move_hole(1, 0, 0, config, Cells, Particles);
    lost_count += 1;
      
    REQUIRE (Particles[0].position[0] == future_x);
    REQUIRE (Particles[0].position[1] == future_y);
    REQUIRE (Particles.size() == initial_size - lost_count);
    REQUIRE (Cells[old_cell] == old_cell_count - 1);
	
    future_x = Particles[Particles.size() - 1].position[0]; //reset future values
    future_y = Particles[Particles.size() - 1].position[1];
      
    config.holeposition = 2; //Frontera arriba
    Particles[0].position[1] = config.latticesize/2 - 1;
    Particles[0].position[0] = dis_hole(gen);
    old_cell = Particles[0].Getcell(config);
    old_cell_count = Cells[old_cell];
	
    Particles[0].Move_hole(1, 1, 0, config, Cells, Particles);
    lost_count += 1;
	
    REQUIRE (Particles[0].position[0] == future_x);
    REQUIRE (Particles[0].position[1] == future_y);
    REQUIRE (Particles.size() == initial_size - lost_count);
    REQUIRE (Cells[old_cell] == old_cell_count - 1);
	
    future_x = Particles[Particles.size() - 1].position[0]; //reset future values
    future_y = Particles[Particles.size() - 1].position[1];
      
    config.holeposition = -1; //Frontera izquierda
    Particles[0].position[0] = -config.latticesize/2;
    Particles[0].position[1] = dis_hole(gen);
    old_cell = Particles[0].Getcell(config);
    old_cell_count = Cells[old_cell];
	
    Particles[0].Move_hole(-1, 0, 0, config, Cells, Particles);
    lost_count += 1;
	
    REQUIRE (Particles[0].position[0] == future_x);
    REQUIRE (Particles[0].position[1] == future_y);
    REQUIRE (Particles.size() == initial_size - lost_count);
    REQUIRE (Cells[old_cell] == old_cell_count - 1);
	
    future_x = Particles[Particles.size() - 1].position[0]; //reset future values
    future_y = Particles[Particles.size() - 1].position[1];
      
    config.holeposition = 0; //Frontera abajo
    Particles[0].position[1] = -config.latticesize/2;
    Particles[0].position[0] = dis_hole(gen);
    old_cell = Particles[0].Getcell(config);
    old_cell_count = Cells[old_cell];
	
    Particles[0].Move_hole(-1, 1, 0, config, Cells, Particles);
    lost_count += 1;
	
    REQUIRE (Particles[0].position[0] == future_x);
    REQUIRE (Particles[0].position[1] == future_y);
    REQUIRE (Particles.size() == initial_size - lost_count);
    REQUIRE (Cells[old_cell] == old_cell_count - 1);

  }

  SECTION ("Cells conditions"){

    /*
    La suma de todas las casillas debe dar el número de particulas
    */
    
    int sum = 0;     

    for (int i = 0; i < config.gridsize*config.gridsize; i++){

      sum += Cells[i];

    }

    REQUIRE (sum == config.nmolecules);

    /*
    Luego de una caminata aleatorea, la suma de las celdas debe seguir siendo el
    número de particulas
    */
    int random_particle = 0, step = 0, direction = 0;

    for (int t = 0; t <= 50; t++){

      random_particle = dis_particle(gen);     
      step = dis_move(gen)*2 - 1;  
      direction = dis_move(gen);

      Particles[random_particle].Move(step, direction, config, Cells);
            
    }

    sum = 0;

    for (int i = 0; i < config.gridsize*config.gridsize; i++){

      sum += Cells[i];

    }

    REQUIRE (sum == config.nmolecules);

    /*
    Por como se definen las celdas, la primera celda, denominada 0, debe estar en la
    esquina inferior izquierda, mientras que la ultima, denominada n - 1 con n el numero de celdas,
    debe estar en la esquina superior derecha.
    */
    
    Particles[0].position[0] = -config.latticesize/2;    //Esquina inferior izquierda del grid
    Particles[0].position[1] = -config.latticesize/2;

    m = Particles[0].Getcell(config);

    REQUIRE (m == 0);

    Particles[0].position[0] = config.latticesize/2 - 1;    //Esquina superior derecha del grid
    Particles[0].position[1] = config.latticesize/2 - 1;

    m = Particles[0].Getcell(config);

    REQUIRE (m == config.gridsize*config.gridsize - 1);
        
  }

  SECTION ("Entropy conditions"){

    /*
      Si se ubican todas las partículas en un solo sitio, la entropia total es cero.
    */
    
    double Entropy = 0;

    Cells = Cells_null;

    for (int i = 0; i < config.nmolecules; i++){

      Particles[i].position[0] = 0;
      Particles[i].position[1] = 0;
      m = Particles[i].Getcell(config);
      Cells[m] += 1;

    }

    Entropy = entropy(config, Cells);

    REQUIRE (Entropy == 0);

  }

  SECTION ("Stability conditions"){

    /*
      En el tiempo estabilización de la entropia, esta debe tender a log(n), donde n es el número de celdas,
      mientras que el tamaño de la gota debe tender a L/sqrt(6), donde L es el tamaño de la taza.
    */

    double Entropy = 0, Dropsize = 0,
      eps_entropy = 0.08, eps_dropsize = 0.18;

    Cells = Cells_null;

    start (config, Cells, Particles);

    const int partition_size = config.latticesize*config.latticesize/10;

    stability (config, partition_size, Particles, Cells);

    Entropy = entropy (config, Cells);
    Dropsize = dropsize (config, Particles);

    double Deviation_entropy = std::abs(std::log(config.gridsize*config.gridsize) - Entropy)/std::log(config.gridsize*config.gridsize);
    double Deviation_dropsize = std::abs(config.latticesize/std::sqrt(6) - Dropsize)/(config.latticesize/std::sqrt(6));

    REQUIRE (Deviation_entropy < eps_entropy);
    REQUIRE (Deviation_dropsize < eps_dropsize);


  }
  
    
}
