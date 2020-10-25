CXX=g++
CXXFLAGS= -std=c++17 -O3 -g
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
MEMCHECKFLAGS= --tool=memcheck --track-origins=yes --leak-check=full
DEPENDENCIES =  Objects/CONFIG.o Objects/class_particle.o Objects/start.o Objects/time_step.o Objects/entropy.o Objects/print_data.o

all: main.x

Objects/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c  $< -o $@

main.x: $(DEPENDENCIES) Objects/main.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

graphs: main.x Data/init_data.txt
	time ./main.x
	gnuplot Scripts/plot_particles.gp
	xpdf Data/particles_start.pdf &
	xpdf Data/particles_end.pdf &

clean:
	rm -f Data/data_* Data/*.pdf *.x

oclean:
	rm -f Objects/*.o
