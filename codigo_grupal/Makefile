CXX = g++
CXXFLAGS = -std=c++17 -O3 -g
SANITFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined
MEMCHECKFLAGS = --tool=memcheck --track-origins=yes --leak-check=full
DEPENDENCIES_SANITIZERS = Objects/Sanitizers/CONFIG.o Objects/Sanitizers/class_particle.o Objects/Sanitizers/start.o Objects/Sanitizers/entropy.o Objects/Sanitizers/print_particles.o Objects/Sanitizers/dropsize.o 
DEPENDENCIES_NORMAL = Objects/Normal/CONFIG.o Objects/Normal/class_particle.o Objects/Normal/start.o Objects/Normal/entropy.o Objects/Normal/print_particles.o Objects/Normal/dropsize.o
DEPENDENCIES_GPROF = Objects/Gprof/CONFIG.o Objects/Gprof/class_particle.o Objects/Gprof/start.o Objects/Gprof/entropy.o Objects/Gprof/print_particles.o Objects/Gprof/dropsize.o 

all: main.x main_stability.x main_dropsize.x main_hole.x

test: test.x
	./$<

gprof: gprof.x
	./$<
	gprof ./$< > Data/gprof-report.txt

cachegrind: valgrind.x
	valgrind --tool=cachegrind ./$<
	cg_annotate $$(ls -t cachegrind.out.* | head -n 1) > Data/cachegrind-report.txt

memcheck: valgrind.x
	valgrind $(MEMCHECKFLAGS) ./$<

graphs: main.x main_stability.x main_dropsize.x Data/init_data.txt
	./$<
	./main_dropsize.x
	gnuplot Scripts/plot_particles.gp
	gnuplot Scripts/plot_entropy.gp
	bash Scripts/plot_stability.sh
	gnuplot Scripts/plot_stability.gp
	gnuplot Scripts/plot_dropsize.gp
	xpdf Data/particles_start.pdf &
	xpdf Data/particles_end.pdf &
	xpdf Data/entropy.pdf &
	xpdf Data/dropsize.pdf &
	xpdf Data/stability.pdf &

main.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/main.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

main_stability.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/stability.o Objects/Sanitizers/main_stability.o
	$(CXX) $(CXXFLAGS) $(LIBRARIES) $(SANITFLAGS) $^ -lgsl -lgslcblas -lm -o $@

main_dropsize.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/stability.o Objects/Sanitizers/main_dropsize.o
	$(CXX) $(CXXFLAGS) $(LIBRARIES) $(SANITFLAGS) $^ -lgsl -lgslcblas -lm -o $@

main_hole.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/main_hole.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

test.x: $(DEPENDENCIES_NORMAL) Objects/Normal/test.o
	$(CXX) $(CXXFLAGS) $^ -o $@

gprof.x: $(DEPENDENCIES_GPROF) Objects/Gprof/main.o
	$(CXX) $(CXXFLAGS) -pg $^ -o $@

valgrind.x: $(DEPENDENCIES_NORMAL) Objects/Normal/main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

Objects/Sanitizers/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c  $< -o $@

Objects/Normal/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) -c  $< -o $@

Objects/Gprof/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) -pg -c  $< -o $@

clean:
	rm -f Data/gprof-report.txt Data/cachegrind-report.txt gmon.out cachegrind.out.* *.x Data/data*.txt

oclean:
	rm -f Objects/Sanitizers/*.o Objects/Normal/*.o Objects/Gprof/*.o
