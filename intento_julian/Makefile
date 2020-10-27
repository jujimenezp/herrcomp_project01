CXX=g++
CXXFLAGS= -std=c++17 -O3 -g
SANITFLAGS= -fsanitize=address -fsanitize=leak -fsanitize=undefined
MEMCHECKFLAGS= --tool=memcheck --track-origins=yes --leak-check=full
DEPENDENCIES =  programs/intento1.cpp programs/getdatos.cpp programs/particles.cpp programs/implementation.cpp programs/printdata.cpp



all: programs/intento1.x

programs/intento1.x: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

memcheck:
	$(CXX) $(CXXFLAGS) $(DEPENDENCIES) -o programs/intento1.x
	valgrind $(MEMCHECKFLAGS) programs/intento1.x > valgrind.txt
	make clean

gprof: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -pg $^ -o programs/intento1.x
	./programs/intento1.x
	gprof programs/intento1.x gmon.out > data/gprof-report.txt

graphs: programs/intento1.x data/init_data.txt
	./programs/intento1.x
	gnuplot scripts/plot_particles.gp
	gnuplot scripts/plot_entropy.gp
	xpdf data/entropy.pdf &
	xpdf data/particles_start.pdf &
	xpdf data/particles_end.pdf &

times: programs/intento1.x data/init_data.txt
	bash time_compute/compute_time_N.sh
	bash time_compute/compute_time_ite.sh
	gnuplot scripts/plot_times.gp
	xpdf data/time_iterations.pdf &
	xpdf data/time_particles.pdf &

clean:
	rm -f gmon.out *.o programs/*.o data/data_* rm programs/intento1.x
