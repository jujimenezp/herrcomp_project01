CXX=g++
CXXFLAGS=-std=c++17 -O3 -g
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
MEMCHECKFLAGS= --tool=memcheck --track-origins=yes --leak-check=full
DEPENDENCIES = programs/intento1.o programs/getdatos.o programs/particles.o programs/implementation.o programs/printdata.o


all: programs/intento1.x

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c $< -o $@

programs/intento1.x: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

memcheck: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $^ -o programs/intento1.x
	valgrind $(MEMCHECKFLAGS) programs/intento1.x
	make clean

gprof: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -pg $^ -o programs/intento1.x
	./programs/intento1.x
	gprof programs/intento1.x gmon.out > data/gprof-report.txt
	make clean

graphs: programs/intento1.x data/init_data.txt
	./programs/intento1.x
	gnuplot scripts/plot_particles.gp
	gnuplot scripts/plot_entropy.gp
	make clean

times: programs/intento1.x data/init_data.txt
	bash time_compute/compute_time_N.sh
	bash time_compute/compute_time_ite.sh
	gnuplot scripts/plot_times.gp

clean:
	rm -f gmon.out programs/*.o
