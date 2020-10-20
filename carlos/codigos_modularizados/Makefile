CXX=g++
CXXFLAGS=-std=c++17 -O2
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
VALGRINDFLAGS= --tool=memcheck --track-origins=yes --leak-check=full
DEPENDENCIES = main.o getdatos.o class_particle.o entropy.o start.o printdata.o


all: main.x

%.o: %.cpp init_data.txt
	$(CXX) $(CXXFLAGS) -g -c $<

main.x: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $^ -o $@

sanitizers: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o main.x

valgrind: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -g $^ -o main.x
	valgrind $(VALGRINDFLAGS) ./main.x

plot: data_entropy.txt data_particles_end.txt data_particles_start.txt
	gnuplot plot.gp

clean:
	rm -f *.x *.o a.out
