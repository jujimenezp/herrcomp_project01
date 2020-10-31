CXX = g++
CXXFLAGS = -std=c++17 -O3 -g
SANITFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined
MEMCHECKFLAGS = --tool=memcheck --track-origins=yes --leak-check=full
DEPENDENCIES_SANITIZERS = Objects/Sanitizers/CONFIG.o Objects/Sanitizers/class_particle.o Objects/Sanitizers/start.o Objects/Sanitizers/time_step.o Objects/Sanitizers/entropy.o Objects/Sanitizers/print_particles.o Objects/Sanitizers/dropsize.o Objects/Sanitizers/stability.o
DEPENDENCIES_NORMAL = Objects/Normal/CONFIG.o Objects/Normal/class_particle.o Objects/Normal/start.o Objects/Normal/time_step.o Objects/Normal/entropy.o Objects/Normal/print_particles.o Objects/Normal/dropsize.o Objects/Normal/stability.o
DEPENDENCIES_GPROF = Objects/Gprof/CONFIG.o Objects/Gprof/class_particle.o Objects/Gprof/start.o Objects/Gprof/time_step.o Objects/Gprof/entropy.o Objects/Gprof/print_particles.o Objects/Gprof/dropsize.o Objects/Gprof/stability.o

all: main.x main_stability.x main_dropsize.x

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

graphs: main_stability.x Data/init_data.txt
	bash Scripts/plot_stability.sh
	gnuplot Scripts/plot_stability.gp
	xpdf Data/stability.pdf &
#	./$<
#	./main_dropsize.x
#	gnuplot Scripts/plot_particles.gp
#	gnuplot Scripts/plot_entropy.gp
#	gnuplot Scripts/plot_dropsize.gp
#	xpdf Data/particles_start.pdf &
#	xpdf Data/particles_end.pdf &
#	xpdf Data/entropy.pdf &
#	xpdf Data/dropsize.pdf &

stability_test: main.x stability_test.x Data/init_data.txt
	./$<
	./stability_test.x
	gnuplot Scripts/plot_entropy.gp
	gnuplot Scripts/plot_stability_test.gp
	xpdf Data/entropy.pdf &
	xpdf Data/stability_test.pdf &

animation: animation.x
	rm -f Data/Animation/*.csv
	./$<

main.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/main.o
	$(CXX) $(CXXFLAGS) $(LIBRARIES) $(SANITFLAGS) $^ -lgsl -lgslcblas -lm -o $@

main_stability.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/main_stability.o
	$(CXX) $(CXXFLAGS) $(LIBRARIES) $(SANITFLAGS) $^ -lgsl -lgslcblas -lm -o $@

main_dropsize.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/main_dropsize.o
	$(CXX) $(CXXFLAGS) $(LIBRARIES) $(SANITFLAGS) $^ -lgsl -lgslcblas -lm -o $@

stability_test.x: $(DEPENDENCIES_SANITIZERS) Objects/Sanitizers/stability.o
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
