CXX=g++
CXXFLAGS=-std=c++17
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
VALGRINDFLAGS= --tool=memcheck --track-origins=yes --leak-check=full
DEPENDENCIES = intento1.o getdatos.o particles.o implementation.o printdata.o


all: intento1.x

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -g -c $<

intento1.x: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $^ -o $@

sanitizers: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o intento1.x

valgrind: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -g $^ -o intento1.x
	valgrind $(VALGRINDFLAGS) ./intento1.x

graphs: intento1.x init_data.txt
	./intento1.x
	gnuplot plot_particles.gp
	gnuplot plot_entropy.gp
	make clean

clean:
	rm -f *.x *.o a.out
