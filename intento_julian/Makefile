CXX=g++
CXXFLAGS=-std=c++17 -O3 -g
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
VALGRINDFLAGS= --tool=memcheck --track-origins=yes --leak-check=full
DEPENDENCIES = programs/intento1.o programs/getdatos.o programs/particles.o programs/implementation.o programs/printdata.o


all: programs/intento1.x

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c $< -o $@

programs/intento1.x: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

valgrind: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $^ -o intento1.x
	valgrind $(VALGRINDFLAGS) programs/intento1.x

graphs: programs/intento1.x data/init_data.txt
	./programs/intento1.x
	gnuplot scripts/plot_particles.gp
	gnuplot scripts/plot_entropy.gp
	make clean

clean:
	rm -f programs/*.o
