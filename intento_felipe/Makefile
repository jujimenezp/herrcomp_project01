CXX=g++
CXXFLAGS= -std=c++17 -O3 -g
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
MEMCHECKFLAGS= --tool=memcheck --track-origins=yes --leak-check=full
DEPENDENCIES =  Objects/CONFIG.o Objects/class_particle.o Objects/start.o Objects/time_step.o Objects/entropy.o Objects/print_data.o
DEPENDENCIES_V =  Objects_V/CONFIG.o Objects_V/class_particle.o Objects_V/start.o Objects_V/time_step.o Objects_V/entropy.o Objects_V/print_data.o

all: main.x

memcheck: main_V.x
	valgrind $(MEMCHECKFLAGS) ./$<

Objects/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c  $< -o $@

Objects_V/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) -c  $< -o $@

main.x: $(DEPENDENCIES) Objects/main.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

main_V.x: $(DEPENDENCIES_V) Objects_V/main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

graphs: main.x Data/init_data.txt
	time ./main.x
	gnuplot Scripts/plot_particles.gp
	xpdf Data/particles_start.pdf &
	xpdf Data/particles_end.pdf &

clean:
	rm -f Data/data_* Data/*.pdf *.x

oclean:
	rm -f Objects/*.o Objects_V/*.o Objects_G/*.o
