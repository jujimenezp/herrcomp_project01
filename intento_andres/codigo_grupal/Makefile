CXX = g++
CXXFLAGS = -std=c++17 -O3 -g
SANITFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined
MEMCHECKFLAGS = --tool=memcheck --track-origins=yes --leak-check=full
DEPENDENCIES_SANITIZERS = Objects/Sanitizers/CONFIG.o Objects/Sanitizers/class_particle.o Objects/Sanitizers/start.o Objects/Sanitizers/entropy.o Objects/Sanitizers/print_particles.o Objects/Sanitizers/dropsize.o 
DEPENDENCIES_NORMAL = Objects/Normal/CONFIG.o Objects/Normal/class_particle.o Objects/Normal/start.o Objects/Normal/entropy.o Objects/Normal/print_particles.o Objects/Normal/dropsize.o
DEPENDENCIES_GPROF = Objects/Gprof/CONFIG.o Objects/Gprof/class_particle.o Objects/Gprof/start.o Objects/Gprof/entropy.o Objects/Gprof/print_particles.o Objects/Gprof/dropsize.o
DEPENDENCIES_NORMAL_WRONG = Objects/Normal/CONFIG.o Objects/Normal/class_particle_wrong.o Objects/Normal/start.o Objects/Normal/entropy.o Objects/Normal/print_particles.o Objects/Normal/dropsize.o
DEPENDENCIES_GPROF_WRONG = Objects/Gprof/CONFIG.o Objects/Gprof/class_particle_wrong.o Objects/Gprof/start.o Objects/Gprof/entropy.o Objects/Gprof/print_particles.o Objects/Gprof/dropsize.o 

all: main_hole.x main_wrong.x

test: test.x
	./$<

gprof: gprof_hole.x gprof_wrong.x
	./$<
	gprof ./$< > Data/gprof_hole-report.txt
	rm gmon.out
	./gprof_wrong.x
	gprof ./gprof_wrong.x > Data/gprof_wrong-report.txt
	rm gmon.out

cachegrind: valgrind_hole.x valgrind_wrong.x
	valgrind --tool=cachegrind ./$<
	cg_annotate $$(ls -t cachegrind.out.* | head -n 1) > Data/cachegrind_hole-report.txt
	rm -f cachegrind.out.*
	valgrind --tool=cachegrind ./valgrind_wrong.x
	cg_annotate $$(ls -t cachegrind.out.* | head -n 1) > Data/cachegrind_wrong-report.txt
	rm -f cachegrind.out.*

memcheck: valgrind_hole.x valgrind_wrong.x
	valgrind $(MEMCHECKFLAGS) ./$<
	valgrind $(MEMCHECKFLAGS) ./valgrind_wrong.x

graphs: main_hole.x main_wrong.x Data/init_data.txt
	./$<
	gnuplot Scripts/plot_hole.gp
	xpdf Data/hole.pdf &
	xpdf Data/hole_log.pdf &
	./main_wrong.x
	gnuplot Scripts/plot_hole_wrong.gp
	xpdf Data/hole_wrong.pdf &
	xpdf Data/hole_wrong_log.pdf &

aux: main_dropsize.x Data/init_data.txt
	gnuplot Scripts/plot_dropsize.gp
	xpdf Data/dropsize.pdf &
	xpdf Data/dropsize_log.pdf &

main.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/main.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

main_stability.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/stability.o Objects/Sanitizers/main_stability.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -lgsl -lgslcblas -lm -o $@

main_dropsize.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/stability.o Objects/Sanitizers/main_dropsize.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -lgsl -lgslcblas -lm -o $@

main_hole.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/main_hole.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

main_wrong.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/main_wrong.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

test.x: $(DEPENDENCIES_NORMAL) Objects/Normal/test.o
	$(CXX) $(CXXFLAGS) $^ -o $@

gprof.x: $(DEPENDENCIES_GPROF) Objects/Gprof/main.o
	$(CXX) $(CXXFLAGS) -pg $^ -o $@

gprof_stability.x: $(DEPENDENCIES_GPROF) Objects/Gprof/stability.o Objects/Gprof/main_stability.o
	$(CXX) $(CXXFLAGS) -pg $^ -lgsl -lgslcblas -lm -o $@

gprof_dropsize.x: $(DEPENDENCIES_GPROF) Objects/Gprof/stability.o Objects/Gprof/main_dropsize.o
	$(CXX) $(CXXFLAGS) -pg $^ -lgsl -lgslcblas -lm -o $@

gprof_hole.x: $(DEPENDENCIES_GPROF) Objects/Gprof/main_hole.o
	$(CXX) $(CXXFLAGS) -pg $^ -o $@

gprof_wrong.x: $(DEPENDENCIES_GPROF_WRONG) Objects/Gprof/main_hole.o
	$(CXX) $(CXXFLAGS) -pg $^ -o $@

valgrind.x: $(DEPENDENCIES_NORMAL) Objects/Normal/main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

valgrind_stability.x: $(DEPENDENCIES_NORMAL) Objects/Normal/stability.o Objects/Normal/main_stability.o
	$(CXX) $(CXXFLAGS) $^ -lgsl -lgslcblas -lm -o $@

valgrind_dropsize.x: $(DEPENDENCIES_NORMAL) Objects/Normal/stability.o Objects/Normal/main_dropsize.o
	$(CXX) $(CXXFLAGS) $^ -lgsl -lgslcblas -lm -o $@

valgrind_hole.x: $(DEPENDENCIES_NORMAL) Objects/Normal/main_hole.o
	$(CXX) $(CXXFLAGS) $^ -o $@

valgrind_wrong.x: $(DEPENDENCIES_NORMAL_WRONG) Objects/Normal/main_hole.o
	$(CXX) $(CXXFLAGS) $^ -o $@

Objects/Sanitizers/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c  $< -o $@

Objects/Normal/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) -c  $< -o $@

Objects/Gprof/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) -pg -c  $< -o $@

clean:
	rm -f Data/gprof*.txt Data/cachegrind*.txt *.x Data/data*.txt *.log

oclean:
	rm -f Objects/Sanitizers/*.o Objects/Normal/*.o Objects/Gprof/*.o
