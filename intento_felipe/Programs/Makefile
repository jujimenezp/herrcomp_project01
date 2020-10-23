CXX = g++
CXXFLAGS=-std=c++17 -O3 -g
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
DEPENDENCIES = ../Functions/Objects/time_steps.o ../Functions/Objects/entropy_step.o ../Functions/Objects/init_entropy.o ../Functions/Objects/init_cells.o ../Functions/Objects/init_particles.o ../Functions/Objects/distribution.o ../Functions/Objects/get_data.o ../Functions/Objects/particle.o

all: coffee_random.x

graphs: coffee_random.x ../Data/init_data.txt
	./$< > ../Data/entropy_data.txt
	gnuplot ../Scripts/distribution_script.gp
	xpdf ../Data/distribution_start.pdf
	xpdf ../Data/distribution_end.pdf
	gnuplot ../Scripts/entropy_script.gp
	xpdf ../Data/entropy_data.pdf
	rm ../Data/entropy_data.txt ../Data/distribution_start.txt ../Data/distribution_end.txt

,,/Functions/Objects/%.o: ../Functions/%.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c $< -o $@

Objects/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c $< -o $@

coffee_random.x: Objects/coffee_random.o $(DEPENDENCIES) 
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

clean:
	rm rm -f *.x *.o a.out



