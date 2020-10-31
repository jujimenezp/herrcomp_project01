CXX = g++
CXXFLAGS = -std=c++17 -O3 -g
SANITFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined
MEMCHECKFLAGS = --tool=memcheck --track-origins=yes --leak-check=full
DEPENDENCIES_SANITIZERS = Objects/Sanitizers/CONFIG.o Objects/Sanitizers/class_particle.o Objects/Sanitizers/start.o Objects/Sanitizers/time_step.o Objects/Sanitizers/entropy.o Objects/Sanitizers/print_particles.o
DEPENDENCIES_NORMAL = Objects/Normal/CONFIG.o Objects/Normal/class_particle.o Objects/Normal/start.o Objects/Normal/time_step.o Objects/Normal/entropy.o Objects/Normal/print_particles.o
DEPENDENCIES_GPROF = Objects/Gprof/CONFIG.o Objects/Gprof/class_particle.o Objects/Gprof/start.o Objects/Gprof/time_step.o Objects/Gprof/entropy.o Objects/Gprof/print_particles.o

all: main.x main_stability.x

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

graphs: main.x Data/init_data.txt
	./$<
	gnuplot Scripts/plot_entropy.gp
	gnuplot Scripts/plot_particles.gp
	xpdf Data/entropy.pdf &
	xpdf Data/particles_start.pdf &
	xpdf Data/particles_end.pdf &

stability: main.x stability.x Data/init_data.txt
	./$<
	./stability.x
	gnuplot Scripts/plot_entropy.gp
	gnuplot Scripts/plot_stability.gp
	xpdf Data/entropy.pdf &
	xpdf Data/stability.pdf &

animation: animation.x
	rm -f Data/Animation/*.csv
	./$<

main.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/main.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

main_stability.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/main_stability.o
	$(CXX) $(CXXFLAGS) $(LIBRARIES) $(SANITFLAGS) $^ -lgsl -lgslcblas -lm -o $@

stability.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/stability.o
	$(CXX) $(CXXFLAGS) $(LIBRARIES) $(SANITFLAGS) $^ -lgsl -lgslcblas -lm -o $@

test.x: $(DEPENDENCIES_NORMAL) Objects/Normal/test.o
	$(CXX) $(CXXFLAGS) $^ -o $@

gprof.x: $(DEPENDENCIES_GPROF) Objects/Gprof/main.o
	$(CXX) $(CXXFLAGS) -pg $^ -o $@

valgrind.x: $(DEPENDENCIES_NORMAL) Objects/Normal/main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

animation.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/animation.o
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) $^ -o $@

Objects/Sanitizers/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) $(SANITFLAGS) -c  $< -o $@

Objects/Normal/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) -c  $< -o $@

Objects/Gprof/%.o: Programs/%.cpp
	$(CXX) $(CXXFLAGS) -pg -c  $< -o $@

clean:
	rm -f Data/data_* Data/gprof-report.txt Data/cachegrind-report.txt Data/Animation/*.csv gmon.out cachegrind.out.* *.x 

oclean:
	rm -f Objects/Sanitizers/*.o Objects/Normal/*.o Objects/Gprof/*.o
